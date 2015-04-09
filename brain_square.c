/*
** brain_square.c for  in /home/garrig_b/PMP
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Sun Jun 22 17:15:40 2014 a
** Last update Sun Jun 22 21:38:33 2014 a
*/

#include "paint.h"

void	brain_square(int x, int y, t_env  *env)
{

  if (g_empty == FULL)
    main_rectangle(x, y, env);
  if (g_empty == ZERO)
    main_rectangle_contour(x, y, env);
  gere_expose(env);
}

void    main_triangle_contour(int x, int y, t_env *env)
{
  if (g_size == NORMAL)
    {
      triangle(env, x, y, 20);
      triangle_2(env, x, y, 40);
    }
  if (g_size == MEDIUM)
    {
      triangle(env, x, y, 30);
      triangle_2(env, x, y, 60);
    }
  if (g_size == LARGE)
    {
      triangle(env, x, y, 50);
      triangle_2(env, x, y, 100);
    }
}

void    main_triangle(int x, int y, t_env *env)
{
  if (g_size == NORMAL)
    {
      triangle_0(env, x, y, 20);
    }
  if (g_size == MEDIUM)
    {
      triangle_0(env, x, y, 30);
    }
  if (g_size == LARGE)
    {
      triangle_0(env, x, y, 50);
    }
}

void	brain_triangle(int x, int y, t_env *env)
{
  if (g_empty == FULL)
    main_triangle(x, y, env);
  if (g_empty == ZERO)
    main_triangle_contour(x, y, env);
  gere_expose(env);
}
