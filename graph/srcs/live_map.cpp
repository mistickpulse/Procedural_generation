//
// live_map.cpp for  in /home/samy.aitouakli/livecoding/graph
// 
// Made by Samy Aitouakli
// Login   <samy.aitouakli@epitech.net>
// 
// Started on  Tue Apr 11 12:38:38 2017 Samy Aitouakli
// Last update Wed Apr 12 18:00:29 2017 Samy Aitouakli
//

#include "live_map.hh"
#include <iostream>
#include <exception>

static t_position	sToPos(std::string str)
{
  t_position		ret;

  ret.x = str.at(0);
  ret.y = str.at(2);
  return (ret);
}

live::Map::Map()
{}

live::Map::~Map()
{}

void		live::Map::buildMap()
{
  int		i;

  i = 0;
  for (std::string line; std::getline(std::cin, line);)
    {
      if (i == 0)
	_height = stoi(line);
      else if (i == 1)
	_width = stoi(line);
      else if (i == 2)
	_filename = line;
      else
	this->_map.push_back(sToPos(line));
      ++i;
    }
}

std::string	live::Map::getFileName() const
{
  return (_filename);
}

t_position	live::Map::getPos(int index) const
{
  return (_map.at(index));
}

int		live::Map::getWidth() const
{
  return (_width);
}

int		live::Map::getHeight() const
{
return (_height);
}
