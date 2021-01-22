/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:11:52 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/22 16:57:00 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_map_functions.h"
#include "../include/libft.h"

/*
** FT_PRINT_RELATED_ERROR
** This function will take an error number as an argument and print the related
** error string defined in "ft_map_functions.h" header
*/

t_map	*ft_print_related_error(int n)
{
	printf(BOLD_RED);
	if (n == 1)
		printf("%s\n", ERROR_1);
	else if (n == 2)
		printf("%s\n", ERROR_2);
	else if (n == 3)
		printf("%s\n", ERROR_3);
	else if (n == 4)
		printf("%s\n", ERROR_4);
	else if (n == 5)
		printf("%s\n", ERROR_5);
	else if (n == 6)
		printf("%s\n", ERROR_6);
	else if (n == 7)
		printf("%s\n", ERROR_7);
	else if (n == 8)
		printf("%s\n", ERROR_8);
	else if (n == 9)
		printf("%s\n", ERROR_9);
	else if (n == 10)
		printf("%s\n", ERROR_10);
	printf(COLOR_RESET);
	return (0);
}

/*
** FT_DEFINED
** This function will check if the specified arguments are already defined
** 1st argument is a string, 3 others are int to be able to verify
** any possible line containing parameters
** It will return 1 if any is defined, 0 otherwise
*/

int		ft_defined(char *str, int a, int b, int c)
{
	if (str || a || b || c)
		return (ALREADY_DEFINED_ERROR);
	return (0);
}

/*
** FT_AFTER_PARAMS
** This function checks if the t_map structure is filled in
** so we can pass to the second phase of analysing the .cub file
** and reading the map
** Returns:
** 1 if we have already analysed all but not the map (can have empty lines)
** 0 if it's not the case
*/

int		ft_after_params(t_map *map)
{
	if (map->res_width && map->res_height && map->north_path && map->south_path
		&& map->east_path && map->west_path && map->sprite_path
		&& (map->f_red || map->f_green || map->f_blue)
		&& (map->c_red || map->c_green || map->c_blue))
	{
		return (1);
	}
	return (0);
}

/*
** FT_LINE_HAS_PLAYER_POSITION
** Checks if the line contains "N/S/W/E" chars and returns 1 if so, 0 otherwise
*/

int		ft_line_has_player_position(char *line)
{
	if (ft_strchr(line, 'S') || ft_strchr(line, 'N') || ft_strchr(line, 'E')
		|| ft_strchr(line, 'W'))
	{
		return (1);
	}
	return (0);
}
