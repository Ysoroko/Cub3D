/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_geometry_forms.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:40:09 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/28 17:43:13 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"
#include "../include/ft_geometry_forms.h"

t_square	*ft_new_square(int x, int y, int width, int height)
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
