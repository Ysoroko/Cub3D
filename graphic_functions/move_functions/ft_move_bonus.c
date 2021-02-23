/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 17:29:02 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/23 18:50:57 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

static void	ft_move_forward_bonus(t_graph *graph, t_ray *ray)
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
	if (ray->map[(int)(r_p_x + r_d_x * move_speed)][(int)(r_p_y)] == '4'
		|| ray->map[(int)(r_p_x + r_d_x * move_speed)][(int)(r_p_y)] == '3'
		|| ray->map[(int)(r_p_x + r_d_x * move_speed)][(int)(r_p_y)] == '0')
		ray->pos->x += r_d_x * move_speed;
	if (ray->map[(int)(r_p_x)][(int)(r_p_y + r_d_y * move_speed)] == '4'
		|| ray->map[(int)(r_p_x)][(int)(r_p_y + r_d_y * move_speed)] == '3'
		|| ray->map[(int)(r_p_x)][(int)(r_p_y + r_d_y * move_speed)] == '0')
		ray->pos->y += r_d_y * move_speed;
}

static void	ft_move_backward_bonus(t_graph *graph, t_ray *ray)
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
	if (ray->map[(int)(r_p_x - r_d_x * move_speed)][(int)r_p_y] == '4'
		|| ray->map[(int)(r_p_x - r_d_x * move_speed)][(int)r_p_y] == '3'
		|| ray->map[(int)(r_p_x - r_d_x * move_speed)][(int)r_p_y] == '0')
		ray->pos->x -= r_d_x * move_speed;
	if (ray->map[(int)r_p_x][(int)(r_p_y - r_d_y * move_speed)] == '4'
		|| ray->map[(int)r_p_x][(int)(r_p_y - r_d_y * move_speed)] == '3'
		|| ray->map[(int)r_p_x][(int)(r_p_y - r_d_y * move_speed)] == '0')
		ray->pos->y -= r_d_y * move_speed;
}


static void	ft_move_right_bonus(t_graph *graph, t_ray *ray)
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

	if (ray->map[(int)(r_p_x + r_d_y * move_speed)][(int)(r_p_y)] == '4'
		|| ray->map[(int)(r_p_x + r_d_y * move_speed)][(int)(r_p_y)] == '3'
		|| ray->map[(int)(r_p_x + r_d_y * move_speed)][(int)(r_p_y)] == '0')
		ray->pos->x += r_d_y * move_speed;
	if (ray->map[(int)(r_p_x)][(int)(r_p_y - r_d_x * move_speed)] == '4'
		|| ray->map[(int)(r_p_x)][(int)(r_p_y - r_d_x * move_speed)] == '0'
		|| ray->map[(int)(r_p_x)][(int)(r_p_y - r_d_x * move_speed)] == '3')
		ray->pos->y -= r_d_x * move_speed;
}

static void	ft_move_left_bonus(t_graph *graph, t_ray *ray)
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

	if (ray->map[(int)(r_p_x - r_d_y * move_speed)][(int)r_p_y] == '4'
		|| ray->map[(int)(r_p_x - r_d_y * move_speed)][(int)r_p_y] == '0'
		|| ray->map[(int)(r_p_x - r_d_y * move_speed)][(int)r_p_y] == '3')
		ray->pos->x -= r_d_y * move_speed;
	if (ray->map[(int)r_p_x][(int)(r_p_y + r_d_x * move_speed)] == '4'
		|| ray->map[(int)r_p_x][(int)(r_p_y + r_d_x * move_speed)] == '0'
		|| ray->map[(int)r_p_x][(int)(r_p_y + r_d_x * move_speed)] == '3')
		ray->pos->y += r_d_x * move_speed;
}

void		ft_move_bonus(t_graph *graph, int direction, t_ray *ray)
{
	if (direction == WALK_RIGHT)
		ft_move_right_bonus(graph, ray);
	else if (direction == WALK_LEFT)
		ft_move_left_bonus(graph, ray);
	else if (direction == WALK_FORWARD)
		ft_move_forward_bonus(graph, ray);
	else if (direction == WALK_BACKWARD)
		ft_move_backward_bonus(graph, ray);
}
