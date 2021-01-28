/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:20:43 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/28 14:29:55 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

t_graph	*ft_window_start(t_map *map)
{
	t_graph	*ret;

	map = 0;
	if (!(ret = ft_new_t_graph(map)))
		return (0);
	if (!(ret->mlx_ptr = mlx_init()))
		return (ft_free_t_graph(ret));
	if (!(ret->win_ptr =
	mlx_new_window(ret->mlx_ptr, map->res_width, map->res_height, "cub3d")))
		return (ft_free_t_graph(ret));
	return (0);
}

//mlx_new_window ( void *mlx_ptr, int size_x, int size_y, char *title ); -- Returns NULL if fails, window identifier otherwise