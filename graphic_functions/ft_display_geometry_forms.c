/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_geometry_forms.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:50:54 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/01 14:55:20 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"
#include "../include/ft_geometry_forms.h"

void	ft_draw_square(t_square *square, t_graph *graph, int trgb)
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

void	ft_draw_line(t_line *line, t_graph *graph, int trgb)
{
	if (line->a_x < line->b_x)
	{
		while (line->a_x++ <= line->b_x)
		{
			while (line->a_y != line->b_y)
			{
				my_mlx_pixel_put(graph->img_ptr, line->a_x, line->a_y, trgb);
				line->a_y += line->delta;
				break ;
			}
		}
	}
	else
	{
		while (line->a_x-- >= line->b_x)
		{
			while (line->a_y != line->b_y)
			{
				my_mlx_pixel_put(graph->img_ptr, line->a_x, line->a_y, trgb);
				line->a_y -= line->delta;
				break ;
			}
		}
	}
}

void	ft_draw_circle(t_circle *circle, t_graph *graph, int trgb)
{
	double	radius;
	double	i;
	double	j;
	double	dist;
	double	prox;

	prox = circle->prox;
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
			if (dist > (radius - prox) && dist < (radius + prox))
				my_mlx_pixel_put(graph->img_ptr, i, j, trgb);
		}
		i++;
	}
}


