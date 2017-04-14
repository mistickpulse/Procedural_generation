//
// main.cpp for  in /home/samy.aitouakli/livecoding/graph
// 
// Made by Samy Aitouakli
// Login   <samy.aitouakli@epitech.net>
// 
// Started on  Tue Apr 11 11:58:36 2017 Samy Aitouakli
// Last update Fri Apr 14 10:35:48 2017 fabian.le-maux@epitech.eu
//

#include <unistd.h>
#include <iostream>
#include "live_sfml.hh"
#include "live_map.hh"

int		main()
{
  live::Graph	graph;
  live::Map	my_map;

  try
  {
    my_map.buildMap();
    while (graph.display(my_map) == 0)
      usleep(20000);
  }
  catch (std::out_of_range e)
  {
    std::cerr << "Error : index out of range" << std::endl;
  }
  catch (std::exception e)
  {
    std::cerr << "Cannot Handle this Error type" << std::endl;
  }
  return (0);
}
