/*
** main.c for  in /home/zouzy/rendu/astek/ez/src
**
** Made by fabian.le-maux@epitech.eu
** Login   <le-mau_f@epitech.net>
**
** Started on  Wed Apr 12 22:19:16 2017 fabian.le-maux@epitech.eu
** Last update Fri Apr 14 11:32:18 2017 fabian.le-maux@epitech.eu
*/

#include <sys/types.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>

# define USAGE "Usage : ./gen [size x] [size y] [wall init qte (in %)]"  \
  " [neighbors needed to validate first rule] [same as the previous one" \
  " but for the secnd rule] [iteration qty]"
# define WALL '0'
# define EMPTY ' '

typedef struct s_gen
{
  char		**map; // map finale
  char		**tmp; // map de travail
  int		smapx; // size map x
  int		smapy; // ""  "" y
  int		fill; // fill %
  int		rnb1; // nbh_qte for rule 1
  int		rnb2; // nbh_qte for rule 2
  int		it; // nbr of application of all the rule on the map;
}		t_gen;

static char		**init_random(t_gen *core)
{
  double	wall_qte = ((core->smapx * core->smapy) * core->fill) / 100; // calcul du nombre de mur a placer dans la map

  srand(time(NULL));
  while (wall_qte > 0)
  {
    core->map[rand() % core->smapy][rand() % core->smapx] = WALL;
    wall_qte -= 1;
  }
  return (core->map);
}

static void		dump(char **map)
{
  for(int i = 0; map[i]; i++)
    printf("%s\n", map[i]);
}


static bool		rule1(t_gen *core, int y, int x, int nbr) // placing wall
{
  int		nbh = 0;

  for(int i = -1; i <= 1; i++)
    for(int j = -1; j <= 1; j++)
      if (core->map[y + i][x + j] == WALL)
	nbh += 1;

  if (nbh >= nbr)
    return (true);
  return (false);
}

static int		rule2(t_gen *core, int y, int x, int nbr) // smooth border
{
  int		nbh = 0;


  for(int i = y-2; i <= y+2; i++)
    for(int j = x-2; j <= x+2; j++)
    {
      if ((abs(i-y) == 2 && abs(j-x) == 2) || // pour ne pas se checker
	  ((i < 0 || j < 0 || i >= core->smapy || j >= core->smapx)))
	continue;
      if(core->map[i][j] == WALL)
	nbh++;
    }

  if (nbh <= nbr)
    return (true);
  return (false);
}

static char		**apply_rule(t_gen *core)
{
  for (int y = 1;y <core->smapy - 1; y++)
  {
    for (int x = 1;x <core->smapx - 1;x++)
    {
      if ((rule1(core, y, x, core->rnb1) == true) ||
	  (rule2(core, y, x, core->rnb2) == true))
	core->tmp[y][x] = WALL;
      else
	core->tmp[y][x] = EMPTY;
    }
  }
  for (int y = 1; y < core->smapy - 1; y++)
    memcpy(core->map[y], core->tmp[y], core->smapx - 1);
  return (core->map);
}

static void		set_initwall(t_gen *core)
{
  int x = 0;
  memset(core->map[0], WALL, core->smapx);
  memset(core->map[core->smapy - 1], WALL, core->smapx);
  while (core->map[x])
  {
    core->map[x][0] = WALL;
    core->map[x][core->smapx - 1] = WALL;
    ++x;
  }
}

static char		**initm(t_gen *core)
{
  char		**ret;

  ret = malloc(sizeof(char *) * (core->smapy + 3));
  for (int i = 0; i < core->smapy; i++)
  {
    ret[i] = malloc(sizeof(char) * (core->smapx + 3));
    ret[i][core->smapx] = 0;
    memset(ret[i], ' ', core->smapx);
  }
  ret[core->smapy] = NULL;
  return (ret);
}

static char		**fullfill(t_gen *core)
{
  for (int i = 0; i < core->smapy - 1; i++)
    for(int j = 0;j < core->smapx - 1; j++)
      core->tmp[i][j] = WALL;
  return (core->tmp);
}

static void		init_args(char **av, t_gen *core)
{
  core->smapx = atoi(av[1]);
  core->smapy = atoi(av[2]);
  core->fill = atoi(av[3]);
  core->rnb1 = atoi(av[4]);
  core->rnb2 = atoi(av[5]);
  core->it = atoi(av[6]);
}

int		main(int ac, char **av)
{
  t_gen		core;

  if (ac != 7)
  {
    fprintf(stderr, "%s\n", USAGE);
    return (EXIT_FAILURE);
  }
  core.map = NULL;
  init_args(av, &core);

  core.map = initm(&core);//  allocated map
  core.tmp = initm(&core);//

  fullfill(&core); // fill tmp (working map) with wall


  set_initwall(&core); // place edge's around the map
  core.map = init_random(&core); // place wall randomly in map (that's make the random from the generation)

  for(;core.it > 0; core.it -= 1)
    core.map = apply_rule(&core);
  if (core.map != NULL)
    dump(core.map);
  return (0);
}
