/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:03:16 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/19 17:08:27 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map_functions.h"

t_map	*ft_new_t_map(void)
{
	return (ft_calloc(1, sizeof(t_map)));
}

int		ft_free(char *str1, t_map *map)
{
	if (str1)
	{
		free(str1);
		str1 = 0;
	}
	if (map)
	{
		//to complete
	}
	return (0);
}

/*
** If multiple paths one after the other, the path will be overwritten
*/

int		ft_extract_path(char *str, t_map *map)
{
	int		i;
	char	*path;

	i = 0;
	while (str[i] != ' ')
		i++;
	while (str[i] == ' ')
		i++;
	if (str[0] == 'N' && str[1] == 'O')
		return ((map->north_path = ft_strtrim(&line[i], " ")) != 0);
	if (str[0] == 'S' && str[1] == 'O')
		return ((map->south_path = ft_strtrim(&line[i], " ")) != 0);
	if (str[0] == 'E' && str[1] == 'A')
		return ((map->east_path = ft_strtrim(&line[i], " ")) != 0);
	if (str[0] == 'W' && str[1] == 'E')
		return ((map->west_path = ft_strtrim(&line[i], " ")) != 0);
	if (str[0] == 'S' && str[1] != 'O')
		return ((map->sprite_path = ft_strtrim(&line[i], " ")) != 0);
}

int		ft_path_line(char *str)
{
	if (str[0] == 'N' && str[1] == 'O')
		return (1);
	else if (str[0] == 'S' && str[1] == 'O')
		return (1);
	else if (str[0] == 'E' && str[1] == 'A')
		return (1);
	else if (str[0] == 'W' && str[1] == 'E')
		return (1);
	else if (str[0] == 'S' && str[1] != 'O')
		return (1);
	return (0);
}
