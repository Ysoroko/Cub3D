/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_raycaster_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 10:48:13 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/26 11:58:45 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

void	ft_initialize_bonus_sprites(t_ray *ray, t_map *map)
{
	ray->floor_texture = ft_image_from_file(ray->graph->mlx_ptr,
		map->res_width, map->res_height, FLOOR_XPM_PATH);
	ray->sprite_two_texture = ft_image_from_file(ray->graph->mlx_ptr,
		map->res_width, map->res_height, SECOND_SPRITE_XPM_PATH);
	ray->heart_texture = ft_image_from_file(ray->graph->mlx_ptr,
		map->res_width, map->res_height, HEART_XPM_PATH);
	ray->gun_texture[0] = ft_image_from_file(ray->graph->mlx_ptr,
		map->res_width, map->res_height, GUN1_XPM_PATH);
	ray->gun_texture[1] = ft_image_from_file(ray->graph->mlx_ptr,
		map->res_width, map->res_height, GUN2_XPM_PATH);
	ray->ceiling_texture = ft_image_from_file(ray->graph->mlx_ptr,
		map->res_width, map->res_height, SKYBOX_ONE_XPM_PATH);
	ray->enemy_texture = ft_image_from_file(ray->graph->mlx_ptr,
		map->res_width, map->res_height, ENEMY_SPRITE_XPM_PATH);
}
