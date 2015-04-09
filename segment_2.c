/*
** segment_2.c for  in /home/garrig_b/PMP
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Sun Jun 22 04:21:30 2014 a
** Last update Sun Jun 22 21:46:50 2014 a
*/
#include "paint.h"

void	trace_large_segment(t_env *env, int xy[4])
{
  int	tmp_xy[4];
  int	tmp_xy2[4];

  tmp_xy[0] = xy[0] + 2;
  tmp_xy[1] = xy[1] + 2;
  tmp_xy[2] = xy[2] + 2;
  tmp_xy[3] = xy[3] + 2;
  trace_segment(env, tmp_xy);
  tmp_xy2[0] = xy[0] - 2;
  tmp_xy2[1] = xy[1] - 2;
  tmp_xy2[2] = xy[2] - 2;
  tmp_xy2[3] = xy[3] - 2;
  trace_segment(env, tmp_xy2);
}

void	trace_medium_segment(t_env *env, int xy[4])
{
  int	tmp_xy[4];
  int	tmp_xy2[4];

  tmp_xy[0] = xy[0] + 1;
  tmp_xy[1] = xy[1] + 1;
  tmp_xy[2] = xy[2] + 1;
  tmp_xy[3] = xy[3] + 1;
  trace_segment(env, tmp_xy);
  tmp_xy2[0] = xy[0] - 1;
  tmp_xy2[1] = xy[1] - 1;
  tmp_xy2[2] = xy[2] - 1;
  tmp_xy2[3] = xy[3] - 1;
  trace_segment(env, tmp_xy2);
}

void	main_segment(t_env *env, int xy[4])
{
  if (g_size == NORMAL)
    {
      trace_segment(env, xy);
      return ;
    }
  if (g_size == MEDIUM)
    {
      trace_segment(env, xy);
      trace_medium_segment(env, xy);
      return ;
    }
  if (g_size == LARGE)
    {
      trace_segment(env, xy);
      trace_medium_segment(env, xy);
      trace_large_segment(env, xy);
    }
}
