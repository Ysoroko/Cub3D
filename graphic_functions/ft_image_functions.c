/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:24:04 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/28 16:09:41 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

/*
** This creates an image structure and fills it with necessary information
*/

t_image	*ft_image(void *mlx_ptr, int width, int height)
{
	t_image *image;

	if (!(image = ft_new_t_image()))
		return (0);
	if (!(image->img = mlx_new_image(mlx_ptr, width, height)))
		return (ft_free_t_image(image));
	if (!(image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
		&image->line_length, &image->endian)))
		return (ft_free_t_image(image));
	return (image);
}

/*
** MY_MLX_PIXEL_PUT
** This is the faster and better version of the mlx_pixel_put
** Allows to print pixels on the screen
*/

void	my_mlx_pixel_put(t_image *image, int x, int y, int trgb_color)
{
	char	*dst;

	dst = image->addr +
		(y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int*)dst = trgb_color;
}
