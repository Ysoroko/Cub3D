/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 18:01:53 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/23 18:45:00 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

static int	ft_check_limits(t_ray *ray, int x, int y)
{
	if (ray->res->x < x || ray->res->y < y ||
		ray->res->x < 8 * HEART_WIDTH || ray->res->y < 8 * HEART_HEIGHT)
		return (1);
	return (0);
}

static void	ft_draw_heart(t_ray *ray, int hp, int units)
{
	int	trgb;
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	x = ray->res->x - (hp * 8 * units);
	y = 3 * units;
	if (ft_check_limits(ray, x, y))
		return ;
	while (++i < 8 * (HEART_WIDTH))
	{
		j = -1;
		x++;
		y = 3 * units;
		while (++j < 8 * (HEART_HEIGHT))
		{
			my_mlx_pixel_get(ray->heart_texture, i / 8, j / 8, &trgb);
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
		ft_draw_heart(ray, hp, ray->graph->frame->units);
	}
}
