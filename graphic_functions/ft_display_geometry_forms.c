/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_geometry_forms.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:50:54 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/29 14:37:18 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"
#include "../include/ft_geometry_forms.h"

void	ft_draw_square(t_square *square, t_graph *graph, int trgb)
{
	double x;
	double y;

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

void	ft_draw_line(t_line *line, t_graph *graph, int trgb)
{
	double x;
	double y;

	x = line->a_x;
	y = line->a_y;
	if (x < line->b_x)
	{
		while (x <= line->b_x)
		{
			while (y != line->b_y)
			{
				my_mlx_pixel_put(graph->img_ptr, x, y, trgb);
				y += line->delta;
				break ;
			}
			x++;
		}
	}
	else
	{
		while (x >= line->b_x)
		{
			while (y != line->b_y)
			{
				my_mlx_pixel_put(graph->img_ptr, x, y, trgb);
				y -= line->delta;
				break ;
			}
			x--;
		}
	}
}
