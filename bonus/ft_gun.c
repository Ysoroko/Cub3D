/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gun.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:25:08 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/25 18:01:52 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

void	ft_display_gun(t_ray *ray, t_image *texture)
{
	int	trgb;
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	x = ray->res->x / 2 - GUN_W / 2;
	y = ray->res->y - GUN_H;
	if (ray->res->x < SPRITE_W || ray->res->y < SPRITE_H)
		return ;
	while (++i < (GUN_W))
	{
		j = -1;
		x += 1;
		y = ray->res->y - GUN_H;
		while (++j < (GUN_H))
		{
			my_mlx_pixel_get(texture, i, j, &trgb);
			if ((trgb & 0x00FFFFFF) != 0)
				my_mlx_pixel_put(ray->graph->img_ptr, x, y, trgb);
			y++;
		}
	}
}

void	ft_fire_gun(t_ray *ray)
{
	static int	count;
	t_image		*temp;

	temp = ray->gun_texture[0];
	ray->gun_texture[0] = ray->gun_texture[1];
	ray->gun_texture[1] = temp;
	if (count % 2)
		system("afplay bonus/knife_on.mp3 &>/dev/null &");
	else
		system("afplay bonus/knife_off.mp3 &>/dev/null &");
	count++;
	ft_next_frame(ray->graph, ray);
}
