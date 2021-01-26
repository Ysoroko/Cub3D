/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_str_tab_errors.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:16:33 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/26 18:26:42 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_map_functions.h"
#include "../include/libft.h"

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
	return (0);
}
