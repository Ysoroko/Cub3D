/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:22:26 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/28 14:46:54 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GRAPHICS_H
# define FT_GRAPHICS_H

#include "../include/ft_map_functions.h"
#include "../minilibx/mlx.h"

typedef struct		s_graph
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*f_ptr;
	int		f_trgb;
	int		c_trgb;
	void	*param;
}					t_graph;

t_graph	*ft_new_t_graph(t_map *map);
t_graph	*ft_free_t_graph(t_graph *graph);
t_graph	*ft_window_start(t_map *map);
int		ft_rgb_to_trgb(int t, int r, int g, int b);

#endif