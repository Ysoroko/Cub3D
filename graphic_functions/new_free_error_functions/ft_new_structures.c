/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_structures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:32:57 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/12 16:26:15 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

static	void	ft_set_resolution(int *res_w, int *res_h, void *mlx, t_map *m)
{
	int	screen_width;
	int	screen_height;

	mlx_get_screen_size(mlx, &screen_width, &screen_height);
	*res_w = fmin(m->res_width, screen_width);
	*res_h = fmin(m->res_height, screen_height);
}

t_graph	*ft_new_t_graph(t_map *map)
{
	t_graph	*ret;

	if (!(ret = malloc(sizeof(t_graph))))
		ft_malloc_fail();
	if (!(ret->mlx_ptr = mlx_init()))
		ft_mlx_fail();
	if (!(ret->win_ptr = mlx_new_window(ret->mlx_ptr,
		map->res_width, map->res_height, "cub3d")))
		ft_mlx_fail();
	ret->map = map;
	ret->f_ptr = 0;
	ret->param = 0;
	ret->move_speed = WALKING_SPEED;
	ret->f_trgb = ft_rgb_to_trgb(0, map->f_red, map->f_green, map->f_blue);
	ret->c_trgb = ft_rgb_to_trgb(0, map->c_red, map->c_green, map->c_blue);
	ret->circle = 0;
	ret->line = 0;
	ft_set_resolution(&ret->res_width, &ret->res_height, ret->mlx_ptr, map);
	ret->img_ptr = ft_image(ret->mlx_ptr,
		map->res_width, map->res_height);
	ret->frame = ft_new_t_frame(ret);
	ret->once_drawn_img = ft_image(ret->mlx_ptr,
		ft_strlen(map->map_str_tab[0]) * ret->frame->units,
		ft_str_tab_len(map->map_str_tab) * ret->frame->units);
	return (ret);
}

t_image	*ft_new_t_image(void)
{
	t_image	*ret;

	ret = 0;
	if (!(ret = malloc(sizeof(t_image))))
		ft_malloc_fail();
	ret->img = 0;
	ret->addr = 0;
	ret->bits_per_pixel = 0;
	ret->line_length = 0;
	ret->endian = 0;
	return (ret);
}

t_frame	*ft_new_t_frame(t_graph *graph)
{
	t_frame	*ret;

	if (!(ret = malloc(sizeof(t_frame))))
		ft_malloc_fail();
	ret->units = fmin(graph->map->res_width, graph->map->res_height)
						/ MAX_RATIO /
					fmax(ft_strlen(graph->map->map_str_tab[0]),
						ft_str_tab_len(graph->map->map_str_tab));
	if (ret->units < 1)
		ret->units = 1;
	ret->ceiling = ft_new_square(0, 0, graph->res_width, graph->res_height / 2);
	ret->floor = ft_new_square(0, graph->res_height / 2,
								graph->res_width, graph->res_height / 2);
	ret->minimap_background = ft_new_square(0, 0,
		ft_strlen(graph->map->map_str_tab[0]) * ret->units,
		ft_str_tab_len(graph->map->map_str_tab) * ret->units);
	ret->minimap_wall = ft_new_square(0, 0, ret->units, ret->units);
	ret->player_direction = graph->map->map_str_tab[graph->map->player_x]
							[graph->map->player_y];
	return (ret);
}
