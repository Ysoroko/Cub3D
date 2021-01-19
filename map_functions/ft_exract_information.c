/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exract_information.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:01:11 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/19 17:24:30 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map_functions.h"

int		ft_extract_rgb(char *str, t_map *map)
{
	int	i;

	i = 1;
	if (str[0] == 'F')
	{
		map->floor_red = ft_atoi(&(str[1]));
		while (!ft_is_digit(str[i]) && str[i])
			i++;
		while (ft_is_digit(str[i]) && str[i])
			i++
		map->floor_green = ft_atoi(&(str[i]));
		while (!ft_is_digit(str[i]) && str[i])
			i++;
		while (ft_is_digit(str[i]) && str[i])
			i++
		map->floor_blue = ft_atoi(&(str[i]));
	}
	else if (str[0] == 'C')
	{
		map->ceiling_red = ft_atoi(&(str[1]));
		while (!ft_is_digit(str[i]) && str[i])
			i++;
		while (ft_is_digit(str[i]) && str[i])
			i++
		map->ceiling_green = ft_atoi(&(str[i]));
		while (!ft_is_digit(str[i]) && str[i])
			i++;
		while (ft_is_digit(str[i]) && str[i])
			i++
		map->ceiling_blue = ft_atoi(&(str[i]));
	}
	return (1);
}

int		ft_extract_resolution(char *str, t_map *map)
{
	int	i;

	i = 1;
	map->res_width = ft_atoi(&(str[1]));
	while (!ft_is_digit(str[i]) && str[i])
		i++;
	while (ft_is_digit(str[i]) && str[i])
		i++
	map->res_height = ft_atoi(&(str[i]));
	return (1);
}

int		ft_store_info_in_t_map(char *str, t_map *map)
{
	int i;

	i = 1;
	if (str[0] == 'R')
		return (ft_extract_resolution(str, map));
	else if (ft_path_line(str))
		return (ft_extract_path(str, map));
	else if (str[0] == 'F' || str[0] == 'C')
		return (ft_extract_rgb(str, map));
	
}

t_map	*ft_extract_map_info(char *file_name)
{
	int		fd;
	t_map	*map;
	char	*line

	if (!(map = ft_new_t_map()))
		return (0);
	if ((fd = open(file_name)) < 0)
	{
		//TO CHANGE FT_FREE TO FREE ALL THE LISTs
		ft_free(map, 0));
		return (0);
	}
	while (get_next_ine(fd, &line) > 0)
		ft_store_info_in_t_map(line, map);
	return (0);
}
