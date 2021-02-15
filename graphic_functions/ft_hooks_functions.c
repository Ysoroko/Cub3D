/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:19:05 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/15 10:37:53 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

/*
** FT_KEYS_BINDING
** This function determines the reaction of the program to each specific key
*/

int				ft_keys_binding(int keycode, t_ray *ray)
{
	printf("KEY [%d] was pressed \n", keycode);
	if (keycode == ESCAPE_KEY)
	{
		mlx_destroy_window(ray->graph->mlx_ptr, ray->graph->win_ptr);
		exit(EXIT_SUCCESS);
	}
	if (keycode == LEFT_ARROW_KEY || keycode == A_KEY)
		ft_turn(ray->graph, TURN_LEFT, ray);
	if (keycode == RIGHT_ARROW_KEY || keycode == D_KEY)
		ft_turn(ray->graph, TURN_RIGHT, ray);
	if (keycode == UP_ARROW_KEY || keycode == W_KEY)
		ft_move_and_collide(ray->graph, WALK_FORWARD, ray);
	if (keycode == DOWN_ARROW_KEY || keycode == S_KEY)
		ft_move_and_collide(ray->graph, WALK_BACKWARD, ray);
	if (keycode == Q_KEY)
		ft_move_and_collide(ray->graph, WALK_LEFT, ray);
	if (keycode == E_KEY)
		ft_move_and_collide(ray->graph, WALK_RIGHT, ray);
	return (0);
}

/*
** FT_WINDOW_CLOSED
** This function allows to exit the program properly when its window is closed
*/

int				ft_window_closed(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}
