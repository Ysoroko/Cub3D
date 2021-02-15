/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_vertical_line.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 12:22:58 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/15 15:49:43 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

void	ft_draw_vertical_line(int x, double a_y, double b_y, t_ray *ray)
{
	int		i;
	int		max;
	int		trgb;
	double	my_x;

	my_x = (double)x;
	ft_limit_points_within_map(&my_x, &a_y, ray->graph);
	ft_limit_points_within_map(&my_x, &b_y, ray->graph);
	i = (int)fmin(a_y, b_y);
	max = (int)fmax(a_y, b_y);
	while (i++ < max - 1)
	{
		trgb = 0x00F2BC94;
		if (ray->side == 1)
			trgb = trgb / 2;
		my_mlx_pixel_put(ray->graph->img_ptr, my_x, i, trgb);
	}
}
