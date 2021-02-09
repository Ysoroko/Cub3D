/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_in_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:54:25 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/09 14:30:23 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

/*
** FT_POSITION_IN_MAP
** This function will modify the argument doubles to show
** the position of the player related to the map (and not the window)
** This can be used to find in which map[i][j] we are currently in
*/

static void	ft_position_in_map(t_graph *graph, double *x, double *y)
{
	double	units;

	units = graph->frame->units;
	*x = floor(*x / units);
	*y = floor(*y / units);
}



/*
static void	ft_collide(t_graph *graph, char **map, int direction)
{
	double	x;
	double	y;
	double	x_in_map;
	double	y_in_map;
	double	angle;

	angle = graph->line->angle;
	x = graph->circle->x;
	y = graph->circle->y;
	if (direction == 1)
	{
		x_in_map = x + graph->move_speed * cos(angle);
		y_in_map = y + graph->move_speed * sin(angle);
	}
	else
	{
		x_in_map = x - graph->move_speed * cos(angle);
		y_in_map = y - graph->move_speed * sin(angle);
	}
	ft_position_in_map_(graph, &x_in_map, &y_in_map);
	if (ft_strchr("12", map[(int)x_in_map][(int)y_in_map]))
	{

	}
}
*/

/*
** FT_MOVE_AND_COLLIDE
** This function is responsible for the player movement and collision
*/

void	ft_move_and_collide(t_graph *graph, int direction, t_ray *ray)
{
	double	angle;
	double	x_in_map;
	double	y_in_map;

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
	x_in_map = graph->circle->x;
	y_in_map = graph->circle->y;
	ft_position_in_map(graph, &x_in_map, &y_in_map);
	//printf("\ni:[%f]\nj:[%f]\n", x_in_map, y_in_map);
	ft_reposition_line(graph, graph->circle, angle, graph->line);
	ft_next_frame(graph, ray);
}

/*
** FT_REPOSITION_LINE
** This function recalculates the new position of the line every call
** Saves the changes inside the *line structure
*/

void	ft_reposition_line(t_graph *g, t_circle *cir, double a, t_line *line)
{
	double	units;
	char	**map;
	double	distance_to_wall;

	map = g->map->map_str_tab;
	units = g->frame->units;
	distance_to_wall = ft_dist_to_wall(g, map, units, a);
	line->a_x = cir->x;
	line->a_y = cir->y;
	line->b_x = line->a_x + distance_to_wall * cos(a);
	line->b_y = line->a_y + distance_to_wall * sin(a);
	line->angle = a;
	if (line->a_x < line->b_x)
		line->delta = (line->a_y - line->b_y) / (line->a_x - line->b_x);
	else
		line->delta = (line->b_y - line->a_y) / (line->b_x - line->a_x);
}
