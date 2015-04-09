##
## Makefile for  in /home/garrig_b/PMP
## 
## Made by a
## Login   <garrig_b@epitech.net>
## 
## Started on  Wed Jun 18 16:13:23 2014 a
## Last update Tue Jun 24 10:37:54 2014 a
##

CC_FreeBSD      =       gcc
CC_solaris      =       /usr/sfw/bin/gcc
CC_linux        =       gcc

CC		=	$(CC_$(OSTYPE))
INCLUDE		=	-L/usr/X11/lib -lmlx_$(HOSTTYPE) -lXext -lX11 -lm  -I.

SRC		= 	main.c		\
			aff.c		\
			square.c	\
			triangle.c	\
			triangle_2.c	\
			circle.c	\
			my_pixel.c	\
			palette.c	\
			presentation.c	\
			gere_expose.c   \
			tools.c		\
			strlcpy.c	\
			segment.c	\
			clear.c		\
			brain.c		\
			segment_2.c	\
			brain_square.c	\

NAME		=	pmp
RM		=	rm -f
OBJ		=	$(SRC:.c=.o)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(INCLUDE)
	@(clear)
	@(cat presentation)
	@(./$(NAME))


all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

me: all clean

.PHONY: all clean fclean re

