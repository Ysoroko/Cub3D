/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_filled_in_forms.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:55:07 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/02 14:00:27 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"
#include "../include/ft_geometry_forms.h"

/*
** Draws the specified square with the specified colour
*/

void	ft_draw_fsquare(t_square *square, t_graph *graph, int trgb)
{
	double	x;
	double	y;

	x = square->x;
	y = square->y;
	while (x < square->x + square->width)
	{
		y = square->y;
		while (y < square->y + square->height)
		{
			my_mlx_pixel_put(graph->img_ptr, x, y, trgb);
			y++;
		}
		x++;
	}
}

/*
** Draws the specified circle with the specified colour
*/

void	ft_draw_fcircle(t_circle *circle, t_graph *graph, int trgb)
{
	double	radius;
	double	i;
	double	j;
	double	dist;
	double	prox;

	prox = 0;
	radius = circle->radius;
	i = circle->x - circle->radius - prox;
	j = circle->y - circle->radius - prox;
	dist = 0;

	while (i <= circle->x + radius + prox)
	{
		j = circle->y - circle->radius - prox;
		while (j++ <= circle->y + radius + prox)
		{
			dist = sqrt(((i - circle->x) * (i - circle->x))
					+ ((j - circle->y) * (j - circle->y)));
			if (dist >= 0 && dist < (radius + prox))
				my_mlx_pixel_put(graph->img_ptr, i, j, trgb);
		}
		i++;
	}
}
