
/*
** main.c for  in /home/garrig_b/PMP
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Wed Jun 18 20:45:19 2014 a
** Last update Tue Jun 24 18:25:58 2014 a
*/

#include "paint.h"
#include <stdlib.h>
#include "mlx.h"

int		g_color_full = 0x00ffffff;
int		g_brain = SQUARE;
int		g_empty = 0;
int		g_size = NORMAL;

int		gere_mouse_2(int buttons, int x, int y, t_env  *env)
{
  static int	xy[4];
  static int	segment;

  activation(env);
  if (buttons == 1)
    my_brain(x, y, env);
  if (buttons == 3)
    {
      segment++;
      if (segment % 2 > 0 )
        {
          mlx_pixel_to_img(x , y, env,  g_color_full);
          xy[0] = x;
          xy[1] = y;
        }
      else if (segment % 2  == 0)
        {
          xy[2] = x;
          xy[3] = y;
          main_segment(env, xy);
        }
    }
  gere_expose(env);
}

t_env		*connection()
{
  t_env		*env;

  if ((env = (t_env*)malloc(sizeof(*env))) == NULL)
    exit (my_putstr("MALLOC FAILED"));
  if ((env->mlx = mlx_init()) == NULL)
    exit(my_putstr("INIT FAILED"));
  return (env);
}

t_mlx		*new_windows(char *str, int x, int y, void *mlx)
{
  t_mlx		*env;

  if ((env = malloc(sizeof(t_mlx))) == NULL)
    exit(my_putstr("MALLOC FAILED"));
  if ((env->win = mlx_new_window(mlx, x, y, str)) == NULL)
    exit(my_putstr("WINDOWS FAILED"));
  if ((env->img = mlx_new_image(mlx, x, y)) == NULL)
    exit(my_putstr("NEW IMAGE FAILED"));
  if ((env->data = mlx_get_data_addr
       (env->img, &env->bpp, &env->sizeline, &env->endian)) == NULL)
    exit(my_putstr("GET DATA FAILED"));
  return (env);
}

int		main()
{
  t_env		*env;

  env = connection();
  env->tools = xpm_tools("TOOLS", env->mlx);
  mlx_expose_hook(env->tools->win, gere_expose_4, env);
  mlx_mouse_hook(env->tools->win, gere_mouse_3, env);

  env->colors = new_windows("COLORS", CL_Y, CL_X, env->mlx);
  mlx_expose_hook(env->colors->win, gere_expose_2, env);
  mlx_mouse_hook(env->colors->win, gere_mouse, env);

  colors_main(env);
  env->init = new_windows("PMP", PMP_X, PMP_Y, env->mlx);
  mlx_expose_hook(env->init->win, gere_expose, env);
  mlx_mouse_hook(env->init->win, gere_mouse_2, env);
  mlx_key_hook(env->init->win, gere_key, env);
  env->presentation = new_windows("WELCOME", PMP_X, PMP_Y, env->mlx);
  mlx_expose_hook(env->presentation->win, gere_expose_3, env);
  presentation(env);
  mlx_loop(env->mlx);
  return (1);
}
