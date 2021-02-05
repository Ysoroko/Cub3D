/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:22:26 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/05 16:03:53 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GRAPHICS_H
# define FT_GRAPHICS_H

#include "ft_map_functions.h"
#include "ft_geometry_forms.h"
#include "ft_params_and_colors.h"
#include "libft.h"
#include "../minilibx/mlx.h"
#include <math.h>


# define ESCAPE_KEY 53
# define RIGHT_ARROW_KEY 124
# define LEFT_ARROW_KEY 123
# define UP_ARROW_KEY 126
# define DOWN_ARROW_KEY 125

# define KEY_PRESS_EVENT 2
# define DESTROY_EVENT 17

# define KEY_PRESS_MASK 1L<<0
# define STRUCTURE_NOTIFY_MASK 1L<<17

typedef struct  s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct		s_frame
{
	t_square	*ceiling;
	t_square	*floor;
	t_square	*minimap_wall;
	t_square	*minimap_background;
	int			units;
}					t_frame;

typedef struct		s_graph
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		*img_ptr;
	t_image		*once_drawn_img;
	int			*f_ptr;
	int			f_trgb;
	int			c_trgb;
	void		*param;
	t_circle	*circle;
	t_line		*line;
	t_map		*map;
	double		move_speed;
	int			res_width;
	int			res_height;
	t_frame		*frame;
}					t_graph;

/*
** FT_NEW_STRUCTURES
*/

t_graph		*ft_new_t_graph(t_map *map);
t_image		*ft_new_t_image(void);
t_frame		*ft_new_t_frame(t_graph *graph);

/*
** FT_WINDOW_START
*/

t_graph		*ft_window_start(t_map *map);
void		ft_draw_background(t_graph *graph);
void		ft_next_frame(t_graph *graph);

/*
** FT_RGB_TO_TRGB
*/

int			ft_rgb_to_trgb(int t, int r, int g, int b);

/*
** FT_IMAGE_FUNCTIONS
*/

t_image		*ft_image(void *mlx_ptr, int width, int height);
void		my_mlx_pixel_put(t_image *image, int x, int y, int color);

/*
** FT_DRAW_EMPTY_FORMS
*/

void		ft_draw_line(t_line *line, t_image *img, int trgb);
void		ft_draw_circle(t_circle *circle, t_image *img, int trgb);
void		ft_draw_triangle(t_triangle *triangle,
								t_image *img_ptr, int trgb);

/*
** FT_DRAW_FILLED_IN_FORMS
*/

void		ft_draw_fsquare(t_square *square, t_image *img, int trgb);
void		ft_draw_fcircle(t_circle *circle, t_image *img, int trgb);

/*
** FT_NEW_GEOMETRY_FORMS
*/

t_square	*ft_new_square(double x, double y, double width, double height);
t_line		*ft_new_line(double a_x, double a_y, double angle, double len);
t_circle	*ft_new_circle(double x, double y, double radius, double prox);
t_point		*ft_new_point(double x, double y);

/*
** FT_HOOKS_FUNCTIONS
*/

int			ft_keys_binding(int keycode, t_graph *graph);
int			ft_window_closed(t_graph *graph);

/*
** FT_ERROR_UTILS
*/

void		ft_malloc_fail(void);
void		ft_mlx_fail(void);

/*
** FT_DRAW_MINIMAP
*/

void		ft_draw_minimap(t_graph *graph);

/*
** FT_MOVE_IN_MAP
*/

void		ft_move_and_collide(t_graph *graph, int direction);

#endif