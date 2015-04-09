/*
** clear.c for  in /home/garrig_b/PMP
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Sat Jun 21 21:32:26 2014 a
** Last update Sun Jun 22 21:35:06 2014 a
*/

#include "paint.h"
#include "mlx.h"

void	im_full(t_env *env)
{
  mlx_string_put(env->mlx, env->tools->win, 50, 66,
		 0x00ffffff, "                      +");
  gere_expose_4(env);
}

void	im_not_full(t_env *env)
{
  mlx_string_put(env->mlx, env->tools->win, 50, 66,
                 0x0000000, "                      +");
  gere_expose_4(env);
}

void	activation(t_env *env)
{
  im_rectangle(env);
  im_triangle(env);
  im_circle(env);
}

void	my_clear(t_env *env)
{
  int	x;
  int	y;

  x = 0;
  while (x != PMP_X)
    {
      y = 0;
      while (y != PMP_Y)
	{
	  mlx_pixel_to_img(x, y, env, 0);
	  y++;
	}
     x++;
    }
}
