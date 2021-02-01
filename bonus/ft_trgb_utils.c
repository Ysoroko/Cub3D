/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trgb_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:34:43 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/01 14:52:00 by ysoroko          ###   ########.fr       */
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

int	ft_inverse_color(trgb)
{
	int r;
	int g;
	int b;

	r = 255 - get_r(trgb);
	g = 255 - get_g(trgb);
	b = 255 - get_b(trgb);
	return (ft_rgb_to_trgb(0, r, g, b));
}


/*
** Increments the color once
*/

int	ft_gradient(int *trgb_start, int trgb_end, double rat)
{
	int r;
	int g;
	int b;
	int ratio;

	ratio = nearbyint(rat * 100);
	r = get_r(*trgb_start);
	g = get_g(*trgb_start);
	b = get_b(*trgb_start);
	if (ratio % 2 == 0)
		ratio = 1;
	else
		ratio = 0;
	if (r > get_r(trgb_end))
		r -= ratio;
	else if (r < get_r(trgb_end))
		r += ratio;
	if (g > get_g(trgb_end))
		g -= ratio;
	else if (g < get_g(trgb_end))
		g += ratio;
	if (b > get_b(trgb_end))
		b -= ratio;
	else if (b < get_b(trgb_end))
		b += ratio;

	if (r < 0)
		r = 0;
	if (r > 255)
		r = 255;
	if (g < 0)
		g = 0;
	if (g > 255)
		g = 255;
	if (b < 0)
		b = 0;
	if (b > 255)
		b = 255;
	return (*trgb_start);
}
