/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:53:13 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/22 17:07:03 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_map_functions.h"
#include "../include/libft.h"

/*
** FT_CHECK_MAP_LINE_FOR_ERRORS
** This function will check the line knowing we're reading a map line
** and check whether an error is encountered
** Returns the error number or 0 if no errors are encountered
** Note: no empty lines can be encountered after the map is completed
*/

int	ft_check_map_line_for_errors(char *str, t_map *map)
{
	if (!str[0] && map->map_str)
		return (EMPTY_LINE_IN_MAP_ERROR);
	if (ft_has_other_chars(str, "NSEW 012"))
		return (FORBIDDEN_CHARS_ERROR);
	if (str[0] && ft_n_chars_in_str(str, '1') < 2)
		return (MAP_LINE_ERROR);
	return (0);
}
