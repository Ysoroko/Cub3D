/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:54:46 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/26 11:10:39 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_map_functions.h"
#include "./include/libft.h"

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
	printf("map_str: %s\n", map->map_str);
	printf("------------------------------------------------\n");
	printf ("\n\n\n\n\n");
}

int main(void)
{
	t_map *map;

	//while (1)
	//{
	map = ft_extract_map_info("test_map.cub");
	ft_print_t_map(map);
	ft_free_map(&map, 0, 0);
	//}
	
	return (0);
}