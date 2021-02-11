/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_raycaster.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:29:18 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/11 16:29:37 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

static void	ft_apply_direction(t_ray *ray, char start_char)
{
	if (start_char == 'N')
	{
		ray->direction->x = -ray->fov;
		ray->plane->y = ray->fov;
	}
	else if (start_char == 'S')
	{
		ray->direction->x = ray->fov;
		ray->plane->y = -ray->fov;
	}
	else if (start_char == 'E')
	{
		ray->direction->y = ray->fov;
		ray->plane->x = ray->fov;
	}
	else if (start_char == 'W')
	{
		ray->direction->y = -ray->fov;
		ray->plane->x = -ray->fov;
	}
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
	ray->pos = ft_new_point(map->player_x + 0.5, map->player_y + 0.5);
	ray->in_map = ft_new_point(0, 0);
	ray->hit = 0;
	ray->side = 0;
	ray->perp_wall_dist = 0;
	ray->fov = M_PI / 4;
	ray->plane = ft_new_point(0, 0);
	ray->direction = ft_new_point(0, 0);
	ft_apply_direction(ray, ray->map[map->player_x][map->player_y]);
	ray->ray_dir = ft_new_point(0, 0);
	ray->delta_dist = ft_new_point(0, 0);
	ray->side_dist = ft_new_point(0, 0);
	ray->step = ft_new_point(0, 0);
	ray->line = ft_new_line(0, 0, 0, 0);
	ray->camera_x = 0;
	map->map_str_tab[map->player_x][map->player_y] = '0';
	return (ray);
}
