/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parameters_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:03:16 by ysoroko           #+#    #+#             */
/*   Updated: 2021/03/01 11:54:02 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_map_functions.h"
#include "../include/libft.h"

/*
** FT_TRIPLE_ATOI
** This function allows to extract up to 3 integers from a string using ft_atoi
** It is used to extract the resolution (width and height) and the RGB
** components of ceiling and floor colors. To enter this function, the line
** must start with "R/C/F"
** This function has no return value, but will modify the provided *ints
** if they aren't null pointers
*/

void	ft_triple_atoi(char *str, int *a, int *b, int *c)
{
	int	i;

	i = 1;
	if (a)
	{
		while (str[i] && !ft_isdigit(str[i]))
			i++;
		*a = ft_atoi(&(str[1]));
	}
	if (b)
	{
		while (str[i] && ft_isdigit(str[i]))
			i++;
		while (str[i] && !(ft_isdigit(str[i])))
			i++;
		*b = ft_atoi(&(str[i]));
	}
	if (c)
	{
		while (str[i] && ft_isdigit(str[i]))
			i++;
		while (str[i] && !(ft_isdigit(str[i])))
			i++;
		*c = ft_atoi(&(str[i]));
	}
}

/*
** FT_EXTRACT_PATH
** This function is applied when the first 1/2 characters of the line
** are "NO/SO/EA/WE/S"
** It extracts the path from the line and mallocs a copy of it.
** Returns 1 if the malloc fails or the line is invalid, 0 otherwise
*/

int		ft_extract_path(char *str, t_map *map)
{
	int		i;

	i = 0;
	while (str[i] != ' ' && str[i])
		i++;
	while (str[i] == ' ')
		i++;
	if (str[0] == 'N' && str[1] == 'O')
		return ((map->north_path = ft_strtrim(&(str[i]), " ")) == 0);
	if (str[0] == 'S' && str[1] == 'O')
		return ((map->south_path = ft_strtrim(&(str[i]), " ")) == 0);
	if (str[0] == 'E' && str[1] == 'A')
		return ((map->east_path = ft_strtrim(&(str[i]), " ")) == 0);
	if (str[0] == 'W' && str[1] == 'E')
		return ((map->west_path = ft_strtrim(&(str[i]), " ")) == 0);
	if (str[0] == 'S' && str[1] != 'O')
		return ((map->sprite_path = ft_strtrim(&(str[i]), " ")) == 0);
	return (0);
}

/*
** FT_PATH_LINE
** This function can determine whether the string argument is a line
** containing a path
** Lines containing a path start with "NO/SO/EA/WE/S"
** Returns 1 if the string argument is a path line, 0 otherwise
*/

int		ft_path_line(char *str)
{
	if (!str || !str[0])
		return (0);
	if (str[0] == 'N' && str[1] == 'O')
		return (1);
	if (str[0] == 'S' && str[1] == 'O')
		return (1);
	if (str[0] == 'E' && str[1] == 'A')
		return (1);
	if (str[0] == 'W' && str[1] == 'E')
		return (1);
	if (str[0] == 'S' && str[1] == ' ')
		return (1);
	return (0);
}
