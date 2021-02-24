/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:20:43 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/24 14:29:06 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

/*
** FT_DEFINE_HOOKS
** This function defines all the key mappings (escape / window closing etc.)
*/

static void	ft_define_hooks(t_ray *ray)
{
	mlx_hook(ray->graph->win_ptr, KEY_PRESS_EVENT, KEY_PRESS_MASK,
			ft_keys_binding, ray);
	mlx_hook(ray->graph->win_ptr, DESTROY_EVENT, STRUCTURE_NOTIFY_MASK,
			ft_window_closed, ray);
}

/*
** FT_DRAW_BACKGROUND
** This function will redraw the background colors when called
*/

void		ft_draw_background(t_graph *graph)
{
	double	width;
	double	height;
	int		c_trgb;
	int		f_trgb;

	width = graph->res_width;
	height = graph->res_height / 2;
	c_trgb = graph->c_trgb;
	f_trgb = graph->f_trgb;
	ft_draw_fsquare(&(t_square){0, 0, width, height}, graph, c_trgb);
	ft_draw_fsquare(&(t_square){0, height, width, height}, graph, f_trgb);
}

/*
** FT_NEXT_FRAME
** This function clears the screen and draws everything needed to be drawn
** on the next frame
** 1) Background
** 2) Minimap
*/

void		ft_next_frame(t_graph *graph, t_ray *ray)
{
	int	mouse_x;
	int	mouse_y;

	mouse_x = 0;
	mouse_y = 0;
	mlx_clear_window(graph->mlx_ptr, graph->win_ptr);
	if (BONUS == 0)
		ft_draw_background(graph);
	if (BONUS == 1 && ray->health <= 0)
	{
		ft_game_over(ray, graph);
		return ;
	}
	ft_raycaster(ray);
	if (BONUS == 1)
	{
		ft_draw_minimap(graph, ray);
		ft_draw_hud(ray);
	}
	mlx_put_image_to_window(graph->mlx_ptr,
								graph->win_ptr, graph->img_ptr->img, 0, 0);
}

/*
** FT_WINDOW_START
** This is the central hub of everything which is drawn on the screen
** This function calls all the other functions to produce the images
*/

t_graph		*ft_window_start(t_map *map)
{
	t_graph		*graph;
	t_ray		*ray;

	graph = ft_new_t_graph(map);
	ray = ft_new_raycaster(graph, map);
	ft_next_frame(graph, ray);
	ft_define_hooks(ray);
	if (BONUS == 1)
		ft_play_background_music();
	mlx_loop(graph->mlx_ptr);
	return (0);
}
