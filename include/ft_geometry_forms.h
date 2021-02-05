/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_geometry_forms.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:15:29 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/05 14:14:01 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GEOMETRY_FORMS_H
# define FT_GEOMETRY_FORMS_H

#include "ft_graphics.h"
#include "ft_params_and_colors.h"

typedef struct	s_square {
	double		x;
	double		y;
	double		width;
	double		height;
}				t_square;

typedef struct	s_line {
	double		a_x;
	double		a_y;
	double		b_x;
	double		b_y;
	double		delta;
	double		delta_x;
	int			trgb;
}				t_line;

typedef struct	s_circle {
	double	x;
	double	y;
	double	radius;
	double	prox;
	int		trgb;
}				t_circle;

typedef struct	s_triangle
{
	int		a_x;
	int		b_x;
	int		c_x;
	int		a_y;
	int		b_y;
	int		c_y;
}				t_triangle;

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

#endif