/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:04:05 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/26 18:21:46 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_FUNCTIONS_H
# define FT_MAP_FUNCTIONS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/*
** COLOR MACROS
*/

# define COLOR_RED "\x1b[31m"
# define BOLD_RED "\033[1m\033[31m"
# define COLOR_RESET "\x1b[0m"

/*
** T_MAP
** This structure is used to store all the data provided by the .cub map file
*/

typedef struct		s_map
{
	int		res_width;
	int		res_height;
	char	*north_path;
	char	*south_path;
	char	*west_path;
	char	*east_path;
	char	*sprite_path;
	int		f_red;
	int		f_green;
	int		f_blue;
	int		c_red;
	int		c_green;
	int		c_blue;
	char	*map_str;
	char	**map_str_tab;
}					t_map;

/*
** FT_EXTRACT_T_MAP.C
*/

t_map				*ft_extract_t_map(char *file_name);

/*
** FT_PARAMETERS_UTILS.C
*/

t_map				*ft_new_t_map(void);
void				ft_triple_atoi(char *str, int *a, int *b, int *c);
int					ft_extract_path(char *str, t_map *map);
int					ft_path_line(char *str);

/*
** FT_PARAMETERS_ERRORS.C
*/

int					ft_check_line_for_errors(char *str, t_map *map);

/*
** FT_ERRORS_UTILS.C
*/

t_map				*ft_print_related_error(int n);
int					ft_defined(char *str, int a, int b, int c);
int					ft_after_params(t_map *map);

/*
** FT_MAP_ERRORS_UTILS.C
*/

int					ft_check_map_line_for_errors(char *str, t_map *map);


/*
** FT_MAP_TO_LIST.C
*/

int					ft_extract_map_from_line(char *line, t_map *map);
int					ft_process_map_str(t_map *map);

/*
** FT_FREE_AND_NEW_FUNCTIONS.C
*/

t_map				*ft_free_map(t_map **map, int error, char **str, int *fd);
char				**ft_free_str_tab(char ***str_tab);

/*
** FT_CHECK_STR_TAB_ERRORS
*/

int					ft_check_str_tab_errors(char **str_tab);


/*
** ERROR MACROS
*/

# define OPEN_ERROR 1
# define MALLOC_ERROR 2
# define GNL_OR_CLOSE_ERROR 3
# define WRONG_EMPTY_LINE_ERROR 4
# define ALREADY_DEFINED_ERROR 5
# define FORBIDDEN_CHARS_ERROR 6
# define WRONG_NUMBER_OF_INTS_ERROR 7
# define RESOLUTION_ERROR 8
# define MAP_LINE_ERROR 9
# define NO_WALLS_ERROR 10
# define INCOMPLETE_ERROR 11
# define MULTIPLE_PLAYERS_ERROR 12
# define NO_PLAYER_ERROR 13

# define ERROR_1 "Error\n [1] Couldn't open the provided \".cub\" file"
# define ERROR_2 "Error\n [2] Couldn't allocate heap memory"
# define ERROR_3 "Error\n [3] GNL returned -1 / Couldn't close the \".cub\""
# define ERROR_4 "Error\n [4] Lines between params in \".cub\" must be empty"
# define ERROR_5 "Error\n [5] Multiple lines define same parameter in \".cub\""
# define ERROR_6 "Error\n [6] A line in \".cub\" contains forbidden characters"
# define ERROR_7 "Error\n [7] Wrong number of int arguments in line"
# define ERROR_8 "Error\n [8] Wrong resolution width/height parameters"
# define ERROR_9 "Error\n [9] Error encountered in a map line"
# define ERROR_10 "Error\n [10] The map is not properly surrounded by walls"
# define ERROR_11 "Error\n [11] The \".cub\" file appears to be incomplete"
# define ERROR_12 "Error\n [12] Player has multiple positions in \".cub\" file"
# define ERROR_13 "Error\n [13] No player position found in \".cub\" file"


#endif
