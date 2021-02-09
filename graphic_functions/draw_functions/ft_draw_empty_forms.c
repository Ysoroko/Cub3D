/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_empty_forms.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:50:54 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/09 17:14:47 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

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
