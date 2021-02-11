/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:08:41 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/11 10:19:14 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_map_functions.h"
#include "../include/libft.h"

/*
** FT_FIND_AND_ERASE_PLAYER_POSITION
** This function will extract the player's position represented by "NSWF"
** and stock the found position in *x and *y arguments
** It will also erase the "NSWF" and replace it by a '0' character which
** is needed for the wall surrounding algorhythm
*/

static void	ft_find_player_position(char **str_tab, int *x, int *y)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (str_tab[++i])
	{
		if (ft_strchrset(str_tab[i], "NSEW"))
		{
			*x = i;
			while (str_tab[i][++j])
			{
				if (ft_strchr("NSEW", str_tab[i][j]))
				{
					*y = j;
					return ;
				}
			}
		}
	}
}

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
** This function takes  all the map lines and create a string tab with it
** It then checks the result for errors
** Returns 0 if everything goes smoothly, an int representing the related
** error otherwise
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
	ft_find_player_position(map->map_str_tab, &map->player_x, &map->player_y);
	return (0);
}
