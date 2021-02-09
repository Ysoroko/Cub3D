/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_raycaster.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:29:18 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/09 14:59:24 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

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

	if (!(ray = malloc(sizeof(*ray))))
		ft_malloc_fail();
	ray->graph = graph;
	ray->map = map->map_str_tab;
	ray->map_height = ft_str_tab_len(ray->map);
	ray->map_width = ft_strlen(ray->map[0]);
	ray->res = ft_new_point(map->res_width, map->res_height);
	ray->pos = ft_new_point(map->player_y, map->player_x);
	ray->in_map = ft_new_point(map->player_y, map->player_x);
	ray->hit = 0;
	ray->side = 0;
	ray->perp_wall_dist = 0;
	ray->fov = 2 * atan((M_PI / 3) / 1);
	ray->direction = ft_new_point(0, 0);
	ft_apply_direction(ray->direction, ray->map[map->player_y][map->player_x]);
	ray->plane = ft_new_point(0, M_PI / 3);
	ray->ray_dir = ft_new_point(0, 0);
	ray->delta_dist = ft_new_point(0, 0);
	ray->side_dist = ft_new_point(0, 0);
	ray->step = ft_new_point(0, 0);
	ray->line = ft_new_line(0, 0, 0, M_PI + M_PI_2);
	return (ray);
}
