/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:24:45 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/08 13:40:31 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

/*
** FT_DRAW_RIGHT_LINE
** Draw a line facing right
*/

static void	ft_draw_right_line(t_line *line, t_image *img_ptr, int trgb)
{
	if (line->a_y == line->b_y)
		line->delta = 0;
	while (line->a_x++ <= line->b_x)
	{
		while (line->a_y != line->b_y)
		{
			line->a_y += line->delta;
			break ;
		}
		my_mlx_pixel_put(img_ptr, line->a_x, line->a_y, trgb);
	}
}

/*
** FR_DRAW_LEFT_LINE
** Draw a line facing left
*/

static void	ft_draw_left_line(t_line *line, t_image *img_ptr, int trgb)
{
	if (line->a_y == line->b_y)
		line->delta = 0;
	while (line->a_x-- >= line->b_x)
	{
		while (line->a_y != line->b_y)
		{
			line->a_y -= line->delta;
			break ;
		}
		my_mlx_pixel_put(img_ptr, line->a_x, line->a_y, trgb);
	}
}

/*
** FR_DRAW_DOWN_LINE
** Draw a line facing down
*/

static void	ft_draw_down_line(t_line *line, t_image *img_ptr, int trgb)
{
	my_mlx_pixel_put(img_ptr, line->a_x, line->a_y, trgb);
	if (line->a_x == line->b_x)
		line->delta = 0;
	while (line->a_y-- >= line->b_y)
	{
		while (line->a_x != line->b_x)
		{
			line->a_x -= line->delta;
			break ;
		}
		my_mlx_pixel_put(img_ptr, line->a_x, line->a_y, trgb);
	}
}

/*
** FR_DRAW_UP_LINE
** Draw a line facing up
*/

static void	ft_draw_up_line(t_line *line, t_image *img_ptr, int trgb)
{
	if (line->a_x == line->b_x)
		line->delta = 0;
	while (line->a_y++ <= line->b_y)
	{
		while (line->a_x != line->b_x)
		{
			line->a_x += line->delta;
			break ;
		}
		my_mlx_pixel_put(img_ptr, line->a_x, line->a_y, trgb);
	}
}

/*
** FT_DRAW_LINE
** Draws the specified line with the specified colour
*/

void		ft_draw_line(t_line *line, t_image *img_ptr, int trgb)
{
	double	delta_y;
	double	delta_x;

	delta_y = fabs(line->a_y - line->b_y);
	delta_x = fabs(line->a_x - line->b_x);
	my_mlx_pixel_put(img_ptr, line->a_x, line->a_y, trgb);
	if (delta_y > delta_x)
	{
		line->delta = (line->a_x - line->b_x) / (line->a_y - line->b_y);
		if (line->a_y < line->b_y)
			ft_draw_up_line(line, img_ptr, trgb);
		else
			ft_draw_down_line(line, img_ptr, trgb);
	}
	else
	{
		if (line->a_x < line->b_x)
		{
			ft_draw_right_line(line, img_ptr, trgb);
		}
		else if (line->a_x >= line->b_x)
		{
			ft_draw_left_line(line, img_ptr, trgb);
		}
	}
}
