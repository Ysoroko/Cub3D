/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_to_bmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:29:30 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/26 15:12:30 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

static void		ft_create_bmp_file_header(int height, int stride, int fd)
{
	int				file_size;
	unsigned char	file_header[14];
	int				i;

	i = -1;
	while (++i < 14)
		file_header[i] = 0;
	file_size = 14 + 40 + (stride * height);
	file_header[0] = (unsigned char)('B');
	file_header[1] = (unsigned char)('M');
	file_header[2] = (unsigned char)(file_size);
	file_header[3] = (unsigned char)(file_size >> 8);
	file_header[4] = (unsigned char)(file_size >> 16);
	file_header[5] = (unsigned char)(file_size >> 24);
	file_header[10] = (unsigned char)(14 + 40);
	write(fd, file_header, sizeof(file_header));
}

static void		ft_create_bmp_info_header(int height, int width, int fd)
{
	unsigned char	info_header[40];
	int				i;

	i = -1;
	while (++i < 40)
		info_header[i] = 0;
	info_header[0] = (unsigned char)(40);
	info_header[4] = (unsigned char)(width);
	info_header[5] = (unsigned char)(width >> 8);
	info_header[6] = (unsigned char)(width >> 16);
	info_header[7] = (unsigned char)(width >> 24);
	info_header[8] = (unsigned char)(height);
	info_header[9] = (unsigned char)(height >> 8);
	info_header[10] = (unsigned char)(height >> 16);
	info_header[11] = (unsigned char)(height >> 24);
	info_header[12] = (unsigned char)(1);
	info_header[14] = (unsigned char)(3 * 8);
	write(fd, info_header, sizeof(info_header));
}

static void		ft_get_and_write_colors(int fd, int trgb)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (unsigned char)(ft_get_r(trgb));
	g = (unsigned char)(ft_get_g(trgb));
	b = (unsigned char)(ft_get_b(trgb));
	write(fd, &b, sizeof(b));
	write(fd, &g, sizeof(g));
	write(fd, &r, sizeof(r));
}

void			ft_save_to_bmp(t_graph *graph)
{
	int	fd;
	int	i;
	int	j;
	int	trgb;

	if ((fd = open("save.bmp", O_CREAT | O_WRONLY | O_TRUNC, 77777)) == -1)
		ft_create_fail();
	i = graph->res_height;
	ft_create_bmp_file_header(graph->res_height,
				(graph->res_width * 3)
				+ ((4 - (graph->res_width * 3) % 4) % 4), fd);
	ft_create_bmp_info_header(graph->res_height,
											graph->res_width, fd);
	while (--i >= 0)
	{
		j = graph->res_width;
		while (--j >= 0)
		{
			my_mlx_pixel_get(graph->img_ptr, graph->res_width - j, i, &trgb);
			ft_get_and_write_colors(fd, trgb);
		}
	}
	if (close(fd) < 0)
		ft_close_fail();
	exit(EXIT_SUCCESS);
}
