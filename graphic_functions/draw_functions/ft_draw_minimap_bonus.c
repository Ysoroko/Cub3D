/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_minimap_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 10:57:30 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/23 16:39:14 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

/*
** FT_DRAW_MINIMAP_BACKGROUND
** This function will draw the background of the minimap as a square
*/

void		ft_draw_minimap_background(t_graph *graph)
{
	double x;
	double y;
	double width;
	double height;

	x = graph->frame->minimap_background->x;
	y = graph->frame->minimap_background->y;
	width = graph->frame->minimap_background->width + 2 * graph->frame->units;
	height = graph->frame->minimap_background->height + 2 * graph->frame->units;
	ft_draw_fsquare(&(t_square){x, y, width, height},
					graph, MAP_BACKGROUND_COLOR);
}

/*
** FT_DRAW_WALLS
** This function is used to draw the walls of the minimap
*/

static void	ft_draw_minimap_walls(t_graph *graph, char **str_tab, double width)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = -1;
	j = -1;
	x = graph->frame->units;
	y = 0;
	while (str_tab[++i])
	{
		j = -1;
		x = graph->frame->units;
		y += graph->frame->units;
		while (str_tab[i][++j])
		{
			if (str_tab[i][j] == '1')
				ft_draw_fsquare(&(t_square){x, y, width, width},
											graph, WALL_COLOR);
			else if (str_tab[i][j] == '2' || str_tab[i][j] == '3')
				ft_draw_fsquare(&(t_square){x, y, width, width},
											graph, SPRITE_COLOR);
			x += graph->frame->units;
		}
	}
}

/*
** FT_DRAW_STARTING_PLAYER_POSITION
** This will determine the starting player position and create a t_line
** for it to be stored in graph
*/

static void	ft_starting_player_direction(t_graph *graph)
{
	char	player_direction;
	double	angle;

	angle = 0;
	player_direction = graph->frame->player_direction;
	if (player_direction == 'S')
		angle = M_PI_2;
	else if (player_direction == 'W')
		angle = M_PI;
	else if (player_direction == 'N')
		angle = M_PI + M_PI_2;
	graph->line = ft_new_line(graph->circle->x,
		graph->circle->y, angle, graph->frame->units * 1.5);
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
	distance_to_wall = ray->graph->frame->units * 1.5;
	ray->graph->circle->x = ray->pos->y *
		ray->graph->frame->units + ray->graph->frame->units;
	ray->graph->circle->y = ray->pos->x *
		ray->graph->frame->units + ray->graph->frame->units;
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

/*
** FT_DRAW_MINIMAP
** This function is the central hub of drawing the minimap
** and determining the needed size
** Draws the background first as a rectangle, then the walls
*/

void	ft_draw_minimap(t_graph *graph, t_ray *ray)
{
	double	units;
	double	radius;
	double	x;
	double	y;

	units = graph->frame->units;
	radius = units / 3;
	x = ray->pos->y * units + units;
	y = ray->pos->x * units + units;
	ft_draw_minimap_background(graph);
	ft_draw_minimap_walls(graph, graph->map->map_str_tab,
							graph->frame->minimap_wall->width);
	if (!graph->circle)
		graph->circle = ft_new_circle(x, y, radius, 0);
	if (!graph->line)
		ft_starting_player_direction(graph);
	ft_draw_fcircle(graph->circle, graph, PLAYER_COLOR);
	ft_draw_line(graph->line, graph, DIRECTION_COLOR);
}
