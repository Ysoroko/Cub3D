/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 18:01:53 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/25 15:59:10 by ysoroko          ###   ########.fr       */
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
	y = ray->res->y / 34;
	if (ray->res->x < HEART_WIDTH || ray->res->y < HEART_HEIGHT)
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
