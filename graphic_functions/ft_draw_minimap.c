/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 10:57:30 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/04 13:14:22 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

/*
** FT_DRAW_BACKGROUND
** This function will draw the background of the minimap as a square
** Returns the drawn background square structure to use its position
** in the following functions
*/

t_square	*ft_draw_minimap_background(t_map *map, t_graph *graph, int units)
{
	t_square	*background;
	double		x;
	double		y;
	double		width;
	double		height;

	x = 0;
	y = 0;
	height = ft_str_tab_len(map->map_str_tab) * units;
	width = ft_strlen(map->map_str_tab[0]) * units;
	background = ft_new_square(x, y, width, height);
	ft_draw_fsquare(background, graph, BACKGROUND_COLOR);
	return (background);
}

/*
** FT_DRAW_WALLS
** This function is used to draw the walls of the minimap
*/

static void	ft_draw_minimap_walls(t_map *map, t_graph *graph,
							t_square *background, int units)
{
	t_square	*wall;
	double		x;
	double		y;
	int			i;
	int			j;

	x = background->x;
	y = background->y - units;
	i = -1;
	j = -1;
	wall = ft_new_square(x, y, units, units);
	while (map->map_str_tab[++i])
	{
		j = -1;
		wall->x = background->x;
		wall->y += units;
		while (map->map_str_tab[i][++j])
		{
			if (map->map_str_tab[i][j] == '1')
				ft_draw_fsquare(wall, graph, WALL_COLOR);
			wall->x += units;
		}
	}
}

/*
** FT_DRAW_MINIMAP
** This function is the central hub of drawing the minimap
** and determining the needed size
** Draws the background first as a rectangle, then the walls
*/

void		ft_draw_minimap(t_map *map, t_graph *graph)
{
	t_point		*map_size;
	t_square	*background;
	int			units;
	int			max_ratio;

	max_ratio = 3;
	map_size = ft_new_point(ft_strlen(map->map_str_tab[0]),
							ft_str_tab_len(map->map_str_tab));
	units = fmin(map->res_width, map->res_height) / max_ratio /
			fmax(map_size->x, map_size->y);
	background = ft_draw_minimap_background(map, graph, units);
	ft_draw_minimap_walls(map, graph, background, units);
}
