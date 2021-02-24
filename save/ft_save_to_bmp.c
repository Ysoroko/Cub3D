/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_to_bmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:29:30 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/24 16:39:29 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"
#include "../include/ft_bmp.h"

static void	ft_init_bmp(t_bmp_h *bfh, t_bmp_i *bih, t_graph *graph)
{
	bfh->bfreserved1 = 0;
	bfh->bfreserved2 = 0;
	bfh->bfsize = 2 + sizeof(t_bmp_h) + sizeof(t_bmp_i) +
	graph->res_width * graph->res_height * 3;
	bfh->bfoffbits = 0x36;
	bih->bisize = sizeof(t_bmp_i);
	bih->biwidth = graph->res_width;
	bih->biheight = graph->res_height;
	bih->biplanes = 1;
	bih->bibitcount = 24;
	bih->bicompression = 0;
	bih->bisizeimage = 0;
	bih->bixpixelspermeter = 0;
	bih->biypixelspermeter = 0;
	bih->biclrused = 0;
	bih->biclrimportant = 0;
}

static int	ft_setup(t_graph *graph)
{
	t_bmp_h	*bfh;
	t_bmp_i	*bih;
	int		fd;

	if (!(bfh = malloc(sizeof(t_bmp_h))))
		ft_malloc_fail();
	if (!(bih = malloc(sizeof(t_bmp_i))))
		ft_malloc_fail();
	if (open("save.bmp", O_CREAT | O_WRONLY | O_TRUNC, 77777) == -1)
		ft_create_fail();
	if ((fd = open("save.bmp", O_WRONLY)) == -1)
		ft_open_fail();
	ft_init_bmp(bfh, bih, graph);
	write(fd, "0x4d42", 6);
	return (fd);
}

void		ft_save_to_bmp(t_graph *graph)
{
	int		trgb;
	int		fd;

	ft_setup(graph);
}
