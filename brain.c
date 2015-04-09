/*
** brain.c for  in /home/garrig_b/PMP
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Sat Jun 21 22:02:36 2014 a
** Last update Sun Jun 22 21:50:49 2014 a
*/

#include "paint.h"
#include <math.h>

void            my_dot(t_env *env, int diam, int x, int y)
{
  int           cosinus;
  int           sinus;
  int           a;

  a = 0;
  while (a <= 500)
    {
      cosinus =  diam*(sin(a));
      sinus =  diam*(cos(a));
      if (x + sinus < 0 && y + cosinus < 0)
	return ;
      mlx_pixel_to_img((x + cosinus),
                       (y + sinus), env, g_color_full);
      a++;
    }
}

void		trace_pencil(int x, int y, t_env *env, int diam)
{
  while (diam != 0)
    {
      my_dot(env, diam, x, y);
      diam--;
    }
}

void		pencil_brain(int x, int y, t_env *env)
{
  if (g_size == NORMAL)
    {
      mlx_pixel_to_img(x , y, env,  g_color_full);
      return;
    }
  if (g_size == MEDIUM)
    {
      trace_pencil(x, y, env, 2);
      return;
    }
  if (g_size == LARGE)
    {
      trace_pencil(x, y, env, 4);
      return;
    }
}

void	rubber(t_env  *env, int x, int y)
{
  int	tmp_x;
  int	tmp_y;
  int	tmp;

  tmp = y;
  tmp_x = x + 20;
  tmp_y = y + 20;
  while (x != tmp_x)
    {
      y = tmp;
      if (y < 0)
        return ;
      if (x < 0)
        return ;
      while (y != tmp_y)
        {
          mlx_pixel_to_img(x , y, env, 0x000000);
          ++y;
        }
      x++;
    }
}

void		my_brain(int x, int y, t_env *env)
{
  if (g_brain == PENCIL)
    pencil_brain(x, y, env);
  if (g_brain == SQUARE)
    brain_square(x, y, env);
  if (g_brain == TRIANGLE)
    brain_triangle(x, y, env);
  if (g_brain == CIRCLE)
    brain_circle(x, y, env);
  if (g_brain == RUBBER)
    rubber(env, x, y);
}
