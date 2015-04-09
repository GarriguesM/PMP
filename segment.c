/*
** segment.c for  in /home/garrig_b/PMP
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Fri Jun 20 12:31:17 2014 a
** Last update Sun Jun 22 21:33:57 2014 a
*/

#include "paint.h"
#include <stdlib.h>
#include <math.h>
#include "mlx.h"

void	segment_2(t_env *env, t_cntr *r)
{
  int   x;
  int   y;

  if (r->x2 == r->x1)
    return ;
  x = r->x2;
  while (x <= r->x1)
    {
      y = r->y1 + ((r->y2 - r->y1) * (x - r->x1)) / (r->x2 - r->x1);
      mlx_pixel_to_img(x, y, env,  g_color_full);
      x++;
    }
}

void	segment_1(t_env *env, t_cntr * r)
{
  int   x;
  int   y;

  if (r->x2 == r->x1)
    return ;
  x = r->x1;
  while (x <= r->x2)
    {
      y = r->y1 + ((r->y2 - r->y1) * (x - r->x1)) / (r->x2 - r->x1);
      mlx_pixel_to_img(x, y, env,  g_color_full);
      x++;
    }
}

void	segment_3(t_env *env, t_cntr * r)
{
  int	x;
  int	y;
  if (r->y2 == r->y1)
    return ;
  y = r->y1;
  while (y <= r->y2)
    {
      x = r->x1 + ((r->x2 - r->x1) *  (y - r->y1)) / (r->y2 - r->y1);
      mlx_pixel_to_img(x, y, env,  g_color_full);
      y++;
   }
}

void	segment_4(t_env *env, t_cntr * r)
{
  int	x;
  int	y;

  if (r->y2 == r->y1)
    return ;
  y = r->y2;
  while (y <= r->y1)
    {
     x = r->x1 + ((r->x2 - r->x1) *  (y - r->y1)) / (r->y2 - r->y1);
     mlx_pixel_to_img(x, y, env,  g_color_full);
     y++;
    }
}

void		trace_segment(t_env *env, int xy[4])
{
  t_cntr        *tmp;

  if ((tmp = malloc(sizeof(t_cntr))) == NULL)
    exit(my_putstr("MALLOC FAILED"));
  tmp->x1 = xy[0];
  tmp->y1 = xy[1];
  tmp->x2 = xy[2];
  tmp->y2 = xy[3];

  if (xy[0] <= xy[2] && (xy[2] - xy[0]) >= ABSCIS(xy[3] - xy[1]))
    segment_1(env, tmp);
  else if (xy[2] <= xy[0] && (xy[0] - xy[2]) >= ABSCIS(xy[1] - xy[3]))
    segment_2(env, tmp);
  else if (xy[1] <= xy[3] && (xy[3] - xy[1]) >= ABSCIS(xy[2] - xy[0]))
    segment_3(env, tmp);
  else
    segment_4(env, tmp);
}
