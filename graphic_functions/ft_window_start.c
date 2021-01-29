/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:20:43 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/29 15:28:39 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

t_graph	*ft_window_start(t_map *map)
{
	t_graph		*graph;
	t_square	*f_square;
	t_square	*c_square;
	t_line		*line;

	if (!(line = ft_new_line(100, 20, 600, 500)))
		return (0);
	if (!(c_square = ft_new_square(0, 0, map->res_width, map->res_height / 2)))
		return (0);
	if (!(f_square = ft_new_square(0, map->res_height / 2,
			map->res_width, map->res_height / 2)))
	{
		free(c_square);
		return (0);
	}
	if (!(graph = ft_new_t_graph(map)))
		return (0);

	ft_draw_square(c_square, graph, graph->c_trgb);
	ft_draw_square(f_square, graph, graph->f_trgb);
	ft_draw_line(line, graph, 0x00FF0000);
	mlx_put_image_to_window(graph->mlx_ptr,
							graph->win_ptr, graph->img_ptr->img, 0, 0);
	mlx_loop(graph->mlx_ptr);
	return (0);
}
