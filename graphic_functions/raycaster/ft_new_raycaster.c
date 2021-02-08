/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_raycaster.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:29:18 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/08 17:55:28 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_raycaster.h"

static void	ft_apply_direction(t_point *direction, char start_char)
{
	if (start_char == 'N')
		direction->y = -1;
	else if (start_char == 'S')
		direction->y = 1;
	else if (start_char == 'E')
		direction->x = 1;
	else if (start_char == 'W')
		direction->x = -1;
}

t_ray		*ft_new_raycaster(t_graph *graph, t_map *map)
{
	t_ray	*ray;
	double	x_dir;
	double	y_dir;

	if (!(ray = malloc(sizeof(*ray))))
		ft_malloc_fail();
	ray->graph = graph;
	ray->map = map->map_str_tab;
	ray->map_height = ft_str_tab_len(ray->map);
	ray->map_width = ft_strlen(ray->map[0]);
	ray->res_h = map->res_height;
	ray->res_w = map->res_width;
	ray->start_x = map->player_y;
	ray->start_y = map->player_x;
	ray->fov = 2 * atan(0.66 / 1);
	ray->start_char = ray->map[map->player_y][map->player_x];
	ray->direction = ft_new_point(0, 0);
	ft_apply_direction(ray->direction, ray->start_char);
	ray->plane_x = 0;
	ray->plane_y = 0.66;
	return (ray);
}
