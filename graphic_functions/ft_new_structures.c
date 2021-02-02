/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_structures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:32:57 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/02 13:29:59 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

t_graph	*ft_new_t_graph(t_map *map)
{
	t_graph	*ret;

	ret = 0;
	if (!(ret = malloc(sizeof(t_graph))))
		ft_malloc_fail();
	if (!(ret->mlx_ptr = mlx_init()))
		ft_mlx_fail();
	if (!(ret->win_ptr = mlx_new_window(ret->mlx_ptr,
		map->res_width, map->res_height, "cub3d")))
		ft_mlx_fail();
	ret->img_ptr = ft_image(ret->mlx_ptr,
		map->res_width, map->res_height);
	ret->f_ptr = 0;
	ret->param = 0;
	ret->f_trgb = ft_rgb_to_trgb(0, map->f_red, map->f_green, map->f_blue);
	ret->c_trgb = ft_rgb_to_trgb(0, map->c_red, map->c_green, map->c_blue);
	ret->circle = 0;
	ret->circle_color = 0x00FF6900;
	ret->x_speed = 20;
	return (ret);
}

t_image	*ft_new_t_image(void)
{
	t_image	*ret;

	ret = 0;
	if (!(ret = malloc(sizeof(t_image))))
		ft_malloc_fail();
	ret->img = 0;
	ret->bits_per_pixel = 0;
	ret->line_length = 0;
	ret->endian = 0;
	return (ret);
}
