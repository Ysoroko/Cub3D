/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:08:41 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/26 16:41:45 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_map_functions.h"
#include "../include/libft.h"

/*
** FT_EXTRACT_MAP_FROM_LINE
** This function will add the line read to the t_map's "map_str" component
** Returns 0 if everything goes well, or a MALLOC_ERROR int macro if a malloc
** fails somewhere
*/

int	ft_extract_map_from_line(char *line, t_map *map)
{
	char *temp;

	temp = 0;
	if (!line[0])
		return (0);
	if (!(map->map_str))
	{
		if (!(map->map_str = ft_strdup(line)))
			return (MALLOC_ERROR);
		return (0);
	}
	else
	{
		if (!(temp = ft_strjoin(map->map_str, "|")))
			return (MALLOC_ERROR);
		free(map->map_str);
		if (!(map->map_str = ft_strjoin(temp, line)))
		{
			free(temp);
			return (MALLOC_ERROR);
		}
		free(temp);
		return (0);
	}
	return (0);
}

/*
** FT_PROCESS_MAP_STR
*/

int	ft_process_map_str(t_map *map)
{
	if (!(map->map_str_tab = ft_split(map->map_str, '|')))
		return (MALLOC_ERROR);
	return (0);
}
