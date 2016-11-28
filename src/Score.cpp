//
// Score.cpp for Score in /home/noboud_n/rendu/cpp_arcade/src
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.net>
//
// Started on  Wed Mar 30 18:34:30 2016 Nyrandone Noboud-Inpeng
// Last update Sun Apr  3 21:54:05 2016 guillaume wilmot
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include "Score.hpp"

Score::Score() : _readFile("ScoreFile.score", std::ifstream::in)
{}

Score::~Score()
{}

Score::Score(const Score &) {}

Score		&Score::operator=(const Score &)
{
  return (*this);
}

std::string	*Score::getScoreTab() const
{
  return (_scoreTab);
}

void		Score::checkHighscore()
{
  int		i;

  i = 0;
  _scoreTab = new std::string[25];
  if (_readFile.is_open())
    {
      while (!_readFile.eof() && i < 20)
	{
	  std::getline(_readFile, _scoreTab[i]);
	  ++i;
	}
    }
  while (i < 20)
    _scoreTab[i++] = "";
}

void		Score::createFile(std::string login, int score, std::string typeGame)
{
  std::cout << typeGame << std::endl;
  _writeFile.open("ScoreFile.score");
  _writeFile << "Score of Arcade" << std::endl;
  _writeFile << "Snake:" << std::endl;
  if (typeGame == "lib_arcade_snake.so")
    _writeFile << login.c_str() << " -- " << score << std::endl;
  _writeFile << "Pacman:" << std::endl;
  if (typeGame == "lib_arcade_pacman.so")
    _writeFile << login.c_str() << " -- " << score << std::endl;
  _writeFile << "Centipede:" << std::endl;
  if (typeGame == "lib_arcade_centipede.so")
    _writeFile << login.c_str() << " -- " << score << std::endl;
  _writeFile.close();
}

int		Score::getScore(std::string str) const
{
  std::size_t		place;
  int			score;

  std::reverse(str.begin(), str.end());
  place = str.find(" -- ");
  if (place != std::string::npos)
    str = str.substr(0, place);
  std::reverse(str.begin(), str.end());
  score = std::stoi(str);
  return (score);
}

void		Score::addScore(std::string login, int score, std::string typeGame)
{
  _i = 0;
  _login = login;
  _score = score;
  _typeGame = typeGame;
  _writeFile.open("ScoreFile.score");
  while (_i < 20 && _scoreTab[_i] != "")
    {
      while (_i < 20 && _scoreTab[_i] != "" &&
	     _scoreTab[_i] != "Snake:")
	++_i;
      checkGame("Snake:", "Pacman:", "lib_arcade_snake.so");
      checkGame("Pacman:", "Centipede:", "lib_arcade_pacman.so");
      checkGame("Centipede:", "", "lib_arcade_centipede.so");
    }
  _writeFile.close();
}

void		Score::checkGame(std::string game, std::string nextGame, std::string type)
{
  int			pos;
  int			allScore[3];
  int			max;
  int			little;
  int			done;

  pos = 0;
  if (_scoreTab[_i] == game)
    {
      ++_i;
      while (_i < 20 && _scoreTab[_i] != "" &&
	     _scoreTab[_i] != nextGame)
	allScore[pos++] = getScore(_scoreTab[_i++]);
      if (game == "Snake:")
	_writeFile << "Score of Arcade" << std::endl;
      _writeFile << game << std::endl;
      _i -= pos;
      max = pos == 3 ? 1 : 0;
      while (pos < 3)
	allScore[pos++] = -1;
      pos = 0;
      little = allScore[0];
      while (pos < 3 && allScore[pos] != -1)
	{
	  if (allScore[pos] < little)
	    little = allScore[pos];
	  ++pos;
	}
      pos = 0;
      done = 0;
      while (pos < 3 && allScore[pos] != -1)
	{
	  if (little == allScore[pos] && _typeGame == type && max == 1 && done == 0 && little < _score)
	    {
	      done = 1;
	      _writeFile << _login << " -- " << _score << std::endl;
	      ++_i;
	    }
	  else
	    _writeFile << _scoreTab[_i++] << std::endl;
	  ++pos;
	}
      if (max == 0 && _typeGame == type)
	_writeFile << _login << " -- " << _score << std::endl;
    }
}
