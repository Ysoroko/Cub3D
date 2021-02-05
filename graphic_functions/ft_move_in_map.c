/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_in_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:54:25 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/05 17:05:36 by ysoroko          ###   ########.fr       */
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
	ft_reposition_line(graph->circle, angle, graph->line);
	ft_next_frame(graph);
}

/*
** FT_REPOSITION_LINE
** This function recalculates the new position of the line every call
** Saves the changes inside the *line structure
*/

void	ft_reposition_line(t_circle *circle, double angle, t_line *line)
{
	line->a_x = circle->x;
	line->a_y = circle->y;
	line->b_x = line->a_x + LINE_LENGTH * cos(angle);
	line->b_y = line->a_y + LINE_LENGTH * sin(angle);
	line->angle = angle;
	if (line->a_x < line->b_x)
		line->delta = (line->a_y - line->b_y) / (line->a_x - line->b_x);
	else
		line->delta = (line->b_y - line->a_y) / (line->b_x - line->a_x);
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
