/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_str_tab_errors.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:16:33 by ysoroko           #+#    #+#             */
/*   Updated: 2021/03/01 11:27:29 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_map_functions.h"
#include "../include/libft.h"

/*
** FT_CHECK_ZERO_SURROUNDINGS
*/

static int	ft_check_surroundings(char **str_tab, int i, int j)
{
	if (i == 0 || i == ft_str_tab_len(str_tab) - 1)
		return (1);
	if (j == 0 || j == (int)ft_strlen(str_tab[0]) - 1)
		return (1);
	if (str_tab[i + 1][j] == ' ' || str_tab[i][j + 1] == ' ' ||
		str_tab[i + 1][j + 1] == ' ' || str_tab[i - 1][j] == ' '
		|| str_tab[i][j - 1] == ' ' || str_tab[i - 1][j - 1] == ' '
		|| str_tab[i - 1][j + 1] == ' ' || str_tab[i + 1][j - 1] == ' ')
	{
		return (1);
	}
	return (0);
}

/*
** FT_NOT_SURROUNDED_BY_WALLS
*/

static int	ft_not_surrounded_by_walls(char **str_tab)
{
	int i;
	int j;

	i = -1;
	while (str_tab[++i])
	{
		j = -1;
		while (str_tab[i][++j])
		{
			if (ft_strchr("02NSEW", str_tab[i][j]))
			{
				if (ft_check_surroundings(str_tab, i, j))
					return (1);
			}
			if (BONUS == 1 && ft_strchr("345", str_tab[i][j]))
			{
				if (ft_check_surroundings(str_tab, i, j))
					return (1);
			}
		}
	}
	return (0);
}

static int	ft_map_is_opened(char **str_tab)
{
	int	str_tab_width;
	int	str_tab_height;

	str_tab_height = ft_str_tab_len(str_tab);
	str_tab_width = (int)ft_strlen(str_tab[0]);
	if (str_tab_height > MAX_MAP_HEIGHT && str_tab_width > MAX_MAP_WIDTH)
		return (MAP_LIMITS_ERROR);
	if (ft_not_surrounded_by_walls(str_tab))
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

int			ft_check_str_tab_errors(char **str_tab)
{
	int error;

	if ((error = ft_check_player_positions(str_tab)) != 0)
		return (error);
	if ((error = ft_map_is_opened(str_tab)) != 0)
		return (error);
	return (0);
}
