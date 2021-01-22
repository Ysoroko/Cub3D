/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 10:53:58 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/22 14:57:42 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_map_functions.h"
#include "../include/libft.h"

static int	ft_check_resolution_errors(char *str, t_map *map)
{
	int	res_width;
	int	res_height;

	if (ft_defined(0, map->res_width, map->res_height, 0))
		return (ALREADY_DEFINED_ERROR);
	if (ft_has_other_chars(str, "R 0123456789\t"))
		return (FORBIDDEN_CHARS_ERROR);
	if (ft_n_ints_in_line(str) != 2)
		return (WRONG_NUMBER_OF_INTS_ERROR);
	ft_triple_atoi(str, &res_width, &res_height, 0);
	if (res_width <= 0 || res_height <= 0)
		return (RESOLUTION_ERROR);
	return (0);
}

static int	ft_check_rgb_errors(char *str, t_map *map)
{
	if (str[0] == 'F')
	{
		if (ft_defined(0, map->f_red, map->f_green, map->f_blue))
			return (ALREADY_DEFINED_ERROR);
		if (ft_has_other_chars(str, "F 0123456789,\t"))
			return (FORBIDDEN_CHARS_ERROR);
	}
	else if (str[0] == 'C')
	{
		if (ft_defined(0, map->c_red, map->c_green, map->c_blue))
			return (ALREADY_DEFINED_ERROR);
		if (ft_has_other_chars(str, "C 0123456789,\t"))
			return (FORBIDDEN_CHARS_ERROR);
	}
	if (ft_n_ints_in_line(str) != 3)
		return (WRONG_NUMBER_OF_INTS_ERROR);
	return (0);
}

static int	ft_check_path_errors(char *str, t_map *map)
{
	if (str[0] == 'N' && str[1] == 'O')
		return (ft_defined(map->north_path, 0, 0, 0));
	if (str[0] == 'S' && str[1] == 'O')
		return (ft_defined(map->south_path, 0, 0, 0));
	if (str[0] == 'E' && str[1] == 'A')
		return (ft_defined(map->east_path, 0, 0, 0));
	if (str[0] == 'W' && str[1] == 'E')
		return (ft_defined(map->west_path, 0, 0, 0));
	if (str[0] == 'S' && str[1] != 'O')
		return (ft_defined(map->sprite_path, 0, 0, 0));
	return (0);
}

int	ft_check_line_for_errors(char *str, t_map *map)
{
	if (!str[0] && !(map->map_str))
		return (0);
	if (!str[0] && (map->map_str))
		return (EMPTY_LINE_IN_MAP_ERROR);
	if (str[0] == 'R')
		return (ft_check_resolution_errors(str, map));
	if (ft_path_line(str))
		return (ft_check_path_errors(str, map));
	if (str[0] == 'C' || str[0] == 'F')
		return (ft_check_rgb_errors(str, map));
	/*if (!(map->map_str) && !ft_is_a_map_line(str))
		return (ft_check_empty_line_errors(str));
		*/
	return (0);
}
