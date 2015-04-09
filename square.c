/*
** figure.c for  in /home/garrig_b/PMP
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Wed Jun 18 17:00:43 2014 a
** Last update Sun Jun 22 22:18:11 2014 a
*/

#include "paint.h"
#include "mlx.h"

void	rectangle(t_env  *env, int x, int y, int taille)
{
  int	tmp_x;
  int	tmp_y;
  int	tmp;

  tmp = y;
  tmp_x = x + taille;
  tmp_y = y + taille;
  if (tmp_y > PMP_Y && tmp_x > PMP_X)
    return ;
  while (x != tmp_x)
    {
      y = tmp;
      if (y < 0)
	return ;
      if (x < 0)
	return ;
      while (y != tmp_y)
	{
          mlx_pixel_to_img(x , y, env, g_color_full);
	  ++y;
	}
      x++;
    }
}

void	rectangle_contour(t_env *env, int x, int y, int taille)
{
  int	tmp;
  int	tmp_x;
  int	tmp_y;
  int	x1;
  int	y1;

  tmp = x;
  tmp_y = y + taille;
  tmp_x = x + taille;
  if (tmp_y > PMP_Y && tmp_x > PMP_X)
    return ;
 while (x != tmp_x)
    {
      mlx_pixel_to_img(x, y, env, g_color_full);
      mlx_pixel_to_img(x, tmp_y, env, g_color_full);
      x++;
    }
  x = tmp;
  while (y != tmp_y)
    {
      mlx_pixel_to_img(x, y, env, g_color_full);
      mlx_pixel_to_img(tmp_x, y, env, g_color_full);
      y++;
    }
}

void	im_rectangle(t_env *env)
{
  if (g_brain != SQUARE)
    {
      mlx_string_put(env->mlx, env->tools->win, 50, 66,
		   0x00000000, "  # ");
      return ;
    }
  else if (g_brain == SQUARE)
    {
      mlx_string_put(env->mlx, env->tools->win, 50, 66,
		     0x00ff0000, "  # ");
      return ;
    }
  gere_expose_4(env);
}

void	main_rectangle_contour(int x, int y, t_env *env)
{
  if (g_size == NORMAL)
    {
      rectangle_contour(env, x, y, 20);
    }
  if (g_size == MEDIUM)
    {
      rectangle_contour(env, x, y, 30);
    }
  if (g_size == LARGE)
    {
      rectangle_contour(env, x, y, 50);
    }
}

void	main_rectangle(int x, int y, t_env *env)
{
  if (g_size == NORMAL)
    {
      rectangle(env, x, y, 20);
    }
  if (g_size == MEDIUM)
    {
      rectangle(env, x, y, 30);
    }
  if (g_size == LARGE)
    {
      rectangle(env, x, y, 50);
    }
}
