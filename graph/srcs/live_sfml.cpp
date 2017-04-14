//
// live_sfml.cpp for  in /home/samy.aitouakli/livecoding/graph
// 
// Made by Samy Aitouakli
// Login   <samy.aitouakli@epitech.net>
// 
// Started on  Tue Apr 11 11:59:21 2017 Samy Aitouakli
// Last update Thu Apr 13 12:29:51 2017 Samy Aitouakli
//

#include "live_sfml.hh"
#include <iostream>

live::Graph::Graph()
{
  _window.create(sf::VideoMode(1240, 960), "Livecoding generation procedurale.");
  _window.setFramerateLimit(20);
}

live::Graph::~Graph()
{

}

int			live::Graph::display(live::Map const &my_map)
{
  sf::Sprite		sprite;
  int			x;
  int			y;
  int			i;
  static int		pos_x = 0;
  static int		pos_y = 0;

  if (!_texture.loadFromFile(my_map.getFileName()))
    {
      std::cerr << "Error loading file" << std::endl;
      return (1);
    }
  sprite.setTexture(_texture);
  i = 0;
  while (i < my_map.getWidth() * my_map.getHeight())
    {
      x = my_map.getPos(i).x;
      y = my_map.getPos(i).y;
      if (my_map.getWidth() <= 60 || my_map.getHeight() <= 40 ||
	  (((i - (pos_y)) % my_map.getWidth()) <= 60 &&
	   (((i - (pos_x * my_map.getWidth())) / my_map.getWidth())) <= 40))
	{
	  sprite.setPosition(sf::Vector2f(((i - (pos_y)) % my_map.getWidth()) * 24,
					  ((i - (pos_x * my_map.getWidth())) /
					   my_map.getWidth()) * 24));
	  sprite.setTextureRect(sf::IntRect(x * 24 + (x + 1), 17 + y * 24 + (y + 1), 24, 24));
	  ++i;
	}
      else
	i += my_map.getWidth() - 61;
      _window.draw(sprite);
    }
  _window.display();
  _window.clear();
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    return (1);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && pos_x > 0)
    --pos_x;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && pos_x < my_map.getHeight() - 40)
    ++pos_x;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && pos_y > 0)
    --pos_y;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && pos_y < my_map.getWidth() - 60)
    ++pos_y;
  return (0);
}
