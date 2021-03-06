/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_geometry_forms.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:40:09 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/12 14:21:36 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

t_square	*ft_new_square(double x, double y, double width, double height)
{
	t_square *square;

	if (!(square = malloc(sizeof(t_square))))
		ft_malloc_fail();
	square->x = x;
	square->y = y;
	square->width = width;
	square->height = height;
	return (square);
}

t_line		*ft_new_line(double a_x, double a_y, double angle, double len)
{
	t_line *line;

	if (!(line = malloc(sizeof(t_line))))
		ft_malloc_fail();
	line->a_x = a_x;
	line->a_y = a_y;
	line->angle = angle;
	line->b_x = a_x + len * cos(angle);
	line->b_y = a_y + len * sin(angle);
	if (a_x < line->b_x)
		line->delta = (a_y - line->b_y) / (a_x - line->b_x);
	else
		line->delta = (line->b_y - a_y) / (line->b_x - a_x);
	return (line);
}

t_circle	*ft_new_circle(double x, double y, double radius, double prox)
{
	t_circle	*circle;

	if (!(circle = malloc(sizeof(t_circle))))
		ft_malloc_fail();
	circle->x = x;
	circle->y = y;
	circle->radius = radius;
	circle->prox = prox;
	return (circle);
}

t_point		*ft_new_point(double x, double y)
{
	t_point	*ret;

	if (!(ret = malloc(sizeof(t_point))))
		ft_malloc_fail();
	ret->x = x;
	ret->y = y;
	return (ret);
}

void		ft_limit_points_within_map(double *x, double *y, t_graph *graph)
{
	if (x)
	{
		if (*x < 0)
			*x = 0;
		if (graph)
		{
			if (*x > graph->res_width)
				*x = graph->res_width;
		}
	}
	if (y)
	{
		if (*y < 0)
			*y = 0;
		{
			if (*y > graph->res_height)
				*y = graph->res_height;
		}
	}
}
