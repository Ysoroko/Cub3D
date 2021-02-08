/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 10:57:30 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/08 14:38:33 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

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
	width = graph->frame->minimap_background->width;
	height = graph->frame->minimap_background->height;
	ft_draw_fsquare(&(t_square){x, y, width, height},
					graph->img_ptr, MAP_BACKGROUND_COLOR);
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
	x = 0;
	y = -graph->frame->units;
	while (str_tab[++i])
	{
		j = -1;
		x = 0;
		y += graph->frame->units;
		while (str_tab[i][++j])
		{
			if (str_tab[i][j] == '1')
				ft_draw_fsquare(&(t_square){x, y, width, width},
											graph->img_ptr, WALL_COLOR);
			else if (str_tab[i][j] == '2')
				ft_draw_fsquare(&(t_square){x, y, width, width},
											graph->img_ptr, SPRITE_COLOR);
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
	player_direction = graph->map->map_str_tab[graph->map->player_y]
												[graph->map->player_x];
	if (player_direction == 'S')
		angle = M_PI_2;
	else if (player_direction == 'W')
		angle = M_PI;
	else if (player_direction == 'N')
		angle = M_PI + M_PI_2;
	graph->line = ft_new_line(graph->circle->x,
		graph->circle->y, angle, ft_dist_to_wall(graph,
		graph->map->map_str_tab, graph->frame->units, angle));
}

/*
** FT_DRAW_MINIMAP
** This function is the central hub of drawing the minimap
** and determining the needed size
** Draws the background first as a rectangle, then the walls
*/

void	ft_draw_minimap(t_graph *graph)
{
	ft_draw_minimap_background(graph);
	ft_draw_minimap_walls(graph, graph->map->map_str_tab,
							graph->frame->minimap_wall->width);
	if (!graph->circle)
	{
		graph->circle = ft_new_circle((graph->map->player_x *
										graph->frame->units)
								+ graph->frame->units / 3,
					(graph->map->player_y * graph->frame->units)
			+ graph->frame->units / 3, graph->frame->units / 3, 0);
	}
	if (!graph->line)
		ft_starting_player_direction(graph);
	ft_draw_fcircle(graph->circle, graph->img_ptr, PLAYER_COLOR);
	ft_draw_line(graph->line, graph->img_ptr, DIRECTION_COLOR);
}
