/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:19:05 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/08 14:42:42 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

/*
** FT_TURN
** Turns the player in the needed direction and calls the next frame to be done
*/

static void		ft_turn(t_graph *graph, int direction)
{
	double angle;

	if (direction == 1)
		angle = (graph->line->angle + TURNING_SPEED);
	else
		angle = (graph->line->angle - TURNING_SPEED);
	ft_reposition_line(graph, graph->circle, angle, graph->line);
	ft_next_frame(graph);
}

/*
** FT_KEYS_BINDING
** This function determines the reaction of the program to each specific key
*/

int				ft_keys_binding(int keycode, t_graph *graph)
{
	printf("KEY [%d] was pressed \n", keycode);
	if (keycode == ESCAPE_KEY)
	{
		mlx_destroy_window(graph->mlx_ptr, graph->win_ptr);
		exit(EXIT_SUCCESS);
	}
	if (keycode == LEFT_ARROW_KEY)
		ft_turn(graph, -1);
	if (keycode == RIGHT_ARROW_KEY)
		ft_turn(graph, 1);
	if (keycode == UP_ARROW_KEY)
		ft_move_and_collide(graph, 1);
	if (keycode == DOWN_ARROW_KEY)
		ft_move_and_collide(graph, -1);
	return (0);
}

/*
** FT_WINDOW_CLOSED
** This function allows to exit the program properly when its window is closed
*/

int				ft_window_closed(t_graph *graph)
{
	mlx_destroy_window(graph->mlx_ptr, graph->win_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}
