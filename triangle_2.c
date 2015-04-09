/*
** triangle_2.c for  in /home/garrig_b/PMP
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Thu Jun 19 01:01:21 2014 a
** Last update Sun Jun 22 21:30:16 2014 a
*/

#include "paint.h"
#include "mlx.h"

void		im_triangle(t_env *env)
{
  if (g_brain != TRIANGLE)
    {
      mlx_string_put(env->mlx, env->tools->win, 50, 66,
		     0x00000000, "        /\\ ");
      return ;
    }
  else if (g_brain == TRIANGLE)
    {
      mlx_string_put(env->mlx, env->tools->win, 50, 66,
		     0x0000ff00, "        /\\ ");
      return ;
    }
  gere_expose_4(env);
}

void	triangle_0(t_env *env, int x, int y, int taille)
{
  int	end;
  int	tmp_x;
  int	tmp2;
  int	tmp;
  int	tmp3;
  int	i;

  end = taille / 2;
  i = 0;
  tmp3 = x;
  tmp2 = x + taille;
  tmp_x = x + taille;
  tmp = x;
  while (tmp3 != tmp2)
    {
      while (x != tmp_x)
	mlx_pixel_to_img(x++, y, env, g_color_full);
      tmp_x--;
      y--;
      x = ++tmp;
      tmp2++;
      if (i++ == end)
	return;
    }
}
