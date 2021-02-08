/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distance_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:07:05 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/08 17:24:00 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

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

double	ft_two_points_distance(double a_x, double a_y, double b_x, double b_y)
{
	return (sqrt(((b_x - a_x) * (b_x - a_x)) + ((b_y - a_y) * (b_y - a_y))));
}

double	ft_dist_to_wall(t_graph *graph, char **map, double units, double angle)
{
	t_point	current;
	t_point	in_map;
	double	distance;
	double	tang;
	double	start_dist_x;

	distance = 0;
	if (angle == M_PI_2 || angle == M_PI + M_PI_2
						|| angle == 0 || angle == M_PI)
		tang = units;
	else
		tang = fabs(tan(angle));
	in_map.x = graph->circle->x;
	in_map.y = graph->circle->x;
	ft_position_in_map(graph, &(in_map.x), &in_map.y);
	start_dist_x = ((in_map.x + 1) * units) - graph->circle->x;
	current.x = graph->circle->x;
	current.y = graph->circle->y;
	while (in_map.y < ft_str_tab_len(map) && in_map.x < ft_strlen(map[0]) &&
			!ft_strchr("12", map[(int)in_map.y][(int)in_map.x]))
	{
		distance += tang;
		current.x += tang * sin(angle);
		current.y += tang * cos(angle);
		in_map.x = current.x;
		in_map.y = current.y;
		ft_position_in_map(graph, &(in_map.x), &in_map.y);
	}
	return (distance);
}
