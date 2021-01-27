/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_str_tab_errors.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:16:33 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/27 13:20:38 by ysoroko          ###   ########.fr       */
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

static void	ft_find_and_erase_player(char **str_tab, int *x, int *y)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (str_tab[++i])
	{
		if (ft_strchrset(str_tab[i], "NSEW"))
		{
			*y = i;
			while (str_tab[i][++j])
			{
				if (ft_strchr("NSEW", str_tab[i][j]))
				{
					*x = j;
					str_tab[i][j] = '0';
					return ;
				}
			}
		}
	}
}

/*
** FT_NOT_SURROUNDED_BY_WALLS
*/

static int	ft_not_surrounded_by_walls(char **str_tab, int x, int y, int *open)
{
	if (*open == 1)
		return (1);
	if (str_tab[x][y] == ' ')
	{
		*open = 1;
		return (1);
	}
	if (x < 0 || y < 0 || y > (int)ft_strlen(str_tab[0]) ||
		x > (int)ft_str_tab_len(str_tab) || str_tab[x][y] != '0')
		return (0);
	str_tab[x][y] = '*';
	ft_not_surrounded_by_walls(str_tab, x + 1, y, open);
	ft_not_surrounded_by_walls(str_tab, x, y + 1, open);
	ft_not_surrounded_by_walls(str_tab, x + 1, y + 1, open);
	ft_not_surrounded_by_walls(str_tab, x - 1, y, open);
	ft_not_surrounded_by_walls(str_tab, x, y - 1, open);
	ft_not_surrounded_by_walls(str_tab, x - 1, y - 1, open);
	ft_not_surrounded_by_walls(str_tab, x + 1, y - 1, open);
	ft_not_surrounded_by_walls(str_tab, x - 1, y + 1, open);
	return (0);
}

static int	ft_map_is_opened(char **str_tab, t_map *map)
{
	int	open;

	open = 0;
	ft_find_and_erase_player(str_tab, &(map->player_x), &(map->player_y));
	ft_not_surrounded_by_walls(str_tab, map->player_x, map->player_y, &open);
	if (open)
		return (NO_WALLS_ERROR);
	return (0);
}

static int	ft_check_player_positions(char **str_tab)
{
	int n;
	int s;
	int e;
	int w;

	n = ft_n_chars_in_str_tab(str_tab, 'N');
	s = ft_n_chars_in_str_tab(str_tab, 'S');
	e = ft_n_chars_in_str_tab(str_tab, 'E');
	w = ft_n_chars_in_str_tab(str_tab, 'W');
	if (!n && !s && !e && !w)
		return (NO_PLAYER_ERROR);
	if (n > 1 || s > 1 || e > 1 || w > 1)
		return (MULTIPLE_PLAYERS_ERROR);
	if ((n && (s || e || w)) || (s && (n || e || w))
		|| (e && (n || s || w)) || (w && (n || e || s)))
	{
		return (MULTIPLE_PLAYERS_ERROR);
	}
	return (0);
}

/*
** FT_CHECK_STR_TAB_ERRORS
*/

int			ft_check_str_tab_errors(char **str_tab, t_map *map)
{
	int error;

	if ((error = ft_check_player_positions(str_tab)) != 0)
		return (error);
	if ((error = ft_map_is_opened(str_tab, map)) != 0)
		return (error);
	return (0);
}
