/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:15:39 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/24 16:02:34 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BMP_H
# define FT_BMP_H

typedef struct      s_bmp_h
{
    unsigned int    bfsize;
    unsigned short  bfreserved1;
    unsigned short  bfreserved2;
    unsigned int    bfoffbits;
}                   t_bmp_h;

typedef struct      s_bmp_i
{
    unsigned int    bisize;
    int             biwidth;
    int             biheight;
    unsigned short  biplanes;
    unsigned short  bibitcount;
    unsigned int    bicompression;
    unsigned int    bisizeimage;
    int             bixpixelspermeter;
    int             biypixelspermeter;
    unsigned int    biclrused;
    unsigned int    biclrimportant;
}                   t_bmp_i;

#endif