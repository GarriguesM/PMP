/*
** strlcpy.c for  in /home/garrig_b/PMP
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Fri Jun 20 18:47:53 2014 a
** Last update Sun Jun 22 21:24:54 2014 a
*/
#include <sys/types.h>
#include <string.h>

size_t		strlcpy(char *dst, const char *src, size_t size)
{
  size_t	length;
  size_t	copy;

  length = strlen(src);
  if (size > 0)
    {
      copy = (length >= size) ? size - 1 : length;
      memcpy(dst, src, copy);
      dst[copy] = '\0';
    }
  return (length);
}
