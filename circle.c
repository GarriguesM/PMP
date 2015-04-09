/*
** test2.c for  in /home/garrig_b/PMP
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Thu Jun 19 20:50:03 2014 a
** Last update Sun Jun 22 21:40:57 2014 a
*/

#include "mlx.h"
#include "paint.h"

void		im_circle(t_env *env)
{
  if (g_brain == CIRCLE)
    {
      mlx_string_put(env->mlx, env->tools->win, 50, 66,
		     0x00fde910, "               o ");
      return ;
    }
  else if (g_brain != CIRCLE)
    {
      mlx_string_put(env->mlx, env->tools->win, 50, 66,
                     0x00000000, "               o ");
      return ;
    }
  gere_expose_4(env);
}

void		main_circle(int x, int y, t_env *env)
{
  if (g_size == NORMAL)
    my_dot(env, 10, x, y);
  if (g_size == MEDIUM)
    my_dot(env, 20, x, y);
  if (g_size == LARGE)
    my_dot(env, 40, x, y);
}

void		main_full_circle(int x, int y, t_env *env)
{
  if (g_size == NORMAL)
    trace_pencil(x, y, env, 10);
  if (g_size == MEDIUM)
    trace_pencil(x, y, env, 20);
  if (g_size == LARGE)
    trace_pencil(x, y, env, 40);
}

void		brain_circle(int x, int y, t_env *env)
{
  im_circle(env);
  if (g_empty == ZERO)
    main_circle(x, y, env);
  if (g_empty == FULL)
    main_full_circle(x, y, env);
  gere_expose(env);
}
