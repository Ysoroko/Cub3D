/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:22:26 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/28 16:03:20 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GRAPHICS_H
# define FT_GRAPHICS_H

#include "../include/ft_map_functions.h"
#include "../minilibx/mlx.h"

typedef struct		s_graph
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*f_ptr;
	int		f_trgb;
	int		c_trgb;
	void	*param;
}					t_graph;

typedef struct  s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct  s_point {
	int		x;
	int		y;
}				t_point;

/*
** FT_FREE_AND_NEW_FUNCTIONS
*/

t_graph	*ft_new_t_graph(t_map *map);
t_graph	*ft_free_t_graph(t_graph *graph);
t_image	*ft_new_t_image(void);
t_image	*ft_free_t_image(t_image *image);

/*
** FT_WINDOW_START
*/

t_graph	*ft_window_start(t_map *map);

/*
** FT_RGB_TO_TRGB
*/

int		ft_rgb_to_trgb(int t, int r, int g, int b);

/*
** FT_IMAGE_FUNCTIONS
*/

t_image	*ft_image(void *mlx_ptr, int width, int height);
void	my_mlx_pixel_put(t_image *image, int x, int y, int color);
t_image	*ft_pixel_on_screen(t_graph *graph,
							t_map *map, t_point *pnt, int trgb);

#endif