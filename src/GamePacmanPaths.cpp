//
// GamePacmanPaths.cpp for arcade in /home/wilmot_g/Rendu/cpp_arcade2/leHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Tue Mar 15 16:14:20 2016 guillaume wilmot
// Last update Sun Apr  3 19:03:30 2016 guillaume wilmot
//

#include "GamePacman.hpp"

void			GamePacman::setListOnKe(t_paths **paths, int id) const
{
  t_paths		*tmp;

  tmp = (*paths)->next;
  while (tmp->id != id && tmp != *paths)
    tmp = tmp->next;
  if (tmp->id == id)
    *paths = tmp;
}

float			GamePacman::extractPath(int key, std::vector<int> *ke, t_paths *end, t_paths *start) const
{
  float			len;

  delete ke;
  if (key == 0)
    return (-1);
  for (len = 1; end->id != start->id; len++)
    setListOnKe(&end, end->visited_by);
  return (len);
}

void			GamePacman::reinitPaths(t_paths *paths) const
{
  t_paths		*tmp;

  tmp = paths;
  while (tmp->next != paths)
    {
      tmp->visited = 0;
      tmp = tmp->next;
    }
  tmp->visited = 0;
}

float			GamePacman::pathfinding(t_paths *path, int y, int x) const
{
  t_paths		*start;
  int			end;
  int			i;
  std::vector<int>	*ke;

  end = 0;
  start = path;
  ke = new std::vector<int>;
  ke->push_back(path->id);
  reinitPaths(path);
  path->visited = 1;
  path->visited_by = path->id;
  while (ke->size() > 0 && !end)
    {
      setListOnKe(&path, ke->at(0));
      ke->erase(ke->begin());
      for (i = 0; i < 4 && !end; i++)
	if (path->neighboors[i])
	  if (!(path->neighboors[i])->visited)
	    {
	      ke->push_back((path->neighboors[i])->id);
	      (path->neighboors[i])->visited = 1;
	      (path->neighboors[i])->visited_by = path->id;
	      if ((path->neighboors[i])->pos[0] == y && (path->neighboors[i])->pos[1] == x)
		end = 1;
	    }
    }
  return (extractPath(end, ke, path, start));
}

int			GamePacman::getBestWay(t_paths *path, int y, int x) const
{
  float			bestLen;
  float			len;
  int			bestWay;
  int			i;
  int			k;

  bestLen = 0;
  bestWay = 9;
  k = 0;
  for (i = 0; i < 4; i++)
    if (path->neighboors[i])
      {
	if ((path->neighboors[i])->pos[0] == y && (path->neighboors[i])->pos[1] == x)
	  {
	    bestLen = 1;
	    bestWay = i;
	    i = 4;
	  }
	else if (k == 0)
	  {
	    bestLen = pathfinding(path->neighboors[i], y, x);
	    if (bestLen != -1)
	      {
		k++;
		bestWay = i;
	      }
	  }
	else if ((len = pathfinding(path->neighboors[i], y , x)) < bestLen && len != -1)
	  {
	    bestLen = len;
	    bestWay = i;
	  }
      }
  return (bestWay);
}

int			GamePacman::findBestWay(int y, int x, int y2, int x2) const
{
  t_paths		*tmp;
  int			end;

  if (x == _pos[0]->getX() && y == _pos[0]->getY())
    return (4);
  tmp = _paths->next;
  end = 0;
  while (tmp != _paths && !end)
    {
      if (tmp->pos[0] != y || tmp->pos[1] != x)
	tmp = tmp->next;
      else
	end = 1;
    }
  if (tmp->pos[0] == y && tmp->pos[1] == x)
    {
      end = getBestWay(tmp, y2, x2);
      if (end == 0 || end == 1)
	return (end == 0 ? UP : RIGHT);
      else if (end == 2 || end == 3)
	return (end == 2 ? DOWN : LEFT);
    }
  return (-1);
}

int			GamePacman::isBlocked(int i, int j) const
{
  if (i < 0 || j < 0)
    return (1);
  if (i >= _height || j >= _width)
    return (1);
  if (_map[i][j] != 1 && _map[i][j] != 3)
    return (0);
  return (1);
}

void			GamePacman::addNeighboor(t_paths **paths, int i, int j, int k) const
{
  t_paths		*tmp;

  if ((tmp = (*paths)->next) == NULL)
    return;
  while (tmp != *paths && (tmp->pos[0] != i || tmp->pos[1] != j))
    tmp = tmp->next;
  if (tmp->pos[0] == i && tmp->pos[1] == j)
    (*paths)->neighboors[k] = tmp;
}

void			GamePacman::addNeighboors(t_paths **paths) const
{
  int			tiles[4][2];
  int			i;

  tiles[0][0] = (*paths)->pos[0] - 1;
  tiles[1][0] = (*paths)->pos[0];
  tiles[2][0] = (*paths)->pos[0] + 1;
  tiles[3][0] = (*paths)->pos[0];
  tiles[0][1] = (*paths)->pos[1];
  tiles[1][1] = (*paths)->pos[1] + 1;
  tiles[2][1] = (*paths)->pos[1];
  tiles[3][1] = (*paths)->pos[1] - 1;
  for (i = 0; i < 4; i++)
    {
      if (tiles[i][0] >= _height)
	tiles[i][0] = 0;
      if (tiles[i][1] >= _width)
	tiles[i][1] = 0;
      if (tiles[i][0] < 0)
	tiles[i][0] = _height - 1;
      if (tiles[i][1] < 0)
	tiles[i][1] = _width - 1;
      if (!isBlocked(tiles[i][0], tiles[i][1]))
	addNeighboor(paths, tiles[i][0], tiles[i][1], i);
    }
}

void			GamePacman::addInPaths(t_paths **paths, int i, int j, int id) const
{
  t_paths		*elem;
  t_paths		*tmp;
  int			k;

  elem = new t_paths;
  elem->visited = 0;
  elem->id = id;
  elem->pos[0] = i;
  elem->pos[1] = j;
  elem->next = elem;
  for (k = 0; k < 4; k++)
    elem->neighboors[k] = NULL;
  if (*paths != NULL)
    {
      tmp = *paths;
      while (tmp->next != *paths)
	tmp = tmp->next;
      elem->next = *paths;
      tmp->next = elem;
    }
  else
    *paths = elem;
}

void			GamePacman::freePaths()
{
  t_paths	*tmp;
  t_paths	*tmp2;

  tmp = _paths->next;
  while (tmp != _paths)
    {
      tmp2 = tmp;
      tmp = tmp->next;
      delete tmp2;
    }
  delete tmp;

}

void			GamePacman::processPaths()
{
  t_paths		*tmp;
  int			i;
  int			j;
  int			id;

  _paths = NULL;
  _nbPaths = 0;
  id = 1;
  for (i = 0; i < _height; i++)
    for (j = 0; j < _width; j++)
      if (_map[i][j] != 1)
	{
	  addInPaths(&_paths, i, j, id++);
	  _nbPaths++;
	}
  if (_paths == NULL)
    return ;
  tmp = _paths->next;
  while (tmp != _paths)
    {
      addNeighboors(&tmp);
      tmp = tmp->next;
    }
  addNeighboors(&_paths);
}
