/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:04:05 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/19 17:10:59 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_FUNCTIONS_H
# define MAP_FUNCTIONS_H

#include <fcntl.h>
#include <unistd.h>

/*
** T_MAP
** This structure is used to store all the data provided by the .cub map file
*/

typedef struct	s_map
{
	int				*res_width;
	int				*res_height;
	char			*north_path;
	char			*south_path;
	char			*west_path;
	char			*east_path;
	char			*sprite_path;
	int				floor_red;
	int				floor_green;
	int				floor_blue;
	int				ceiling_red;
	int				ceiling_green;
	int				ceiling_blue;
	char			*map_str;
}				t_map;

/*
** FT_MAP_FUNCTIONS
*/

t_map	ft_new_t_map(void);
int		ft_store_info_in_t_map(char *str, t_map *map);

#endif
