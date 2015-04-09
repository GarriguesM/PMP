/*
** gere_mouse.c for  in /home/garrig_b/PMP
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Fri Jun 20 03:39:32 2014 a
** Last update Sun Jun 22 21:53:22 2014 a
*/

#include "paint.h"

void	colors_palette(t_env *env)
{
  int		x;
  int		y;

  x = 0;
  while (x != 40)
    {
      y = 0;
      while (y != 40)
	mlx_pixel_to_img_2(x , y++, env, BLUE);
      ++x;
    }
  while (x != 80)
    {
      y = 0;
      while (y != 40)
	mlx_pixel_to_img_2(x , y++, env, PURPLE);
      x++;
    }
  while (x != 120)
    {
      y = 0;
      while (y != 40)
	mlx_pixel_to_img_2(x , y++, env, PINK);
      x++;
    }
}

int	gere_mouse(int buttons, int x, int y, t_env  *env)
{
  if (x <= 40)
    {
      g_color_full = BLUE;
      pencil(env);
      return ;
    }
  if (x <= 80)
    {
      g_color_full = PURPLE;
      pencil(env);
      return ;
    }
  else if (x <= 120)
    {
      g_color_full = PINK;
      pencil(env);
      return ;
    }
}

void	colors_main(t_env  *env)
{
  colors_palette(env);
}
