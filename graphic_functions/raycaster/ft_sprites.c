/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:34:55 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/22 17:17:30 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

/*
** FT_SORT
** This function is used to sort the seen sprites based on the distance
** The furthest sprites are put first so that they are drawn first
** The array component of t_sprite_ray which is sorted is sprite_order
*/

/*
static void	ft_sort(int *spr_order, double *spr_dist, int n_spr)
{
	return ;
}
*/

/*
** FT_SETUP_ORDER_AND_DISTANCE
** This function fills in the sprite_order array,
** calculates the distance to each sprite and calls ft_sort
** function to sort the order based on the distance
*/

static void	ft_setup_order_and_distance(t_ray *ray, t_sprite_ray *s_ray)
{
	int	i;

	i = -1;
	while (++i < s_ray->num_sprites)
	{
		s_ray->sprite_order[i] = i;
		s_ray->sprite_distance[i] = (ray->pos->x - s_ray->sprite_array[i]->x)
				* (ray->pos->x - s_ray->sprite_array[i]->x) +
				(ray->pos->y - s_ray->sprite_array[i]->y)
				* (ray->pos->y - s_ray->sprite_array[i]->y);
	}
	//ft_sort(s_ray->sprite_order, s_ray->sprite_distance, s_ray->num_sprites);
}

/*
** FT_CALCULATE
** This function is used to setup the variables before drawing
** It translates the sprite position to relative to camera first,
** uses a 2x2 matrix to apply the 3d effect (rotate them to be always facing
** the player)
*/

static void	ft_calculate(t_ray *ray, t_sprite_ray *s_ray, int i)
{
	s_ray->spr->x = (s_ray->sprite_array[s_ray->sprite_order[i]])->x -
				ray->pos->x;
	s_ray->spr->y = (s_ray->sprite_array[s_ray->sprite_order[i]])->y -
				ray->pos->y;
	s_ray->inv_det = 1 / (ray->plane->x * ray->direction->y -
							ray->plane->y * ray->direction->x);
	s_ray->transform->x = s_ray->inv_det * (ray->direction->y *
			s_ray->spr->x - ray->direction->x * s_ray->spr->x);
	s_ray->transform->y = s_ray->inv_det * (-ray->plane->y *
			s_ray->spr->x + ray->plane->x * s_ray->spr->y);
	s_ray->sprite_screen_x = (int)((ray->res->x / 2) *
						(1 + s_ray->transform->x / s_ray->transform->y));
	s_ray->sprite_height = abs((int)(ray->res->y / s_ray->transform->x));
	s_ray->draw_start->y = -s_ray->sprite_height / 2 + ray->res->y / 2;
	s_ray->draw_end->y = s_ray->sprite_height / 2 + ray->res->y / 2;
	s_ray->draw_start->x = -s_ray->sprite_width / 2 + s_ray->sprite_screen_x;
	s_ray->draw_end->x = s_ray->sprite_width / 2 + s_ray->sprite_screen_x;
	ft_limit_points_within_map(&(s_ray->draw_start->x),
						&(s_ray->draw_start->y), ray->graph);
	ft_limit_points_within_map(&(s_ray->draw_end->x),
						&(s_ray->draw_end->y), ray->graph);
	printf("going to draw now \n");
}

static void	ft_draw(t_sprite_ray *s_ray, t_ray *ray)
{
	int	i;
	int	j;
	int	d;
	int	trgb;

	i = s_ray->draw_start->x - 1;
	while (++i < s_ray->draw_end->x)
	{
		s_ray->tex->x = (int)(256 * (i - (-s_ray->sprite_width / 2
				+ s_ray->sprite_screen_x)) * s_ray->tex->x /
				s_ray->sprite_width) / 256;
		if (s_ray->transform->y > 0 && i > 0 && i < ray->res->x
							&& s_ray->transform->y < s_ray->z_buffer[i])
		{
			j = s_ray->draw_start->y - 1;
			while (++j < s_ray->draw_end->y)
			{
				d = j * 256 - ray->res->y * 128 + s_ray->sprite_height * 128;
				s_ray->tex->y = ((d * s_ray->texture_size->y) /
												s_ray->sprite_height) / 256;
				my_mlx_pixel_get(ray->sprite_texture,
									s_ray->tex->x, s_ray->tex->y, &trgb);
				if ((trgb & 0x00FFFFFF) != 0)
					my_mlx_pixel_put(ray->graph->img_ptr, i, j, trgb);
			}
			printf("here\n");
		}
	}
}

void		ft_sprites_raycaster(t_ray *ray, t_sprite_ray *s_ray, int x)
{
	int	i;

	i = 0;
	s_ray->z_buffer[x] = ray->perp_wall_dist;
	ft_setup_order_and_distance(ray, s_ray);
	printf("setup ok \n");
	while (i++ < s_ray->num_sprites)
	{
		ft_calculate(ray, s_ray, i);
		printf("calculate ok \n");
		ft_draw(s_ray, ray);
		printf("draw ok \n");
	}
}
