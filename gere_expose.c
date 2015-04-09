/*
** gere_expose.c for  in /home/garrig_b/PMP
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Fri Jun 20 12:00:09 2014 a
** Last update Sun Jun 22 21:51:03 2014 a
*/

#include "paint.h"
#include "mlx.h"

int		gere_expose(t_env *env)
{
  mlx_put_image_to_window (env->mlx, env->init->win, env->init->img, 0, 0);
  return (0);
}

int		gere_expose_2(t_env *env)
{
  mlx_put_image_to_window (env->mlx, env->colors->win,
			   env->colors->img, 0, 0);
  return (0);
}

int		gere_expose_3(t_env *env)
{
  mlx_put_image_to_window (env->mlx, env->presentation->win,
			   env->presentation->img, 0, 0);
  return (0);
}

int		gere_expose_4(t_env *env)
{
  mlx_put_image_to_window (env->mlx, env->tools->win,
			   env->tools->xpm, 0, 0);
  mlx_string_put(env->mlx, env->tools->win, 0, 66,
                 0x00ffffff, " 1 2 3 ");
  mlx_string_put(env->mlx, env->tools->win, 0, 76,
                 0x00ffffff, "  space =  rubber  c = clear windows");
  return (0);
}

int		gere_key(int keycode, t_env *env)
{
  if (keycode ==  RUBBER)
    g_brain = RUBBER;
  if (keycode == NORMAL)
    g_size = NORMAL;
  if (keycode == MEDIUM)
    g_size = MEDIUM;
  if (keycode == LARGE)
    g_size = LARGE;
  if (keycode == CLEAR)
    {
      my_clear(env);
      gere_expose(env);
      mlx_clear_window(env->mlx, env->tools->win);
      gere_expose_4(env);
    }
}
