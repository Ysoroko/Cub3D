/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_geometry_forms.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:40:09 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/29 14:36:41 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"
#include "../include/ft_geometry_forms.h"

t_square	*ft_new_square(double x, double y, double width, double height)
{
	t_square *square;

	if (!(square = malloc(sizeof(t_square))))
		return (0);
	square->x = x;
	square->y = y;
	square->width = width;
	square->height = height;
	return (square);
}

t_line		*ft_new_line(double a_x, double a_y, double b_x, double b_y)
{
	t_line *line;

	if ((a_x == b_x && a_y == b_y) || !(line = malloc(sizeof(t_line))))
		return (0);
	line->a_x = a_x;
	line->a_y = a_y;
	line->b_x = b_x;
	line->b_y = b_y;
	if (a_x < b_x)
		line->delta = (a_y - b_y) / (a_x - b_x);
	else
		line->delta = (b_y - a_y) / (b_x - a_x);
	return (line);
}
