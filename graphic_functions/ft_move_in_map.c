/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_in_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:54:25 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/05 16:04:04 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

/*
** FT_MOVE_AND_COLLIDE
** This function in responsible for the player movement and collision
*/

void	ft_move_and_collide(t_graph *graph, int direction)
{
	double angle;

	angle = graph->line->angle;
	if (direction == 1)
	{
		graph->circle->x += graph->move_speed * cos(angle);
		graph->circle->y += graph->move_speed * sin(angle);
	}
	else
	{
		graph->circle->x -= graph->move_speed * cos(angle);
		graph->circle->y -= graph->move_speed * sin(angle);
	}
	ft_next_frame(graph);
}

/*
** FT_POSITION_IN_MAP
** This function will return a t_point with the position of the player related
** to the map (and not the window)
*/

t_point	*ft_position_in_map(t_graph *graph)
{
	t_point	*position;
	double	units;

	position = ft_new_point(graph->circle->x, graph->circle->y);
	units = graph->frame->units;
	position->x = position->x / units;
	position->y = position->y / units;
	return (position);
}
