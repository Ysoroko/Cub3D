/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:20:21 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/17 12:34:26 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

/*
** FT_SETUP_RAY
** This function is used to setup the starting t_ray values after the
** incrementation in the main "while" loop
*/

static void	ft_setup_ray(t_ray *ray, int i)
{
	ray->camera_x = 2 * i / ray->res->x - 1;
	ray->ray_dir->x = ray->direction->x + ray->plane->x * ray->camera_x;
	ray->ray_dir->y = ray->direction->y + ray->plane->y * ray->camera_x;
	ray->in_map->x = (int)(floor(ray->pos->x));
	ray->in_map->y = (int)(floor(ray->pos->y));
	ray->delta_dist->x = fabs(1 / ray->ray_dir->x);
	ray->delta_dist->y = fabs(1 / ray->ray_dir->y);
	ray->hit = 0;
}

/*
** FT_STEP_AND_SIDE_DIST
** This function will calculate the distance to the next x/y in the map and
** set the coresponding values in t_ray accordingly
*/

static void	ft_step_and_side_dist(t_ray *ray)
{
	if (ray->ray_dir->x < 0)
	{
		ray->step->x = -1;
		ray->side_dist->x =
					(ray->pos->x - ray->in_map->x) * ray->delta_dist->x;
	}
	else
	{
		ray->step->x = 1;
		ray->side_dist->x =
					(ray->in_map->x + 1 - ray->pos->x) * ray->delta_dist->x;
	}
	if (ray->ray_dir->y < 0)
	{
		ray->step->y = -1;
		ray->side_dist->y =
				(ray->pos->y - ray->in_map->y) * ray->delta_dist->y;
	}
	else
	{
		ray->step->y = 1;
		ray->side_dist->y =
				(ray->in_map->y + 1 - ray->pos->y) * ray->delta_dist->y;
	}
}

/*
** FT_PERFORM_DDA
** This functions performs the "digital differential analysis"
** For each intersection with the next x/y in the map, it will calculate the
** distance to the next intersection in x and y and apply the least one
** This is done until it encounters a wall
*/

static void	ft_perform_dda(t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist->x < ray->side_dist->y)
		{
			ray->side_dist->x += ray->delta_dist->x;
			ray->in_map->x += ray->step->x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist->y += ray->delta_dist->y;
			ray->in_map->y += ray->step->y;
			ray->side = 1;
		}
		if (ray->map[(int)(ray->in_map->x)][(int)(ray->in_map->y)] == '1')
			ray->hit = 1;
	}
}

/*
** FT_DISTANCE_AND_LINE
** This function is used to determine the perendicular distance to the wall
** based on our line of sight and use this distance to draw the according
** vertical line
*/

static void	ft_distance_and_line(t_ray *ray, int x)
{
	int		h;
	double	line_height;

	h = ray->graph->res_height;
	if (ray->side == 0)
	{
		ray->perp_wall_dist = (ray->in_map->x - ray->pos->x +
								(1 - ray->step->x) / 2) / ray->ray_dir->x;
	}
	else
	{
		ray->perp_wall_dist = (ray->in_map->y - ray->pos->y +
								(1 - ray->step->y) / 2) / ray->ray_dir->y;
	}
	line_height = (int)(h / ray->perp_wall_dist);
	ray->line->len = line_height;
	ray->line->a_x = x;
	ray->line->a_y = -line_height / 2 + h / 2;
	ray->line->b_x = x;
	ray->line->b_y = line_height / 2 + h / 2;
	ray->line->delta = 1;
	ft_limit_points_within_map(0, &ray->line->a_y, ray->graph);
	ft_limit_points_within_map(0, &ray->line->b_y, ray->graph);
}

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
**	}
*/

static void	ft_textures(t_ray *ray, int x)
{
	int	y;
	int	color;
	int	buffer[(int)(ray->res->y)];

	y = (int)ray->line->a_y;
	if (ray->side == 0)
		ray->wall_x = ray->pos->y + ray->perp_wall_dist + ray->ray_dir->y;
	else
		ray->wall_x = ray->pos->x + ray->perp_wall_dist + ray->ray_dir->x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)(ray->texture_width));
	if ((ray->side == 0 && ray->ray_dir->x > 0) ||
						(ray->side == 1 && ray->ray_dir->y < 0))
		ray->tex_x = ray->texture_width - ray->tex_x - 1;
	ray->tex_step = ray->texture_height / ray->line->len;
	ray->tex_pos = (ray->line->a_y - ray->graph->res_height
									/ 2 + ray->line->len / 2) * ray->tex_step;
	while (y++ < ray->line->b_y)
	{
		ray->tex_y = (int)ray->tex_pos & (ray->texture_height - 1);
		ray->tex_pos += ray->tex_step;
		my_mlx_pixel_get(ray->north_texture, x % TEXTURE_W, y % TEXTURE_H, &(color));
		buffer[y] = color;
	}
	ft_draw_vertical_line(x, ray->line->a_y, ray->line->b_y, ray, buffer);
}

/*
** FT_RAYCASTER
** This is the main function which is the central hub of all the raycasting
** related calculations each frame
*/

void		ft_raycaster(t_ray *ray)
{
	int	i;

	i = -1;
	while (++i < ray->res->x)
	{
		ft_setup_ray(ray, i);
		ft_step_and_side_dist(ray);
		ft_perform_dda(ray);
		ft_distance_and_line(ray, i);
		ft_textures(ray, i);
		//printf("ALL GOOD BEFORE RAYCASTER\n");
		//printf("a_y: [%f]\n b_y: [%f]\n", ray->line->a_y, ray->line->b_y);
	}
}


