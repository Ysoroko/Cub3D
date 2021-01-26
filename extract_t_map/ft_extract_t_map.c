/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_t_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 10:51:31 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/26 16:44:06 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_map_functions.h"
#include "../include/libft.h"
#include "../include/get_next_line.h"

/*
** FT_EXTRACT_RGB
** This function is used when the line starts with 'F' or 'C'
** It extracts the related rgb data and stores it in the t_map structure
** Returns 0
*/

static int		ft_extract_rgb(char *str, t_map *map)
{
	if (str[0] == 'F')
		ft_triple_atoi(str, &(map->f_red), &(map->f_green), &(map->f_blue));
	else if (str[0] == 'C')
		ft_triple_atoi(str, &(map->c_red), &(map->c_green), &(map->c_blue));
	return (0);
}

/*
** FT_EXTRACT_RESOLUTION
** This function is used when the first character of the line is 'R'.
** It extracts the resolution and stores it in the corresponding elements
** of the t_map argument
** Returns 0
*/

static int		ft_extract_resolution(char *str, t_map *map)
{
	ft_triple_atoi(str, &map->res_width, &map->res_height, 0);
	return (0);
}

/*
** FT_STORE_INFO_IN_T_MAP
** This function checks every line extracted by get_next_line
** and if it is a line that defines an information about the map,
** it stores the information in the corresponding element of t_map
** Returns a corresponding error number if an error was encountered
** or 0 if everything went well (or no info is to be extracted from the line)
*/

static int		ft_store_info_in_t_map(char *str, t_map *map)
{
	int	error;
	int after_params;

	after_params = ft_after_params(map);

	if (!after_params)
	{
		if ((error = ft_check_line_for_errors(str, map)) != 0)
			return (error);
		if (str[0] == 'R')
			return (ft_extract_resolution(str, map));
		if (ft_path_line(str))
			return (ft_extract_path(str, map));
		if (str[0] == 'F' || str[0] == 'C')
			return (ft_extract_rgb(str, map));
	}
	else if (after_params)
	{
		if ((error = ft_check_map_line_for_errors(str, map)) != 0)
			return (error);
		return (ft_extract_map_from_line(str, map));
	}
	return (0);
}

/*
** FT_EXTRACT_T_MAP
** This function is the central hub of translating the .cub map file in a t_map
** It returns the results of this translation or a NULL pointer
** if an error was encountered
*/

t_map			*ft_extract_t_map(char *file_name)
{
	int		fd;
	int		gnl_ret;
	int		error;
	t_map	*map;
	char	*line;

	if (!file_name || ((fd = open(file_name, O_RDONLY)) < 0))
		return (ft_print_related_error(OPEN_ERROR));
	if (!(map = ft_new_t_map()))
		return (ft_free_map(0, MALLOC_ERROR, 0, &fd));
	while ((gnl_ret = get_next_line(fd, &line)) >= 0)
	{
		if ((error = ft_store_info_in_t_map(line, map)) != 0)
			return (ft_free_map(&map, error, &line, &fd));
		free(line);
		if (!gnl_ret)
			break ;
	}
	if (close(fd) < 0 || gnl_ret < 0)
		return (ft_free_map(&map, GNL_OR_CLOSE_ERROR, &line, 0));
	if ((error = ft_process_map_str(map)) != 0)
		return (ft_free_map(&map, error, &line, 0));
	return (map);
}
