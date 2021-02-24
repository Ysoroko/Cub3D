/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_damage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:25:37 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/24 14:32:30 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

void	ft_recieve_damage(t_ray *ray)
{
	ray->health -= 1;
	if (ray->health)
		ft_play_hurt_sound();
	if (ray->health <= 0)
		ft_next_frame(ray->graph, ray);
}

void	ft_game_over(t_ray *ray, t_graph *graph)
{
	ft_stop_all_afplay_sounds();
	ft_play_game_over_sound();
	ft_draw_fsquare(&(t_square){0, 0, ray->res->x, ray->res->y}, graph, 0);
	mlx_put_image_to_window(graph->mlx_ptr,
								graph->win_ptr, graph->img_ptr->img, 0, 0);
	mlx_string_put(graph->mlx_ptr, graph->win_ptr,
				ray->res->x / 2, ray->res->y / 2, 0x00FF0000, "YOU DIED");
}
