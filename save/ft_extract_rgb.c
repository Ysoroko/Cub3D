/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_rgb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:39:34 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/26 14:57:21 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

int		ft_get_t(int trgb)
{
	return ((trgb & (0xFF << 24)) / 255 / 255 / 255);
}

int		ft_get_r(int trgb)
{
	return ((trgb & (0xFF << 16)) / 255 / 255);
}

int		ft_get_g(int trgb)
{
	return ((trgb & (0xFF << 8)) / 255);
}

int		ft_get_b(int trgb)
{
	return (trgb & 0xFF);
}
