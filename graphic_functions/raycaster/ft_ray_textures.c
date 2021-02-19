/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:40:03 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/19 16:13:47 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

/*
** FT_DETERMINE_TEXTURE
** This function is used to determine the texture based on the players's
** direction
*/

static void	ft_determine_texture(t_ray *ray, t_image **text)
{
	if (ray->in_map->y - ray->pos->y > 0 && ray->side == 1)
		*text = ray->east_texture;
	else if (ray->in_map->y - ray->pos->y <= 0 && ray->side == 1)
		*text = ray->west_texture;
	else if (ray->in_map->x - ray->pos->x > 0 && ray->side == 0)
		*text = ray->south_texture;
	else if (ray->in_map->x - ray->pos->x <= 0 && ray->side == 0)
		*text = ray->north_texture;
}

/*
** FT_SETUP
** All the setup needed before the "while (y) loop is done here"
*/

static void	ft_setup(t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_x = ray->pos->y + ray->perp_wall_dist * ray->ray_dir->y;
	else
		ray->wall_x = ray->pos->x + ray->perp_wall_dist * ray->ray_dir->x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)(ray->texture_width));
	if ((ray->side == 0 && ray->ray_dir->x > 0) ||
						(ray->side == 1 && ray->ray_dir->y < 0))
		ray->tex_x = ray->texture_width - ray->tex_x - 1;
	ray->tex_step = ray->texture_height / ray->line->len;
	ray->tex_pos = (ray->line->a_y - ray->graph->res_height
									/ 2 + ray->line->len / 2) * ray->tex_step;
}

/*
** FT_TEXTURES
** Does all the calculations related to the textures and draws them on screen
*/

void		ft_textures(t_ray *ray, int x)
{
	int		y;
	int		color;
	t_image *text;

	y = (int)ray->line->a_y;
	ft_setup(ray);
	while (y++ < (int)ray->line->b_y)
	{
		ray->tex_y = (int)ray->tex_pos & (ray->texture_height - 1);
		ray->tex_pos += ray->tex_step;
		ft_determine_texture(ray, &text);
		my_mlx_pixel_get(text, ray->tex_x, ray->tex_y, &(color));
		if (ray->perp_wall_dist > TEXTURE_SHADOW_RANGE)
			color = -color;
		my_mlx_pixel_put(ray->graph->img_ptr, x, y, color);
	}
}
