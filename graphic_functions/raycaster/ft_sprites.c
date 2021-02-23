/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:34:55 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/23 13:45:13 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

/*
** FT_SORT
** This function is used to sort the seen sprites based on the distance
** The furthest sprites are put first so that they are drawn first
** The array component of t_sprite_ray which is sorted is sprite_order
*/

static void	ft_sort(int *spr_order, double *spr_dist, int n_spr)
{
	int		i;
	int		j;
	double	d_temp;
	int		i_temp;

	i = -1;
	while (++i < n_spr)
	{
		j = -1;
		while (++j < (n_spr - 1))
		{
			if (spr_dist[j] < spr_dist[j + 1])
			{
				d_temp = spr_dist[j];
				spr_dist[j] = spr_dist[j + 1];
				spr_dist[j + 1] = d_temp;
				i_temp = spr_order[j];
				spr_order[j] = spr_order[j + 1];
				spr_order[j + 1] = i_temp;
			}
		}
	}
}

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
	ft_sort(s_ray->sprite_order, s_ray->sprite_distance, s_ray->num_sprites);
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
	s_ray->inv_det = 1.0 / (ray->plane->x * ray->direction->y -
							ray->plane->y * ray->direction->x);
	s_ray->transform->x = s_ray->inv_det * (ray->direction->y *
			s_ray->spr->x - ray->direction->x * s_ray->spr->y);
	s_ray->transform->y = s_ray->inv_det * (-ray->plane->y *
			s_ray->spr->x + ray->plane->x * s_ray->spr->y);
	s_ray->sprite_screen_x = (int)((ray->res->x / 2) *
						(1 + s_ray->transform->x / s_ray->transform->y));
	s_ray->sprite_height = abs((int)(ray->res->y / s_ray->transform->y));
	s_ray->draw_start->y = -s_ray->sprite_height / 2 + ray->res->y / 2;
	s_ray->draw_end->y = s_ray->sprite_height / 2 + ray->res->y / 2;
	s_ray->sprite_width = abs((int)(ray->res->y / s_ray->transform->y));
	s_ray->draw_start->x = -s_ray->sprite_width / 2 + s_ray->sprite_screen_x;
	s_ray->draw_end->x = s_ray->sprite_width / 2 + s_ray->sprite_screen_x;
	ft_limit_points_within_map(&(s_ray->draw_start->x),
						&(s_ray->draw_start->y), ray->graph);
	ft_limit_points_within_map(&(s_ray->draw_end->x),
						&(s_ray->draw_end->y), ray->graph);
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
				+ s_ray->sprite_screen_x)) * s_ray->texture_size->x /
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
		}
	}
}

/*
** FT_PRINT_S_RAY
** A debugging function used for printing the s_ray structure
** at a given moment
**
** static void ft_print_s_ray(t_sprite_ray *s_ray)
** {
**	int i;
**
**	i = -1;
**	printf("Number of sprites: [%d]\n", s_ray->num_sprites);
**	while (++i < s_ray->num_sprites)
**	{
**		printf("Sprite [%d]: x:[%d] y:[%d] texture:[%c]\n", i,
**			s_ray->sprite_array[i]->x, s_ray->sprite_array[i]->y,
**			s_ray->sprite_array[i]->texture_sprite);
**	}
**	i = 0;
**	while (++i < s_ray->num_sprites)
**		printf("Z_buffer [%d]: [%f]\n", i, s_ray->z_buffer[i]);
**	while (++i < s_ray->num_sprites)
**		printf("Sprite_order [%d]: [%d]\n", i, s_ray->sprite_order[i]);
**	while (++i < s_ray->num_sprites)
**		printf("Sprite_distance: [%d]: [%f]\n", i, s_ray->sprite_distance[i]);
**	printf("Inv_det: [%f]\n", s_ray->inv_det);
**	printf("Sprite_screen_x: [%d]\n", s_ray->sprite_screen_x);
**	printf("Sprite_width: [%d]\n", s_ray->sprite_width);
**	printf("Sprite_height: [%d]\n", s_ray->sprite_height);
**	printf("spr x:[%f] y: [%f]\n", s_ray->spr->x, s_ray->spr->y);
**	printf("transform x:[%f] y: [%f]\n", s_ray->transform->x,
**								s_ray->transform->y);
**	printf("draw-start x:[%f] y: [%f]\n", s_ray->draw_start->x,
**								s_ray->draw_start->y);
**	printf("draw_end x:[%f] y: [%f]\n", s_ray->draw_end->x,
**										s_ray->draw_end->y);
**	printf("tex x:[%f] y: [%f]\n", s_ray->tex->x, s_ray->tex->y);
**	printf("texture_size x:[%f] y: [%f]\n", s_ray->texture_size->x,
**									s_ray->texture_size->y);
** }
*/

void		ft_sprites_raycaster(t_ray *ray, t_sprite_ray *s_ray)
{
	int	i;

	i = -1;
	ft_setup_order_and_distance(ray, s_ray);
	while (++i < s_ray->num_sprites)
	{
		ft_calculate(ray, s_ray, i);
		ft_draw(s_ray, ray);
	}
}
