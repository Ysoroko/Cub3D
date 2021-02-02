/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:54:46 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/02 18:39:55 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_map_functions.h"
#include "./include/libft.h"
#include "./include/ft_graphics.h"
#include "./minilibx/mlx.h"

void	ft_print_t_map(t_map *map)
{
	printf ("\n\n\n\n\n");
	printf("------------------------------------------------\n");
	printf("		CONTENTS OF THE MAP				\n");
	printf("------------------------------------------------\n");
	if(!map)
	{
		printf("The resulting t_map is a NULL pointer\n\n");
		return ;
	}
	printf("res_width: %d\n", map->res_width);
	printf("res_height: %d\n", map->res_height);
	printf("north_path: %s\n", map->north_path);
	printf("south_path: %s\n", map->south_path);
	printf("west_path: %s\n", map->west_path);
	printf("east_path: %s\n", map->east_path);
	printf("sprite_path: %s\n", map->sprite_path);
	printf("f_red: %d\n", map->f_red);
	printf("f_green: %d\n", map->f_green);
	printf("f_blue: %d\n", map->f_blue);
	printf("c_red: %d\n", map->c_red);
	printf("c_green: %d\n", map->c_green);
	printf("c_blue: %d\n", map->c_blue);
	printf("player X: %d\n", map->player_x);
	printf("player Y: %d\n", map->player_y);
	printf("map_str: %s\n", map->map_str);
	printf ("\n\n");
	printf("-----------------------\n");
	printf("	The map:\n");
	printf("-----------------------\n\n");
	ft_putstr_tab(map->map_str_tab, 1);
	printf ("\n\n");
	printf("------------------------------------------------\n");
	printf ("\n\n\n\n\n");
}

int	ft_main_errors(int argc, char **argv)
{
	printf(BOLD_RED);
	if (argc < 2)
	{
		printf("Error\n Not enough arguments, please provide the .cub file\n");
		printf(COLOR_RESET);
		return (-1);
	} 
	if (argc > 3)
	{
		printf("Error\n Too many arguments supplied\n");
		printf(COLOR_RESET);
		return (-1);
	}
	if (argv[2] && ft_strlcmp(argv[2], "--save"))
	{
		printf("Error\n Second argument must be \"--save\"\n");
		printf(COLOR_RESET);
		return (-1);
	}
	printf(COLOR_RESET);
	return (0);
}


//1000x420 resolution = segfault to fix
int main(int argc, char **argv)
{
	t_map *map;

	if (ft_main_errors(argc, argv))
		return (-1);
	if (!(map = ft_extract_t_map(argv[1])))
		return (-1);
	ft_print_t_map(map);
	ft_window_start(map);
	//ft_free_map(&map, 0, 0, 0);
	//while (1)
	//{	
	//}
	
	return (0);
}
