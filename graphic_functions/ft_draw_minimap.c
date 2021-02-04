/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 10:57:30 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/04 15:52:03 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

/*
** FT_DRAW_BACKGROUND
** This function will draw the background of the minimap as a square
*/

void	ft_draw_minimap_background(t_graph *graph)
{
	ft_draw_fsquare(graph->frame->minimap_background,
						graph, MAP_BACKGROUND_COLOR);
}

/*
** FT_DRAW_WALLS
** This function is used to draw the walls of the minimap
*/

static void	ft_draw_minimap_walls(t_graph *graph)
{
	t_square	*wall;
	int			i;
	int			j;

	i = -1;
	j = -1;
	wall = graph->frame->minimap_wall;
	wall->x = graph->frame->minimap_background->x;
	wall->y = graph->frame->minimap_background->y - graph->frame->units;
	while (graph->map->map_str_tab[++i])
	{
		j = -1;
		wall->x = graph->frame->minimap_background->x;
		wall->y += graph->frame->units;
		while (graph->map->map_str_tab[i][++j])
		{
			if (graph->map->map_str_tab[i][j] == '1')
				ft_draw_fsquare(wall, graph, WALL_COLOR);
			wall->x += graph->frame->units;
		}
	}
	graph->frame->minimap_wall->x = graph->frame->minimap_background->x;
	graph->frame->minimap_wall->y = graph->frame->minimap_background->y;
}

/*
** FT_DRAW_MINIMAP
** This function is the central hub of drawing the minimap
** and determining the needed size
** Draws the background first as a rectangle, then the walls
*/

void		ft_draw_minimap(t_graph *graph)
{
	ft_draw_minimap_background(graph);
	ft_draw_minimap_walls(graph);
	if (!graph->circle)
	{
		graph->circle = ft_new_circle((graph->map->player_x *
										graph->frame->units)
								+ graph->frame->units / 2,
					(graph->map->player_y * graph->frame->units)
			+ graph->frame->units / 2, graph->frame->units / 2, 0);
	}
}
