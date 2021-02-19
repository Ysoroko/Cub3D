/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor_and_ceiling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:08:20 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/19 13:57:50 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

/*
** This function is used to setup everything drawn in the "while (y)" loop
*/

static void	ft_y_loop(t_ray *ray, int y)
{
	ray->ray_dir_0->x = ray->direction->x - ray->plane->x;
	ray->ray_dir_0->y = ray->direction->y - ray->plane->y;
	ray->ray_dir_1->x = ray->direction->x + ray->plane->x;
	ray->ray_dir_1->y = ray->direction->y + ray->plane->y;
	ray->p = y - ray->res->y / 2;
	ray->pos_z = ray->res->y / 2;
	ray->row_distance = ray->pos_z / ray->p;
	ray->floor_step->x = ray->row_distance *
				(ray->ray_dir_1->x - ray->ray_dir_0->x) / ray->res->x;
	ray->floor_step->y = ray->row_distance *
				(ray->ray_dir_1->y - ray->ray_dir_0->y) / ray->res->x;
	ray->floor->x = ray->pos->x + ray->row_distance * ray->ray_dir_0->x;
	ray->floor->y = ray->pos->y + ray->row_distance * ray->ray_dir_0->y;
}

/*
** This function is used to setup everything drawn in the "while (x)" loop
*/

static void	ft_x_loop(t_ray *ray, int x, int y)
{
	int		color;
	t_image	*f_texture;
	t_image	*c_texture;

	color = 0;
	f_texture = ray->floor_texture;
	c_texture = ray->ceiling_texture;
	ray->cell->x = (int)(ray->floor->x);
	ray->cell->y = (int)(ray->floor->y);
	ray->tex->x = (int)((double)ray->texture_width *
		(ray->floor->x - ray->cell->x)) & (ray->texture_width - 1);
	ray->tex->y = (int)((double)ray->texture_height *
		(ray->floor->y - ray->cell->y)) & (ray->texture_height - 1);
	ray->floor->x += ray->floor_step->x;
	ray->floor->y += ray->floor_step->y;
	//printf("ALL GOOD HERE\n");
	//printf("ray->tex->x: [%f]\n ray->tex->y: [%f]\n", ray->tex->x, ray->tex->y);
	my_mlx_pixel_get(c_texture, ray->tex->x, ray->tex->y, &(color));
	my_mlx_pixel_put(ray->graph->img_ptr, x, y, color);
	my_mlx_pixel_get(f_texture, ray->tex->x, ray->tex->y, &(color));
	my_mlx_pixel_put(ray->graph->img_ptr, x, ray->res->y - y - 1, color);
}

/*
** FT_FLOOR_AND_CEILING_RAYCASTING
** This is the central hub of functions responsible for the raycasting
** of the floor and the ceiling
*/

void		ft_floor_and_ceiling_raycasting(t_ray *ray, int x)
{
	int		y;

	y = 0;
	while (++y < ray->res->y / 2)
	{
		ft_y_loop(ray, y);
		ft_x_loop(ray, x, y);
	}
}
