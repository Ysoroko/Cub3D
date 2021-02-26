/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 17:29:02 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/26 10:55:23 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

static void	ft_move_forward_bonus(t_graph *graph, t_ray *ray)
{
	double	move_speed;
	char	next_pos_x;
	char	next_pos_y;

	move_speed = graph->move_speed;
	next_pos_x = ray->map[(int)(ray->pos->x + ray->direction->x * move_speed)]
							[(int)ray->pos->y];
	next_pos_y = ray->map[(int)(ray->pos->x)]
						[(int)(ray->pos->y + ray->direction->y * move_speed)];
	if (ft_strchr("034", next_pos_x))
	{
		if (next_pos_x == '3' && ray->map[(int)ray->pos->x]
											[(int)ray->pos->y] != '3')
			ft_recieve_damage(ray);
		ray->pos->x += ray->direction->x * move_speed;
	}
	if (ft_strchr("034", next_pos_y))
	{
		if (next_pos_y == '3' && ray->map[(int)ray->pos->x]
											[(int)ray->pos->y] != '3')
			ft_recieve_damage(ray);
		ray->pos->y += ray->direction->y * move_speed;
	}
}

static void	ft_move_backward_bonus(t_graph *graph, t_ray *ray)
{
	double	move_speed;
	char	next_pos_x;
	char	next_pos_y;

	move_speed = graph->move_speed;
	next_pos_x = ray->map[(int)(ray->pos->x - ray->direction->x * move_speed)]
							[(int)ray->pos->y];
	next_pos_y = ray->map[(int)(ray->pos->x)]
						[(int)(ray->pos->y - ray->direction->y * move_speed)];
	if (ft_strchr("034", next_pos_x))
	{
		if (next_pos_x == '3' && ray->map[(int)ray->pos->x]
											[(int)ray->pos->y] != '3')
			ft_recieve_damage(ray);
		ray->pos->x -= ray->direction->x * move_speed;
	}
	if (ft_strchr("034", next_pos_y))
	{
		if (next_pos_y == '3' && ray->map[(int)ray->pos->x]
											[(int)ray->pos->y] != '3')
			ft_recieve_damage(ray);
		ray->pos->y -= ray->direction->y * move_speed;
	}
}

static void	ft_move_right_bonus(t_graph *graph, t_ray *ray)
{
	double	move_speed;
	char	next_pos_x;
	char	next_pos_y;

	move_speed = graph->move_speed;
	next_pos_x = ray->map[(int)(ray->pos->x + ray->direction->y * move_speed)]
							[(int)ray->pos->y];
	next_pos_y = ray->map[(int)(ray->pos->x)]
						[(int)(ray->pos->y - ray->direction->x * move_speed)];
	if (ft_strchr("034", next_pos_x))
	{
		if (next_pos_x == '3' && ray->map[(int)ray->pos->x]
											[(int)ray->pos->y] != '3')
			ft_recieve_damage(ray);
		ray->pos->x += ray->direction->y * move_speed;
	}
	if (ft_strchr("034", next_pos_y))
	{
		if (next_pos_y == '3' && ray->map[(int)ray->pos->x]
											[(int)ray->pos->y] != '3')
			ft_recieve_damage(ray);
		ray->pos->y -= ray->direction->x * move_speed;
	}
}

static void	ft_move_left_bonus(t_graph *graph, t_ray *ray)
{
	double	move_speed;
	char	next_pos_x;
	char	next_pos_y;

	move_speed = graph->move_speed;
	next_pos_x = ray->map[(int)(ray->pos->x - ray->direction->y * move_speed)]
							[(int)ray->pos->y];
	next_pos_y = ray->map[(int)(ray->pos->x)]
						[(int)(ray->pos->y + ray->direction->x * move_speed)];
	if (ft_strchr("034", next_pos_x))
	{
		if (next_pos_x == '3' && ray->map[(int)ray->pos->x]
											[(int)ray->pos->y] != '3')
			ft_recieve_damage(ray);
		ray->pos->x -= ray->direction->y * move_speed;
	}
	if (ft_strchr("034", next_pos_y))
	{
		if (next_pos_y == '3' && ray->map[(int)ray->pos->x]
											[(int)ray->pos->y] != '3')
			ft_recieve_damage(ray);
		ray->pos->y += ray->direction->x * move_speed;
	}
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
