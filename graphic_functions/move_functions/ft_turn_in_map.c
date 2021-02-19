/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turn_in_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:06:06 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/19 18:08:20 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

static void	ft_turn_right(t_graph *graph, t_ray *ray, double *angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = ray->direction->x;
	old_plane_x = ray->plane->x;
	ray->direction->x = old_dir_x * cos(-TURNING_SPEED)
					- ray->direction->y * sin(-TURNING_SPEED);
	ray->direction->y = old_dir_x * sin(-TURNING_SPEED)
					+ ray->direction->y * cos(-TURNING_SPEED);
	ray->plane->x = old_plane_x * cos(-TURNING_SPEED)
					- ray->plane->y * sin(-TURNING_SPEED);
	ray->plane->y = old_plane_x * sin(-TURNING_SPEED)
					+ ray->plane->y * cos(-TURNING_SPEED);
	if (BONUS == 1)
		*angle = (graph->line->angle + TURNING_SPEED);
}

static void	ft_turn_left(t_graph *graph, t_ray *ray, double *angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = ray->direction->x;
	old_plane_x = ray->plane->x;
	ray->direction->x = old_dir_x * cos(TURNING_SPEED)
					- ray->direction->y * sin(TURNING_SPEED);
	ray->direction->y = old_dir_x * sin(TURNING_SPEED)
					+ ray->direction->y * cos(TURNING_SPEED);
	ray->plane->x = old_plane_x * cos(TURNING_SPEED)
					- ray->plane->y * sin(TURNING_SPEED);
	ray->plane->y = old_plane_x * sin(TURNING_SPEED)
					+ ray->plane->y * cos(TURNING_SPEED);
	if (BONUS == 1)
		*angle = (graph->line->angle - TURNING_SPEED);
}

/*
** FT_TURN
** Turns the player in the needed direction and calls the next frame to be done
*/

void		ft_turn(t_graph *graph, int direction, t_ray *ray)
{
	double	angle;

	if (direction == TURN_RIGHT)
		ft_turn_right(graph, ray, &angle);
	else
		ft_turn_left(graph, ray, &angle);
	if (BONUS == 1)
		ft_reposition_line(ray, graph->circle, angle, graph->line);
	ft_next_frame(graph, ray);
}
