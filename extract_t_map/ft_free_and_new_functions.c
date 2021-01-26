/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_new_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:40:01 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/26 16:04:49 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_map_functions.h"
#include "../include/libft.h"

/*
** FT_NEW_T_MAP
** This function creates a new t_map structure by using "malloc"
** and sets all of its contents to 0.
** Returns the pointer to the newly created t_map (0 if malloc fails)
*/

t_map	*ft_new_t_map(void)
{
	t_map	*new_map;

	if (!(new_map = malloc(sizeof(t_map))))
		return (0);
	new_map->res_width = -1;
	new_map->res_height = -1;
	new_map->north_path = 0;
	new_map->south_path = 0;
	new_map->west_path = 0;
	new_map->east_path = 0;
	new_map->sprite_path = 0;
	new_map->f_red = -1;
	new_map->f_green = -1;
	new_map->f_blue = -1;
	new_map->c_red = -1;
	new_map->c_green = -1;
	new_map->c_blue = -1;
	new_map->map_str = 0;
	new_map->map_str_tab = 0;
	return (new_map);
}

/*
** FT_FREE_STR
** This function is used to free a string and set its address to 0
*/

void		ft_free_str(char **str)
{
	if (str)
	{
		free(*str);
		*str = 0;
	}
}

/*
** FT_FREE_STR_TAB
** This function is used to free a tab of strings allocated on the heap
** It also sets the str_tab pointer to NULL
** Has no return value
*/

static void		ft_free_str_tab(char ***str_tab)
{
	int	i;

	i = -1;
	if (!(*str_tab))
		return ;
	while ((*str_tab)[++i])
	{
		free((*str_tab)[i]);
		(*str_tab)[i] = 0;
	}
	free(*str_tab);
	*str_tab = 0;
}

/*
** FT_FREE
** This functions frees its arguments and sets them to 0 to avoid double free
** in future
** It always returns a NULL t_map pointer
*/

t_map	*ft_free_map(t_map **map, int error_number, char **str)
{
	if (map && *map)
	{
		ft_free_str(&((*map)->north_path));
		ft_free_str(&((*map)->south_path));
		ft_free_str(&((*map)->east_path));
		ft_free_str(&((*map)->west_path));
		ft_free_str(&((*map)->sprite_path));
		ft_free_str(&((*map)->map_str));
		ft_free_str_tab(&((*map)->map_str_tab));
		free(*map);
		*map = 0;
	}
	if (error_number)
		ft_print_related_error(error_number);
	if (str)
		ft_free_str(str);
	return (0);
}
