/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 18:01:53 by ysoroko           #+#    #+#             */
/*   Updated: 2021/03/01 10:51:28 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

static void	ft_draw_heart(t_ray *ray, int hp)
{
	int	trgb;
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	x = ray->res->x - (hp * (ray->res->x / 14));
	if (ray->res->x <= HEART_WIDTH || ray->res->y <= HEART_HEIGHT)
		return ;
	while (++i < (ray->res->x / 180) * (HEART_WIDTH))
	{
		j = -1;
		x += 1;
		y = ray->res->y / 34;
		while (++j < (ray->res->y / 101) * (HEART_HEIGHT))
		{
			my_mlx_pixel_get(ray->heart_texture, i / (ray->res->x / 180),
								j / (ray->res->y / 101), &trgb);
			if ((trgb & 0x00FFFFFF) != 0)
				my_mlx_pixel_put(ray->graph->img_ptr, x, y, trgb);
			y++;
		}
	}
}

void		ft_draw_hud(t_ray *ray)
{
	int	hp;

	hp = ray->health + 1;
	while (--hp > 0)
	{
		ft_draw_heart(ray, hp);
	}
}

/*
** FT_REPOSITION_LINE
** This function recalculates the new position of the line every call
** Saves the changes inside the *line structure
*/

void		ft_reposition_line(t_ray *ray, t_circle *cir, double a, t_line *l)
{
	double	units;
	char	**map;
	double	distance_to_wall;

	map = ray->graph->map->map_str_tab;
	units = ray->graph->frame->units;
	distance_to_wall = ray->graph->frame->units * 1.5;
	ray->graph->circle->x = ray->pos->y *
		ray->graph->frame->units + ray->graph->frame->units;
	ray->graph->circle->y = ray->pos->x *
		ray->graph->frame->units + ray->graph->frame->units;
	l->a_x = cir->x;
	l->a_y = cir->y;
	l->b_x = l->a_x + distance_to_wall * cos(a);
	l->b_y = l->a_y + distance_to_wall * sin(a);
	l->angle = a;
	if (l->a_x < l->b_x)
		l->delta = (l->a_y - l->b_y) / (l->a_x - l->b_x);
	else
		l->delta = (l->b_y - l->a_y) / (l->b_x - l->a_x);
}
