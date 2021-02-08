/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:20:21 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/08 17:58:37 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_raycaster.h"

void	ft_raycaster(t_graph *graph)
{
	int		i;
	t_ray	*ray;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;

	ray = ft_new_raycaster(graph, graph->map);
	i = -1;
	while (++i < ray->res_w)
	{
		camera_x = 2 * i / (double)(ray->res_w) - 1;
		ray_dir_x = ray->direction->x + ray->plane_x * camera_x;
		ray_dir_y = ray->direction->y + ray->plane_y * camera_x;
	}

}