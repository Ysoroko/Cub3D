/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:08:41 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/26 18:26:40 by ysoroko          ###   ########.fr       */
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

int			ft_extract_map_from_line(char *line, t_map *map)
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
** FT_TRANSFORM_STR_TAB
*/

static char	**ft_transform_str_tab(char **str_tab)
{
	int		i;
	int		extra_spaces;
	int		max;
	char	*temp;
	char	**ret_tab;

	i = -1;
	max = ft_longest_strlen_in_strtab(str_tab);
	if (!(ret_tab = ft_calloc(sizeof(*ret_tab), ft_str_tab_len(str_tab) + 1)))
		return (0);
	while (str_tab[++i])
	{
		extra_spaces = max - (int)ft_strlen(str_tab[i]);
		if (!(temp = ft_char_alloc(extra_spaces, ' ')))
			return (ft_free_str_tab(&ret_tab));
		if (!(ret_tab[i] = ft_strjoin(str_tab[i], temp)))
		{
			free(temp);
			return (ft_free_str_tab(&ret_tab));
		}
		free(temp);
	}
	ret_tab[i] = 0;
	return (ret_tab);
}

/*
** FT_PROCESS_MAP_STR
*/

int			ft_process_map_str(t_map *map)
{
	char	**temp;
	int		error;

	if (!ft_after_params(map) || !map->map_str)
		return (INCOMPLETE_ERROR);
	if (!(temp = ft_split(map->map_str, '|')))
		return (MALLOC_ERROR);
	if (!(map->map_str_tab = ft_transform_str_tab(temp)))
	{
		ft_free_str_tab(&temp);
		return (MALLOC_ERROR);
	}
	ft_free_str_tab(&temp);
	if ((error = ft_check_str_tab_errors(map->map_str_tab)) != 0)
		return (error);
	return (0);
}
