/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:21:07 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/08 17:54:51 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RAYCASTER_H
# define FT_RAYCASTER_H

#include "ft_graphics.h"
#include "ft_map_functions.h"
#include "ft_geometry_forms.h"
#include "ft_params_and_colors.h"
#include "libft.h"
#include "../minilibx/mlx.h"
#include <math.h>

typedef struct	s_ray
{
	char	**map;
	int		map_width;
	int		map_height;
	int		start_x;
	int		start_y;
	char	start_char;
	int		res_w;
	int		res_h;
	double	fov;
	double	plane_x;
	double	plane_y;
	t_point	*direction;
	t_graph	*graph;
}				t_ray;

t_ray	*ft_new_raycaster(t_graph *graph, t_map *map);

#endif