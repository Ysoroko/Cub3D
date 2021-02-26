/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor_and_ceiling_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:08:20 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/26 11:06:51 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

/*
** This function is used to setup all the variables to start drawing
*/

static void	ft_setup(t_ray *ray, int y)
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
** This function is used to calculate everything needed to draw the floor and
** the ceiling
*/

static void	ft_launch(t_ray *ray, int x, int y)
{
	int		color;
	t_image	*f_texture;
	t_image	*c_texture;

	color = 0;
	f_texture = ray->floor_texture;
	c_texture = ray->ceiling_texture;
	ray->cell->x = (int)(ray->floor->x);
	ray->cell->y = (int)(ray->floor->y);
	ray->tex->x = (int)(ray->texture_width *
		(ray->floor->x - ray->cell->x)) & (ray->texture_width - 1);
	ray->tex->y = (int)(ray->texture_height *
		(ray->floor->y - ray->cell->y)) & (ray->texture_height - 1);
	ray->floor->x += ray->floor_step->x;
	ray->floor->y += ray->floor_step->y;
	if (y > ray->res->y / 2)
	{
		my_mlx_pixel_get(f_texture, ray->tex->x, ray->tex->y, &(color));
		ft_apply_shadow_to_floor(y, ray->res->y, &color);
		my_mlx_pixel_put(ray->graph->img_ptr, x, y, color);
	}
}

static void	ft_draw_skybox(t_ray *ray)
{
	int		x;
	int		y;
	int		color;
	t_image *texture;

	x = -1;
	texture = ray->ceiling_texture;
	while (x++ < ray->res->x)
	{
		y = -1;
		while (y++ < ray->res->y / 2)
		{
			my_mlx_pixel_get(texture,
				x % SKY_W, y % SKY_H, &(color));
			my_mlx_pixel_put(ray->graph->img_ptr, x, y, color);
		}
	}
}

/*
** FT_FLOOR_AND_CEILING_RAYCASTING
** This is the central hub of functions responsible for the raycasting
** of the floor and the ceiling
*/

void		ft_floor_and_ceiling_raycasting(t_ray *ray)
{
	int		y;
	int		x;

	y = -1;
	x = -1;
	ft_draw_skybox(ray);
	while (++y < ray->res->y)
	{
		ft_setup(ray, y);
		x = -1;
		while (++x < ray->res->x - 1)
			ft_launch(ray, x, y);
	}
}
