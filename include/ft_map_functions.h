/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:04:05 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/21 17:36:57 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_FUNCTIONS_H
# define MAP_FUNCTIONS_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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
t_map				*ft_free_map(t_map **map, int error_number, char **str);
void				ft_triple_atoi(char *str, int *a, int *b, int *c);
int					ft_extract_path(char *str, t_map *map);
int					ft_path_line(char *str);

/*
** FT_MAP_ERRORS.C
*/

t_map				*ft_print_related_error(int n);


# define ERROR_1 "Error\n [1]: Couldn't open the \".cub\" file\n"
# define ERROR_2 "Error\n [2]: Couldn't allocate heap memory\n"
# define ERROR_3 "Error\n [3]: Get_next_line returned -1\n"
# define ERROR_4 "Error\n [4]: Couldn't close the \".cub\"\n"


#endif
