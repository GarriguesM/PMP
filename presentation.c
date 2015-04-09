/*
** presentation.c for  in /home/garrig_b/PMP
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Fri Jun 20 09:57:42 2014 a
** Last update Sun Jun 22 22:05:05 2014 a
*/

#include <unistd.h>
#include "paint.h"
#include "mlx.h"

void	presentation_0(t_env *env)
{
  int	x;
  int	y;

  x = 0;
  while (x  != PMP_X)
    {
      y = 0;
      while ( y != PMP_Y)
	mlx_pixel_put(env->mlx,
		      env->presentation->win, x, y++, PURPLE);
      x++;
    }
  mlx_string_put(env->mlx,
		 env->presentation->win, 250, 105,
		 0x00ff0000, "PIMP MY PAINT ");
  sleep(1.5);
  mlx_destroy_window(env->mlx, env->presentation->win);
}

void		presentation(t_env *env)
{
  presentation_0(env);
}
