/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shadows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:17:50 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/23 14:31:08 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

/*
** FT_APPLY_SHADOW_TO_TEXTURES
** This function is responsible for the distance related shadow effect
** It is using perp_wall_dist from our t_ray structure and starting at a
** fixed distance, lowers the transparency of the color seen on the screen
** if it's far away from the player
*/

void	ft_apply_shadow_to_textures(double dist, int *color)
{
	int transparency;

	transparency = (int)fmin(((*color >> 24) + 0.1) * (dist * 600), 255);
	*color = (transparency << 24 | *color);
}

/*
** FT_APPLY_SHADOW_TO_FLOOR
** This function is responsible for applying the shadow effect to the floor
** The same logic is used for the textures,
** but different distances are used here
*/

void	ft_apply_shadow_to_floor(double dist, int res, int *color)
{
	int transparency;

	transparency = (int)fmin(((*color >> 24) + 1)
		* ((res / 2 - dist) * 0.35), 255);
	*color = (transparency << 24 | *color);
}

/*
** FT_APPLY_SHADOW_TO_SPRITES
*/

void	ft_apply_shadow_to_sprites(double dist, int *color)
{
	int transparency;

	transparency = (int)fmin(((*color >> 24) + 0.1) * (dist * 600), 255);
	*color = (transparency << 24 | *color);
}
