/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_raycaster.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:29:18 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/23 11:02:18 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

/*
** FT_APPLY_DIRECTION
** This function is used to change the starting player's direction based
** on the related char in the map (N/S/E/W)
*/

static void	ft_apply_direction(t_ray *ray, char start_char)
{
	ray->plane = ft_new_point(0, 0);
	ray->direction = ft_new_point(0, 0);
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

/*
** FT_INITIALIZE_RAYCASTER_POINTS
** This function is used to malloc and initialize all of the t_point
** structures inside of the t_ray we are initializing here
*/

static void	ft_initialize_raycaster_points(t_ray *ray, t_map *map)
{
	ray->res = ft_new_point(map->res_width, map->res_height);
	ray->pos = ft_new_point(map->player_x + 0.5, map->player_y + 0.5);
	ray->in_map = ft_new_point(0, 0);
	ray->ray_dir = ft_new_point(0, 0);
	ray->delta_dist = ft_new_point(0, 0);
	ray->side_dist = ft_new_point(0, 0);
	ray->step = ft_new_point(0, 0);
	ray->line = ft_new_line(0, 0, 0, 0);
	ft_apply_direction(ray, ray->map[map->player_x][map->player_y]);
	ray->ray_dir_0 = ft_new_point(0, 0);
	ray->ray_dir_1 = ft_new_point(0, 0);
	ray->floor_step = ft_new_point(0, 0);
	ray->floor = ft_new_point(0, 0);
	ray->cell = ft_new_point(0, 0);
	ray->tex = ft_new_point(0, 0);
}

/*
** FT_INITIALIZE_SPRITES
** Used to extract and initialize the sprite related part of the raycaster
*/

static void	ft_initialize_raycaster_sprites(t_ray *ray, t_map *map)
{
	char *north_path;
	char *south_path;
	char *east_path;
	char *west_path;

	north_path = map->north_path;
	south_path = map->south_path;
	east_path = map->east_path;
	west_path = map->west_path;
	ray->north_texture = ft_image_from_file(ray->graph->mlx_ptr,
					map->res_width, map->res_height, north_path);
	ray->south_texture = ft_image_from_file(ray->graph->mlx_ptr,
					map->res_width, map->res_height, south_path);
	ray->east_texture = ft_image_from_file(ray->graph->mlx_ptr,
					map->res_width, map->res_height, east_path);
	ray->west_texture = ft_image_from_file(ray->graph->mlx_ptr,
					map->res_width, map->res_height, west_path);
	if (BONUS == 1)
	{
		ray->floor_texture = ft_image_from_file(ray->graph->mlx_ptr,
			map->res_width, map->res_height, "./images/floor2.xpm");
		ray->ceiling_texture = ft_image_from_file(ray->graph->mlx_ptr,
			map->res_width, map->res_height, "./images/night2.xpm");
	}
}

/*
** FT_INITIALIZE_RAYCASTER_NUMBERS
** This function is used to initialize all of the raycaster's numbers
*/

static void	ft_initialize_raycaster_numbers(t_ray *ray)
{
	ray->map_height = ft_str_tab_len(ray->map);
	ray->map_width = ft_strlen(ray->map[0]);
	ray->hit = 0;
	ray->side = 0;
	ray->perp_wall_dist = 0;
	ray->fov = M_PI / 4;
	ray->wall_x = 0;
	ray->tex_x = 0;
	ray->tex_y = 0;
	ray->texture_width = TEXTURE_W;
	ray->texture_height = TEXTURE_H;
	ray->sprite_width = SPRITE_W;
	ray->sprite_height = SPRITE_H;
	ray->step = 0;
	ray->tex_pos = 0;
	ray->camera_x = 0;
	ray->p = 0;
	ray->pos_z = 0;
	ray->row_distance = 0;
}

/*
** FT_NEW_RAYCASTER
** This function is the central hub of initializing the t_ray structure
** used in all of the raycasting calculations
** Several functions are used for it because of the size of the strucure
*/

t_ray		*ft_new_raycaster(t_graph *graph, t_map *map)
{
	t_ray	*ray;

	if (!(ray = malloc(sizeof(*ray))))
		ft_malloc_fail();
	ray->graph = graph;
	ray->map = map->map_str_tab;
	ft_initialize_raycaster_numbers(ray);
	ft_initialize_raycaster_points(ray, map);
	ft_initialize_raycaster_sprites(ray, map);
	map->map_str_tab[map->player_x][map->player_y] = '0';
	//FT_NEW_SPRITE_RAY SEGFAULTS!!!
	ray->sprite_ray = ft_new_sprite_ray(ray->map, ray);
	return (ray);
}
