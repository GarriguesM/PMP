/*
** aff.c for  in /home/garrig_b/PMP
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Wed Jun 18 16:20:20 2014 a
** Last update Sun Jun 22 21:32:16 2014 a
*/
#include <unistd.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      i++;
    }
  return (i);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (write(2, str, i));
}

void	my_putnbr(int nb)
{
  int	o;

  o = nb % 10 + 48;
  if (nb / 10 > 0)
    my_putnbr(nb / 10);
  write(1, &o, 1);
}
