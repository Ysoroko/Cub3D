/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:20:43 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/01 16:43:47 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

/*
** FT_DEFINE_HOOKS
** This function defines all the key mappings (escape / window closing etc.)
*/

static void	ft_define_hooks(t_graph *graph)
{
	mlx_hook(graph->win_ptr, KEY_PRESS_EVENT, KEY_PRESS_MASK,
			ft_keys_binding, graph);
	mlx_hook(graph->win_ptr, DESTROY_EVENT, STRUCTURE_NOTIFY_MASK,
			ft_window_closed, graph);
}

static int	ft_draw_figures(t_graph *graph, t_map *map)
{
	t_square	*f_square;
	t_square	*c_square;

	if (!(c_square = ft_new_square(0, 0, map->res_width, map->res_height / 2)))
		return (0);
	if (!(f_square = ft_new_square(0, map->res_height / 2,
			map->res_width, map->res_height / 2)))
	{
		free(c_square);
		return (0);
	}
	ft_draw_square(c_square, graph, graph->c_trgb);
	ft_draw_square(f_square, graph, graph->f_trgb);
	return (1);
}

t_graph		*ft_window_start(t_map *map)
{
	t_graph		*graph;

	if (!(graph = ft_new_t_graph(map)))
		return (0);
	if (!(ft_draw_figures(graph, map)))
		return (0);
	mlx_put_image_to_window(graph->mlx_ptr,
							graph->win_ptr, graph->img_ptr->img, 0, 0);
	ft_define_hooks(graph);
	mlx_loop(graph->mlx_ptr);
	return (0);
}
