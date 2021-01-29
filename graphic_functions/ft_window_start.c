/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:20:43 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/29 11:29:21 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

t_graph	*ft_window_start(t_map *map)
{
	t_graph		*graph;
	t_square	*square;

	if (!(square = ft_new_square(0, 100, 200, 200)))
		return (0);
	if (!(graph = ft_new_t_graph(map)))
		return (0);

	ft_draw_square(square, graph, graph->f_trgb);
	mlx_put_image_to_window(graph->mlx_ptr,
							graph->win_ptr, graph->img_ptr->img, 0, 0);
	mlx_loop(graph->mlx_ptr);
	return (0);
}
