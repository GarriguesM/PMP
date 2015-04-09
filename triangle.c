/*
** triangle.c for  in /home/garrig_b/PMP
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Wed Jun 18 20:33:55 2014 a
** Last update Sun Jun 22 21:49:04 2014 a
*/

#include "paint.h"
#include <stdlib.h>

void    draw_triangle_1(t_env *env, t_cntr * r, int taille)
{
  int   x;
  int   y;

  x = r->x1;
  while (x <= r->x2)
    {
      y = r->y1 + ((r->y2 - r->y1) * (x - r->x1)) / (r->x2 - r->x1);
      mlx_pixel_to_img(x, y, env,  g_color_full);
      x++;
    }
}

void	draw_triangle_2(t_env *env, t_cntr *r, int taille)
{
  int   x;
  int   y;

  x = r->x2;
  while (x <= r->x1)
    {
      y = r->y1 + ((r->y2 - r->y1) * (x - r->x1)) / (r->x2 - r->x1);
      mlx_pixel_to_img(x + taille, y, env,  g_color_full);
      x++;
    }
}

void		triangle(t_env *env, int x, int y, int taille)
{
  t_cntr	*tmp;
  t_cntr        *tmp2;

  if ((tmp = malloc(sizeof(t_cntr))) == NULL)
    exit(my_putstr("MALLOC FAILED"));
  if ((tmp2 = malloc(sizeof(t_cntr))) == NULL)
    exit(my_putstr("MALLOC FAILED"));
  tmp->x1 = x;
  tmp->y1 = y;
  tmp->x2 = x + taille;
  tmp->y2 = y - taille;
  draw_triangle_1(env, tmp, taille);
  tmp2->x1 = x + taille;
  tmp2->y1 = y;
  tmp2->x2 = x;
  tmp2->y2 = y - taille;
  draw_triangle_2(env, tmp2, taille);
}

void	triangle_2(t_env *env, int x, int y, int taille)
{
  int	tmp_x;


  tmp_x = x + taille;
  while (x != tmp_x)
    {
      mlx_pixel_to_img(x, y, env, g_color_full);
      x++;
    }
}
