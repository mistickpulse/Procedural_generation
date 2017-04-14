//
// live_map.hh for  in /home/samy.aitouakli/livecoding/graph
// 
// Made by Samy Aitouakli
// Login   <samy.aitouakli@epitech.net>
// 
// Started on  Tue Apr 11 12:06:40 2017 Samy Aitouakli
// Last update Fri Apr 14 10:17:01 2017 fabian.le-maux@epitech.eu
//

#ifndef LIVE_MAP_HH
# define LIVE_MAP_HH

# include <string>
# include <vector>

typedef struct			s_position
{
  int				x;
  int				y;
}				t_position;

namespace			live
{
  class				Map
  {
  private:
    std::string			_filename;
    int				_width;
    int				_height;
    std::vector<t_position>	_map;
  public:
    Map();
    ~Map();
    void			buildMap();
    std::string			getFileName() const;
    t_position			getPos(int index) const;
    int				getWidth() const;
    int				getHeight() const;
  };
}

#endif // !LIVE_MAP_HH
