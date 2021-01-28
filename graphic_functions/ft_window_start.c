/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:20:43 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/28 16:29:32 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

t_graph	*ft_window_start(t_map *map)
{
	t_graph	*graph;
	t_image	*image;

	if (!(graph = ft_new_t_graph(map)))
		return (0);
	if (!(graph->mlx_ptr = mlx_init()))
		return (ft_free_t_graph(graph));
	if (!(graph->win_ptr =
	mlx_new_window(graph->mlx_ptr, map->res_width, map->res_height, "cub3d")))
		return (ft_free_t_graph(graph));
	if (!(image = ft_image(graph->mlx_ptr, map->res_width, map->res_height)))
	{
		return (ft_free_t_graph(graph));
	}
	int i = 1;
	int j = 1;
	while (i < map->res_width)
	{
		j = 0;
		while (j < map->res_height)
		{
			my_mlx_pixel_put(image, i, j, graph->f_trgb);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(graph->mlx_ptr, graph->win_ptr, image->img, 0, 0);
	mlx_loop(graph->mlx_ptr);
	return (0);
}
