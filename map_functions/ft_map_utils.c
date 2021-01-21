/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:03:16 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/21 17:32:22 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_map_functions.h"
#include "../include/libft.h"

/*
** FT_NEW_T_MAP
** This function creates a new t_map structure by using "malloc"
** and sets all of its contents to 0.
** Returns the pointer to the newly created t_map (0 if malloc fails)
*/

t_map	*ft_new_t_map(void)
{
	t_map	*new_map;

	if (!(new_map = malloc(sizeof(t_map))))
		return (0);
	new_map->res_width = 0;
	new_map->res_height = 0;
	new_map->north_path = 0;
	new_map->south_path = 0;
	new_map->west_path = 0;
	new_map->east_path = 0;
	new_map->sprite_path = 0;
	new_map->f_red = 0;
	new_map->f_green = 0;
	new_map->f_blue = 0;
	new_map->c_red = 0;
	new_map->c_green = 0;
	new_map->c_blue = 0;
	new_map->map_str = 0;
	return (new_map);
}

/*
** FT_FREE
** This functions frees its arguments and sets them to 0 to avoid double free
** in future
*/

t_map	*ft_free_map(t_map **map, int error_number, char **str)
{
	if (map && *map)
	{
		free((*map)->north_path);
		(*map)->north_path = 0;
		free((*map)->south_path);
		(*map)->south_path = 0;
		free((*map)->east_path);
		(*map)->east_path = 0;
		free((*map)->west_path);
		(*map)->west_path = 0;
		free((*map)->sprite_path);
		(*map)->sprite_path = 0;
		free(*map);
		*map = 0;
	}
	if (error_number)
		ft_print_related_error(error_number);
	if (str && *str)
	{
		free(*str);
		*str = 0;
	}
	return (0);
}

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
** Returns 0 if the malloc fails or the line is invalid
** If multiple paths one after the other, the path will be overwritten
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
		return ((map->north_path = ft_strtrim(&(str[i]), " ")) != 0);
	if (str[0] == 'S' && str[1] == 'O')
		return ((map->south_path = ft_strtrim(&(str[i]), " ")) != 0);
	if (str[0] == 'E' && str[1] == 'A')
		return ((map->east_path = ft_strtrim(&(str[i]), " ")) != 0);
	if (str[0] == 'W' && str[1] == 'E')
		return ((map->west_path = ft_strtrim(&(str[i]), " ")) != 0);
	if (str[0] == 'S' && str[1] != 'O')
		return ((map->sprite_path = ft_strtrim(&(str[i]), " ")) != 0);
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
	if (str[0] == 'S' && str[1] != 'O')
		return (1);
	return (0);
}
