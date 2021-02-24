/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 12:36:51 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/24 16:24:49 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

/*
** FT_MALLOC_FAIL
** This function is called whenever a malloc called in my program returns 0
** It will display an error message and exit the program, thus freeing
** all the memory allocated on the heap
*/

void	ft_malloc_fail(void)
{
	perror("Error\n Malloc failure\n");
	exit(EXIT_FAILURE);
}

/*
** FT_MLX_FAIL
** This function is called whenever a function of a minilibx library
** returns a failure related value
** It will display an error message and exit the program, thus freeing
** all the memory allocated on the heap
*/

void	ft_mlx_fail(void)
{
	perror("Error\n MLX function failure\n");
	exit(EXIT_FAILURE);
}

/*
** FT_CREATE_FAIL
** This one is called when we couldn't create the "save.bmp" file
*/

void	ft_create_fail(void)
{
	perror("Error\n Couldn't create \"save.bmp\" file\n");
	exit(EXIT_FAILURE);
}

/*
** FT_OPEN_FAIL
** This one is called when we couldn't open the "save.bmp" file
*/

void	ft_open_fail(void)
{
	perror("Error\n Couldn't open \"save.bmp\" file\n");
	exit(EXIT_FAILURE);
}
