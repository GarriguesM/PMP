/*
** my_pixel.c for  in /home/garrig_b/PMP
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Wed Jun 18 17:10:44 2014 a
** Last update Sun Jun 22 21:41:25 2014 a
*/

#include "paint.h"
#include "mlx.h"

void            mlx_pixel_to_img(int x, int y, t_env *env, int color)
{
  int           pixel;

  pixel = (( x * (env->init->bpp / 8))
	   + (y * env->init->sizeline));
  if (env->init->endian == 0)
    {
      env->init->data[pixel] = mlx_get_color_value
	(env->mlx, color);
      env->init->data[pixel + 1]
	= mlx_get_color_value(env->mlx, color >> 8);
      env->init->data[pixel + 2]
	= mlx_get_color_value(env->mlx, color >> 16);
      return ;
    }
  env->init->data[pixel] = mlx_get_color_value
    (env->mlx, color >> 16);
  env->init->data[pixel + 1]
    = mlx_get_color_value(env->mlx, color >> 8);
  env->init->data[pixel + 2] = mlx_get_color_value
    (env->mlx, color);
  return ;
}

void            mlx_pixel_to_img_2(int x, int y, t_env *env, int color)
{
  int           pixel;

  pixel = (( x * (env->colors->bpp / 8)) + (y * env->colors->sizeline));
  if (env->colors->endian == 0)
    {
      env->colors->data[pixel] = mlx_get_color_value
	(env->mlx, color);
      env->colors->data[pixel + 1] = mlx_get_color_value
	(env->mlx, color >> 8);
      env->colors->data[pixel + 2] = mlx_get_color_value
	(env->mlx, color >> 16);
      return ;
    }
  env->colors->data[pixel] = mlx_get_color_value
    (env->mlx, color >> 16);
  env->colors->data[pixel + 1] = mlx_get_color_value
    (env->mlx, color >> 8);
  env->colors->data[pixel + 2] = mlx_get_color_value
    (env->mlx, color);
  return ;
}
