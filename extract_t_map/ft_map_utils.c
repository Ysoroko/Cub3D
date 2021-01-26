/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:53:13 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/26 12:42:09 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_map_functions.h"
#include "../include/libft.h"

/*
** FT_INVALID_LAST_CHAR_BEFORE_SPACE
** As its name suggets, this function will check the line and try to find a an
** invalid character before ' ' (anything other than a '1')
** Returns 1 if it finds such an error, 0 otherwise
*/

static int	ft_invalid_last_char_before_space(char *line)
{
	int i;

	i = 0;
	if (!line[0])
		return (0);
	if (line[0] == ' ')
		i++;
	while (line[i])
	{
		while (line[i] && line[i] != ' ')
			i++;
		if (ft_strchr("02NSEW", line[i - 1]))
			return (1);
		if (line[i])
			i++;
		else
			break ;
	}
	return (0);
}

/*
** FT_INVALID_FIRST_CHAR_AFTER_SPACE
** As its name suggets, this function will check the line and try to find a an
** invalid character after ' ' (anything other than a '1')
** Returns 1 if it finds such an error, 0 otherwise
*/

static int	ft_invalid_first_char_after_space(char *line)
{
	int i;

	i = 0;
	if (!line[0])
		return (0);
	if (ft_strchr("02NSEW", line[0]))
		return (1);
	while (line[i])
	{
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i - 1] && line[i - 1] == ' ' && ft_strchr("02NSEW", line[i]))
			return (1);
		if (line[i])
			i++;
		else
			break ;
	}
	return (0);
}

/*
** FT_MULTIPLE_PLAYER_CHARS_IN_LINE
** This function checks if we have multiple player locations in one line
** (any combination of N/S/E/W chars in the same line)
** Returns 1 if yes, 0 otherwise
*/

static int	ft_multiple_player_chars_in_line(char *line)
{
	if (ft_strchr(line, 'N') && (ft_strchr(line, 'S') ||
		ft_strchr(line, 'E') || ft_strchr(line, 'W') ||
		ft_n_chars_in_str(line, 'N') > 1))
		return (1);
	if (ft_strchr(line, 'S') && (ft_strchr(line, 'N') ||
		ft_strchr(line, 'E') || ft_strchr(line, 'W') ||
		ft_n_chars_in_str(line, 'S') > 1))
		return (1);
	if (ft_strchr(line, 'E') && (ft_strchr(line, 'S') ||
		ft_strchr(line, 'N') || ft_strchr(line, 'W') ||
		ft_n_chars_in_str(line, 'E') > 1))
		return (1);
	if (ft_strchr(line, 'W') && (ft_strchr(line, 'S') ||
		ft_strchr(line, 'E') || ft_strchr(line, 'N') ||
		ft_n_chars_in_str(line, 'W') > 1))
		return (1);
	return (0);
}

/*
** FT_CHECK_MAP_LINE_FOR_ERRORS
** This function will check the line knowing we're reading a map line
** and check whether an error is encountered
** Returns the error number or 0 if no errors are encountered
** Note: no empty lines can be encountered after the map is completed
*/

int			ft_check_map_line_for_errors(char *line, t_map *map)
{
	if (!line[0] && !map->map_str)
		return (0);
	if ((!line[0] || !ft_strchr(line, '1')) && map->map_str)
		return (MAP_LINE_ERROR);
	if (ft_has_other_chars(line, "NSEW 012"))
		return (FORBIDDEN_CHARS_ERROR);
	if (line[0] && ft_n_chars_in_str(line, '1') < 2 && ft_strchr(line, '0'))
		return (NO_WALLS_ERROR);
	if (ft_invalid_last_char_before_space(line) ||
		ft_invalid_first_char_after_space(line))
		return (NO_WALLS_ERROR);
	if (ft_multiple_player_chars_in_line(line))
		return (MAP_LINE_ERROR);
	return (0);
}
