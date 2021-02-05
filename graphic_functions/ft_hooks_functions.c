/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:19:05 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/05 13:15:45 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

static	void	ft_move_circle(t_graph *graph, char direction)
{
	if (direction == 'N')
		graph->circle->y -= WALKING_SPEED;
	else if (direction == 'S')
		graph->circle->y += WALKING_SPEED;
	else if (direction == 'E')
		graph->circle->x += WALKING_SPEED;
	else if (direction == 'W')
		graph->circle->x -= WALKING_SPEED;
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
		ft_move_circle(graph, 'W');
	if (keycode == RIGHT_ARROW_KEY)
		ft_move_circle(graph, 'E');
	if (keycode == UP_ARROW_KEY)
		ft_move_circle(graph, 'N');
	if (keycode == DOWN_ARROW_KEY)
		ft_move_circle(graph, 'S');
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
