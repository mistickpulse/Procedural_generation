//
// live_sfml.hh for  in /home/samy.aitouakli/livecoding/graph
// 
// Made by Samy Aitouakli
// Login   <samy.aitouakli@epitech.net>
// 
// Started on  Tue Apr 11 11:03:32 2017 Samy Aitouakli
// Last update Fri Apr 14 10:16:55 2017 fabian.le-maux@epitech.eu
//

#ifndef LIVE_SFML_HPP_
# define LIVE_SFML_HPP_

# include <SFML/Graphics.hpp>
# include "live_map.hh"

namespace		live
{
  class			Graph
  {
  private:
    sf::RenderWindow	_window;
    sf::Texture		_texture;

  public:
    Graph();
    ~Graph();
    int			display(live::Map const &my_map);
  };
}

#endif /* !LIVE_SFML_HPP_ */
