/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:04:05 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/21 16:28:57 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_FUNCTIONS_H
# define MAP_FUNCTIONS_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/*
** T_MAP
** This structure is used to store all the data provided by the .cub map file
*/

typedef struct	s_map
{
	int				res_width;
	int				res_height;
	char			*north_path;
	char			*south_path;
	char			*west_path;
	char			*east_path;
	char			*sprite_path;
	int				f_red;
	int				f_green;
	int				f_blue;
	int				c_red;
	int				c_green;
	int				c_blue;
	char			*map_str;
}				t_map;

/*
** FT_MAP_FUNCTIONS.C
*/

t_map				*ft_extract_map_info(char *file_name);

/*
** FT_MAP_UTILS.C
*/

t_map				*ft_new_t_map(void);
t_map				*ft_free_map(t_map *map);
void				ft_triple_atoi(char *str, int *a, int *b, int *c);
int					ft_extract_path(char *str, t_map *map);
int					ft_path_line(char *str);

#endif
