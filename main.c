/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:54:46 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/28 16:10:08 by ysoroko          ###   ########.fr       */
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

/*
	#include mlx.h

	void	*mlx_init()	-------	establish connection between the software and display. Returns a *void identifier

	void *
       mlx_new_window ( void *mlx_ptr, int size_x, int size_y, char *title ); -- Returns NULL if fails, window identifier otherwise

    int
       mlx_clear_window ( void *mlx_ptr, void *win_ptr ); ------ clears the window (in black) -- Returns nothing

    int
       mlx_destroy_window ( void *mlx_ptr, void *win_ptr ); ------ destroys the window -- Returns nothing

	int
       mlx_pixel_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color ); ----	draws a pixel

       int
       mlx_string_put  (  void  *mlx_ptr, void *win_ptr, int x, int y, int color,
       char *string );


	int		mlx_loop(void * mlx_ptr)	-----	infinite loop waits for an event (key/mouse pressed / redraw part of the window (=expose))
										
	int		mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param)	------	(*f_ptr is the call to the function called when
	int		mlx_mouse_hook(void *win_ptr, int (*funct_ptr)(), void *param)			the event occurs, specific to the window defined
	int		mlx_expose_hook(void *win_ptr, int (*funct_ptr)(), void *param)			by *win_ptr. *param is used to store the params
																					it might need)
	
	int		mlx_loop_hook(void *win_ptr, int (*funct_ptr)(), void *param)	------	the given function will be called when no event occurs

	When it catches an event, the MiniLibX calls  the  corresponding  function
       with fixed parameters:

         expose_hook(void *param);
         key_hook(int keycode, void *param);
         mouse_hook(int button, int x, int y, void *param);
         loop_hook(void *param);

	param  is  the  address specified in the mlx_*_hook calls. This address is
       never used nor modified by the MiniLibX. On key and  mouse  events,  addi-
       tional information is passed: keycode tells you which key is pressed (with
       X11, look for the include file "keysymdef.h", with MacOS, just try :) ), (
       x  ,  y ) are the coordinates of the mouse click in the window, and button
       tells you which mouse button was pressed.
*/