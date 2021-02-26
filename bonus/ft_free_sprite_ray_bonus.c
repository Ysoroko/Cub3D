/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_sprite_ray_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 11:37:13 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/26 13:46:09 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

void	ft_free_sprite_ray(t_sprite_ray *sprite_ray)
{
	int i;

	i = -1;
	while (++i < sprite_ray->num_sprites)
		free(sprite_ray->sprite_array[i]);
	free(sprite_ray->sprite_array);
	free(sprite_ray->z_buffer);
	free(sprite_ray->sprite_order);
	free(sprite_ray->sprite_distance);
	free(sprite_ray->spr);
	free(sprite_ray->transform);
	free(sprite_ray->draw_start);
	free(sprite_ray->draw_end);
	free(sprite_ray->tex);
	free(sprite_ray->texture_size);
	free(sprite_ray);
}
