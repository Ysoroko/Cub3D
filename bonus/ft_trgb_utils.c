/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trgb_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:34:43 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/28 14:40:01 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

int	get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int	get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int	get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

/*
** This function will add a shade based on the distance
*/

int	ft_add_shade(double distance, int trgb)
{
	double	t;

	t = get_t(trgb);
	t *= distance;
	return (ft_rgb_to_trgb((int)t, get_r(trgb), get_g(trgb), get_b(trgb)));
}
