//
// Score.hpp for Score in /home/noboud_n/rendu/cpp_arcade/src
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.net>
//
// Started on  Wed Mar 30 18:03:56 2016 Nyrandone Noboud-Inpeng
// Last update Sun Apr  3 18:11:54 2016 Nyrandone Noboud-Inpeng
//

#ifndef SCORE_HPP_
# define SCORE_HPP_

# include <fstream>

class		Score
{
public:
  Score();
  ~Score();
  Score(const Score &);
  Score		&operator=(const Score &);

  std::string	*getScoreTab() const;
  int		getScore(std::string) const;
  void		checkHighscore();
  void		createFile(std::string, int, std::string);
  void		addScore(std::string, int, std::string);
  void		checkGame(std::string, std::string, std::string);

  int		_i;
  std::string	_login;
  int		_score;
  std::string	_typeGame;
private:
  std::ifstream	_readFile;
  std::ofstream	_writeFile;
  std::string	*_scoreTab;
};

#endif /* SCORE_HPP_ */
