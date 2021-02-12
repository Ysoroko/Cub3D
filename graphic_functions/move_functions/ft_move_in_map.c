/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_in_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:54:25 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/12 16:35:01 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

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

static void	ft_move(t_graph *graph, int direction, t_ray *ray)
{
	double	move_speed;
	double	r_p_x;
	double	r_p_y;
	double	r_d_x;
	double	r_d_y;

	r_d_x = ray->direction->x;
	r_d_y = ray->direction->y;
	r_p_x = ray->pos->x;
	r_p_y = ray->pos->y;
	move_speed = graph->move_speed;

	if (direction == 1)
	{
		if (ray->map[(int)(r_p_x + r_d_x * move_speed)][(int)(r_p_y)] == '0')
			ray->pos->x += r_d_x * move_speed;
		if (ray->map[(int)(r_p_x)][(int)(r_p_y + r_d_y * move_speed)] == '0')
			ray->pos->y += r_d_y * move_speed;
		return ;
	}
	if (ray->map[(int)(r_p_x - r_d_x * move_speed)][(int)r_p_y] == '0')
		ray->pos->x -= r_d_x * move_speed;
	if (ray->map[(int)r_p_x][(int)(r_p_y - r_d_y * move_speed)] == '0')
		ray->pos->y -= r_d_y * move_speed;
}

/*
** FT_MOVE_AND_COLLIDE
** This function is responsible for the player movement and collision
*/

void		ft_move_and_collide(t_graph *graph, int direction, t_ray *ray)
{
	ft_move(graph, direction, ray);
	graph->circle->x = ray->pos->y * graph->frame->units + graph->frame->units;
	graph->circle->y = ray->pos->x * graph->frame->units + graph->frame->units;
	ft_reposition_line(ray, graph->circle, graph->line->angle, graph->line);
	ft_next_frame(graph, ray);
}

/*
** FT_REPOSITION_LINE
** This function recalculates the new position of the line every call
** Saves the changes inside the *line structure
*/

void		ft_reposition_line(t_ray *ray, t_circle *cir, double a, t_line *l)
{
	double	units;
	char	**map;
	double	distance_to_wall;

	map = ray->graph->map->map_str_tab;
	units = ray->graph->frame->units;
	//distance_to_wall = ray->perp_wall_dist * units;
	distance_to_wall = ray->graph->frame->units * 1.5;
	l->a_x = cir->x;
	l->a_y = cir->y;
	l->b_x = l->a_x + distance_to_wall * cos(a);
	l->b_y = l->a_y + distance_to_wall * sin(a);
	l->angle = a;
	if (l->a_x < l->b_x)
		l->delta = (l->a_y - l->b_y) / (l->a_x - l->b_x);
	else
		l->delta = (l->b_y - l->a_y) / (l->b_x - l->a_x);
}
