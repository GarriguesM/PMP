/*
** tools.c for  in /home/garrig_b/PMP
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Fri Jun 20 16:30:32 2014 a
** Last update Sun Jun 22 21:59:50 2014 a
*/

#include "paint.h"
#include <stdlib.h>
#include "mlx.h"

void	pencil(t_env *env)
{
  int	x;
  int	y;

  x = 0;
  while (x != 35)
    {
      y = 65;
      while (y != 70)
	{
	  mlx_string_put(env->mlx, env->tools->win, x, y,
			 g_color_full, "!");
          y++;
	}
      x++;
    }
  gere_expose_4(env);
}

int	gere_mouse_3(int buttons, int x, int y, t_env  *env)
{
  if(x >= 0 && x <= 40)
    g_brain = PENCIL;
  if (x >= 40 && x <= 80)
    g_brain = SQUARE;
  else if (x >= 80 &&  x <= 120)
    g_brain = TRIANGLE;
  else if (x >= 120 && x <= 160)
    g_brain = CIRCLE;
  else if (x >= 160 && x <= 200)
    {
      if(g_empty == ZERO)
	{
	  im_full(env);
	  return (g_empty = FULL);
	}
      if (g_empty == FULL)
	{
	  im_not_full(env);
	  return (g_empty = ZERO);
	}
    }
  else if (x >= 200 && x <= 230)
    exit(0);
}

t_mlx		*xpm_tools(char *str, void *mlx)
{
  int		x;
  int		y;
  t_mlx         *env;

  if ((env = malloc(sizeof(t_mlx))) == NULL)
    exit(my_putstr("MALLOC FAILED"));
  if ((env->win = mlx_new_window(mlx, 230, 80, str)) == NULL)
    exit(my_putstr("WINDOWS FAILED"));
  if ((env->img = mlx_new_image(mlx, 230, 80)) == NULL)
    exit(my_putstr("NEW IMAGE FAILED"));
  if ((env->data = mlx_get_data_addr
       (env->img, &env->bpp, &env->sizeline, &env->endian)) == NULL)
    exit(my_putstr("GET DATA FAILED"));
  if ((env->xpm = mlx_xpm_file_to_image(mlx, "CANCER.xpm", &x, &y)) == NULL)
    exit(my_putstr("TEXTURE FAILED"));
  if ((env->data_xpm = mlx_get_data_addr
       (env->img, &env->bpp, &env->sizeline, &env->endian)) == NULL)
    exit(my_putstr("GET DATA FAILED"));
  return (env);
}
