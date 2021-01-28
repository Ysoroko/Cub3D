/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_new_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:32:57 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/28 15:30:44 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

t_graph	*ft_new_t_graph(t_map *map)
{
	t_graph	*ret;

	ret = 0;
	if (!(ret = malloc(sizeof(t_graph))))
		return (0);
	ret->mlx_ptr = 0;
	ret->win_ptr = 0;
	ret->img_ptr = 0;
	ret->f_ptr = 0;
	ret->param = 0;
	ret->f_trgb = ft_rgb_to_trgb(0, map->f_red, map->f_green, map->f_blue);
	ret->c_trgb = ft_rgb_to_trgb(0, map->c_red, map->c_green, map->c_blue);
	return (ret);
}

t_graph	*ft_free_t_graph(t_graph *graph)
{
	free(graph);
	graph = 0;
	return (0);
}

t_image	*ft_new_t_image(void)
{
	t_image	*ret;

	ret = 0;
	if (!(ret = malloc(sizeof(t_image))))
		return (0);
	ret->img = 0;
	ret->bits_per_pixel = 0;
	ret->line_length = 0;
	ret->endian = 0;
	return (ret);
}

t_image	*ft_free_t_image(t_image *image)
{
	free(image);
	image = 0;
	return (0);
}
