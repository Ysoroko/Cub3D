/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_to_bmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:29:30 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/25 14:32:28 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

const int BYTES_PER_PIXEL = 3; /// red, green, & blue
const int FILE_HEADER_SIZE = 14;
const int INFO_HEADER_SIZE = 40;

static void	ft_create_bmp_file_header(int height, int stride, int fd)
{
	int				file_size;
	unsigned char	file_header[FILE_HEADER_SIZE];
	int				i;

	i = -1;
	while (++i < FILE_HEADER_SIZE)
		file_header[i] = 0;
	file_size = FILE_HEADER_SIZE + INFO_HEADER_SIZE + (stride * height);
	file_header[0] = (unsigned char)('B');
	file_header[1] = (unsigned char)('M');
	file_header[2] = (unsigned char)(file_size);
	file_header[3] = (unsigned char)(file_size >> 8);
	file_header[4] = (unsigned char)(file_size >> 16);
	file_header[5] = (unsigned char)(file_size >> 24);
	file_header[10] = (unsigned char)(FILE_HEADER_SIZE + INFO_HEADER_SIZE);
	write(fd, file_header, sizeof(file_header));
}

void	ft_create_bmp_info_header(int height, int width, int fd)
{
	unsigned char	info_header[INFO_HEADER_SIZE];
	int				i;

	i = -1;
	while (++i < INFO_HEADER_SIZE)
		info_header[i] = 0;
	info_header[0] = (unsigned char)(INFO_HEADER_SIZE);
	info_header[4] = (unsigned char)(width);
	info_header[5] = (unsigned char)(width >> 8);
	info_header[6] = (unsigned char)(width >> 16);
	info_header[7] = (unsigned char)(width >> 24);
	info_header[8] = (unsigned char)(height);
	info_header[9] = (unsigned char)(height >> 8);
	info_header[10] = (unsigned char)(height >> 16);
	info_header[11] = (unsigned char)(height >> 24);
	info_header[12] = (unsigned char)(1);
	info_header[14] = (unsigned char)(BYTES_PER_PIXEL * 8);
	write(fd, info_header, sizeof(info_header));
}

void			ft_save_to_bmp(t_graph *graph)
{
	int	fd;
	int	i;
	int	j;
	int	trgb;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if ((fd = open("save.bmp", O_CREAT | O_WRONLY | O_TRUNC, 77777)) == -1)
		ft_create_fail();
	i = graph->res_height;
	ft_create_bmp_file_header(graph->res_height,
				(graph->res_width * BYTES_PER_PIXEL)
				+ ((4 - (graph->res_width * BYTES_PER_PIXEL) % 4) % 4), fd);
	ft_create_bmp_info_header(graph->res_height,
											graph->res_width, fd);
	while (--i >= 0)
	{
		j = graph->res_width;
		while (--j >= 0)
		{
			my_mlx_pixel_get(graph->img_ptr, graph->res_width - j, i, &trgb);
			b = (unsigned char)(ft_get_b(trgb));
			g = (unsigned char)(ft_get_g(trgb));
			r = (unsigned char)(ft_get_r(trgb));
			write(fd, &b, sizeof(r));
			write(fd, &g, sizeof(g));
			write(fd, &r, sizeof(b));
		}
	}
	if (close(fd) < 0)
		ft_close_fail();
	exit(EXIT_SUCCESS);
}
