/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_geometry_forms.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:15:29 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/28 17:35:28 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GEOMETRY_FORMS_H
# define FT_GEOMETRY_FORMS_H

#include "ft_graphics.h"

typedef struct	s_square {
	int		x;
	int		y;
	int		width;
	int		height;
}				t_square;

typedef struct	s_circle {
	int		x;
	int		y;
	int		radius;
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

#endif