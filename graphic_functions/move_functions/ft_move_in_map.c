/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_in_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:54:25 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/26 15:35:01 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

static void	ft_move_back_and_forward(t_graph *graph, int direction, t_ray *ray)
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
	if (direction == WALK_FORWARD)
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

static void	ft_move_sideways(t_graph *graph, int direction, t_ray *ray)
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
	if (direction == WALK_RIGHT)
	{
		if (ray->map[(int)(r_p_x + r_d_y * move_speed)][(int)(r_p_y)] == '0')
			ray->pos->x += r_d_y * move_speed;
		if (ray->map[(int)(r_p_x)][(int)(r_p_y - r_d_x * move_speed)] == '0')
			ray->pos->y -= r_d_x * move_speed;
		return ;
	}
	if (ray->map[(int)(r_p_x - r_d_y * move_speed)][(int)r_p_y] == '0')
		ray->pos->x -= r_d_y * move_speed;
	if (ray->map[(int)r_p_x][(int)(r_p_y + r_d_x * move_speed)] == '0')
		ray->pos->y += r_d_x * move_speed;
}

/*
** FT_MOVE_AND_COLLIDE
** This function is responsible for the player movement and collision
*/

void		ft_move_and_collide(t_graph *graph, int direction, t_ray *ray)
{
	if (BONUS == 0)
	{
		if (direction == WALK_FORWARD || direction == WALK_BACKWARD)
			ft_move_back_and_forward(graph, direction, ray);
		else
			ft_move_sideways(graph, direction, ray);
	}
	else if (BONUS == 1)
	{
		ft_move_bonus(graph, direction, ray);
		ft_reposition_line(ray, graph->circle, graph->line->angle,
														graph->line);
		ft_play_step_sound();
	}
	ft_next_frame(graph, ray);
}
