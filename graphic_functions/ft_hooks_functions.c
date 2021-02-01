/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:19:05 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/01 18:28:43 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"


static int	ft_move_circle(t_circle *circle, t_graph *graph)
{
	mlx_clear_window(graph->mlx_ptr, graph->win_ptr);
	ft_draw_circle(circle, graph, 0x00FF0000);
	mlx_put_image_to_window(graph->mlx_ptr,
							graph->win_ptr, graph->img_ptr->img, 0, 0);
	return (0);
}

/*
** FT_KEYS_BINDING
** This function determines the reaction of the program to each specific key
*/

int	ft_keys_binding(int keycode, t_graph *graph)
{
	t_circle *circle;

	printf("KEY [%d] was pressed \n", keycode);
	circle = ft_new_circle(960, 540, 100, 10);
	if (keycode == ESCAPE_KEY)
	{
		mlx_destroy_window(graph->mlx_ptr, graph->win_ptr);
		exit(EXIT_SUCCESS);
	}
	if (keycode == LEFT_ARROW_KEY)
	{
		circle->x -= 20;
		ft_move_circle(circle, graph);
	}
	if (keycode == RIGHT_ARROW_KEY)
	{
		circle->x += 20;
		ft_move_circle(circle, graph);
	}
	return (0);
}

/*
** FT_WINDOW_CLOSED
** This function allows to exit the program properly when its window is closed
*/

int	ft_window_closed(t_graph *graph)
{
	mlx_destroy_window(graph->mlx_ptr, graph->win_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}
