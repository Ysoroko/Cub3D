/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_empty_forms.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:50:54 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/04 14:45:34 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

/*
** FT_DRAW_LINE
** Draws the specified line with the specified colour
*/

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

/*
** FT_DRAW_CIRCLE
** Draws the specified circle with the specified colour, not filled in
** The thickness of the line of the circle is 2*circle->prox
*/

void	ft_draw_circle(t_circle *circle, t_graph *graph, int trgb)
{
	double	radius;
	double	i;
	double	j;
	double	dist;

	radius = circle->radius;
	i = circle->x - circle->radius - circle->prox;
	j = circle->y - circle->radius - circle->prox;
	dist = 0;
	while (i <= circle->x + radius + circle->prox)
	{
		j = circle->y - circle->radius - circle->prox;
		while (j++ <= circle->y + radius + circle->prox)
		{
			dist = sqrt(((i - circle->x) * (i - circle->x))
					+ ((j - circle->y) * (j - circle->y)));
			if (dist > (radius - circle->prox)
				&& dist < (radius + circle->prox))
				my_mlx_pixel_put(graph->img_ptr, i, j, trgb);
		}
		i++;
	}
}

/*
** FT_DRAW_TRIANGLE
** Draws the triangle, connecting its 3 dots by using the line function
** Does not fill in its interior
*/

void	ft_draw_triangle(t_triangle *triangle, t_graph *graph, int trgb)
{
	t_line *a;
	t_line *b;
	t_line *c;

	a = ft_new_line(triangle->a_x, triangle->a_y,
					triangle->b_x, triangle->b_y);
	b = ft_new_line(triangle->a_x, triangle->a_y,
					triangle->c_x, triangle->c_y);
	c = ft_new_line(triangle->b_x, triangle->b_y,
					triangle->c_x, triangle->c_y);
	ft_draw_line(a, graph, trgb);
	ft_draw_line(b, graph, trgb);
	ft_draw_line(c, graph, trgb);
}
