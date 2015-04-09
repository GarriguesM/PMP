/*
** paint.h for  in /home/garrig_b/PMP
** 
** Made by a
** Login   <garrig_b@epitech.net>
** 
** Started on  Wed Jun 18 15:00:46 2014 a
** Last update Sun Jun 22 22:07:10 2014 a
*/

#include <math.h>
#include <string.h>

#ifndef _PAINT_H_
# define _PAINT_H_

int		g_color_full;
int		g_brain;
int		g_empty;
int		g_size;

typedef struct		s_cntr
{
  int			x1;
  int			x2;
  int			y1;
  int			y2;
}			t_cntr;

typedef struct		s_mlx
{
  void			*win;
  void			*img;
  void			*xpm;
  char			*data;
  char			*data_xpm;
  int			bpp;
  int			sizeline;
  int			endian;
}			t_mlx;

typedef struct		s_env
{
  void                  *mlx;
  struct s_mlx		*presentation;
  struct s_mlx		*init;
  struct s_mlx		*colors;
  struct s_mlx		*tools;
}			t_env;

void		my_brain(int x, int y, t_env *env);
void		rubber(t_env  *env, int x, int y);
void		pencil_brain(int x, int y, t_env *env);
void		trace_pencil(int x, int y, t_env *env, int diam);
void		my_dot(t_env *env, int diam, int x, int y);
void		triangle_2(t_env *env, int x, int y, int taille);
void		triangle(t_env *env, int x, int y, int taille);
void		draw_triangle_2(t_env *env, t_cntr *r, int taille);
void		draw_triangle_1(t_env *env, t_cntr * r, int taille);
void		main_segment(t_env *env, int xy[4]);
void		trace_medium_segment(t_env *env, int xy[4]);
void		trace_large_segment(t_env *env, int xy[4]);
void		my_clear(t_env *env);
void		activation(t_env *env);
void		im_not_full(t_env *env);
void		im_full(t_env *env);
void		my_putnbr(int nb);
int		my_strlen(char *str);
char		*mlx_get_data_addr (void *, int *, int *, int *);
int		my_putstr(char *);
void		triangle_init(t_env *env);
int		gere_expose_2(t_env *env);
int		gere_mouse(int buttons, int x, int y, t_env *env);
int		gere_mouse_2(int buttons, int x, int y, t_env  *env);
int		gere_mouse_3(int buttons, int x, int y, t_env  *env);
void		presentation(t_env *env);
void		presentation_0(t_env *env);
int		mlx_pixel_put(void *mlx_ptr, void
			      *win_ptr, int x, int y, int color);
int		mlx_string_put(void *mlx_ptr, void
			       *win_ptr, int x, int y, int color, char *string);
t_env		*connection();
int		gere_expose(t_env *env);
int		gere_expose_2(t_env *env);
int		gere_expose_3(t_env *env);
int		gere_expose_4(t_env *env);
int		gere_key(int keycode, t_env *env);
void		mlx_pixel_to_img(int x, int y, t_env *env, int color);
void		mlx_pixel_to_img_2(int x, int y, t_env *env, int color);
char		*mlx_get_data_addr (void *, int *, int *, int *);
size_t		strlcpy(char *dst, const char *src, size_t size);
void		tools(t_env *env);
t_mlx		*xpm_tools(char *str, void *mlx);
void		main_rectangle(int x ,int y, t_env *env);
void		main_rectangle_contour(int x, int y, t_env *env);
void		colors_palette(t_env *env);
void		colors_main(t_env  *env);
void		rectangle(t_env  *env, int x, int y, int taille);
void		rectangle_contour(t_env *env, int x, int y, int taille);
void		im_rectangle(t_env *env);
void		brain_square(int x, int y, t_env  *env);
void		main_triangle(int x, int y, t_env *env);
void		main_triangle_contour(int x, int y, t_env *env);
t_mlx		*new_windows(char *str, int x, int y, void *mlx);
void		pencil(t_env *env);
void		im_circle(t_env *env);
void		main_circle(int x, int y, t_env *env);
void		main_full_circle(int x, int y, t_env *env);
void		brain_circle(int x, int y, t_env *env);
void		im_triangle(t_env *env);
void		triangle_0(t_env *env, int x, int y, int taille);

# define DEATH 2
# define PMP_Y 200
# define PMP_X 600
# define DIAM 50
# define CL_X 40
# define CL_Y 120
# define BLUE 0x00357AB7
# define PURPLE 0x00663399
# define PINK 0x00D87093
# define SQUARE 1
# define TRIANGLE 3
# define WRITE 2
# define CIRCLE 5
# define SPACE 32
# define CLEAR 99
# define NORMAL 65436
# define MEDIUM 65433
# define LARGE 65435
# define RUBBER 32
# define PENCIL 45
# define ZERO 0
# define FULL 1
# define ABSCIS(x) (((x) < 0) ? -(x) : (x))

#endif /* !PAINT_H_ © */
