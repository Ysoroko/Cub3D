/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_vertical_line.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 12:22:58 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/12 16:04:18 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

/*
**	static void	ft_print_ray(t_ray *ray)
**	{
**		//TO COMMENT OUT BEFORE PUSHING
**		int i = 0;
**
**		printf ("\n\n\n\n\n");
**		printf("------------------------------------------------\n");
**		printf("\t		RAY				\n");
**		printf("------------------------------------------------\n");
**		printf("\nmap: \n\n");
**		while (ray->map[i++] != 0)
**		printf("map[i]: |%s|\n", ray->map[i]);
**		printf("map_width: [%d]\n", ray->map_width);
**		printf("map_height: [%d]\n", ray->map_height);
**		printf("hit: [%d]\n", ray->hit);
**		printf("side: [%d]\n", ray->side);
**		printf("fov: [%f]\n", ray->fov);
**		printf("camera_x: [%f]\n", ray->camera_x);
**		printf("perp_wall_dist: [%f]\n", ray->perp_wall_dist);
**		printf("pos: x:[%f] y: [%f]\n", ray->pos->x, ray->pos->y);
**		printf("in_map: x:[%f] y: [%f]\n", ray->in_map->x, ray->in_map->y);
**		printf("res: x:[%f] y: [%f]\n", ray->res->x, ray->res->y);
**		printf("plane: x:[%f] y: [%f]\n", ray->plane->x, ray->plane->y);
**		printf("direction: x:[%f] y: [%f]\n",
**				ray->direction->x, ray->direction->y);
**		printf("ray_dir: x:[%f] y: [%f]\n", ray->ray_dir->x, ray->ray_dir->y);
**		printf("delta_dist: x:[%f] y: [%f]\n",
**							ray->delta_dist->x, ray->delta_dist->y);
**		printf("side_dist: x:[%f] y: [%f]\n",
**						ray->side_dist->x, ray->side_dist->y);
**		printf("step: x:[%f] y: [%f]\n", ray->step->x, ray->step->y);
**		printf("line: a_x:[%f] a_y: [%f] b_x: [%f] b_y:
**		ray->line->b_y, ray->line->angle, ray->line->len, ray->line->delta);
**	}
*/

void	ft_draw_vertical_line(int x, double a_y, double b_y, t_ray *ray)
{
	int		i;
	int		max;
	int		trgb;
	double	my_x;

	my_x = (double)x;
	ft_limit_points_within_map(&my_x, &a_y, ray->graph);
	ft_limit_points_within_map(&my_x, &b_y, ray->graph);
	i = (int)fmin(a_y, b_y);
	max = (int)fmax(a_y, b_y);
	while (i++ < max - 1)
	{
		trgb = 0x00F2BC94;
		if (ray->side == 1)
			trgb = trgb / 2;
		my_mlx_pixel_put(ray->graph->img_ptr, my_x, i, trgb);
	}
}
