/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:20:43 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/02 14:14:24 by ysoroko          ###   ########.fr       */
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

/*
** FT_DRAW_BACKGROUND
** This function will redraw the background colors when called
*/

void		ft_draw_background(t_graph *graph)
{
	t_square	*f_square;
	t_square	*c_square;

	c_square = ft_new_square(0, 0, graph->res_width, graph->res_height / 2);
	f_square = ft_new_square(0, graph->res_height / 2,
								graph->res_width, graph->res_height / 2);
	ft_draw_fsquare(c_square, graph, graph->c_trgb);
	ft_draw_fsquare(f_square, graph, graph->f_trgb);
	mlx_put_image_to_window(graph->mlx_ptr,
							graph->win_ptr, graph->img_ptr->img, 0, 0);
}

t_graph		*ft_window_start(t_map *map)
{
	t_graph		*graph;

	graph = ft_new_t_graph(map);
	ft_draw_background(graph);
	graph->circle = ft_new_circle(960, 540, 100, 5);
	ft_draw_fcircle(graph->circle, graph, graph->circle_color);
	mlx_put_image_to_window(graph->mlx_ptr,
							graph->win_ptr, graph->img_ptr->img, 0, 0);
	ft_define_hooks(graph);
	mlx_loop(graph->mlx_ptr);
	return (0);
}
