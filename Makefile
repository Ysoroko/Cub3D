# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/21 15:58:16 by ysoroko           #+#    #+#              #
#    Updated: 2021/02/23 17:40:31 by ysoroko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror

INCLUDE			=	-I include

BONUS			= 	-D BONUS=1

FRAMEWORKS		=	-lmlx -framework OpenGL -framework AppKit

MINILIBX		=	@ cd minilibx && make ; mv libmlx.a ..

LIBFT			=	@ cd libft && make ;

MAP				=	"maps/map9.cub"

SRC				=	get_next_line/get_next_line_utils.c \
					get_next_line/get_next_line.c \
					\
					libft/libft.a \
					\
					extract_t_map/ft_errors_utils.c \
					extract_t_map/ft_extract_t_map.c \
					extract_t_map/ft_map_errors_utils.c \
					extract_t_map/ft_map_to_list.c \
					extract_t_map/ft_parameters_errors.c \
					extract_t_map/ft_parameters_utils.c \
					extract_t_map/ft_free_and_new_functions.c \
					extract_t_map/ft_check_str_tab_errors.c \
					\
					graphic_functions/draw_functions/ft_draw_filled_in_forms.c \
					graphic_functions/draw_functions/ft_draw_vertical_line.c \
					graphic_functions/draw_functions/ft_draw_line.c \
					\
					graphic_functions/new_free_error_functions/ft_error_utils.c \
					graphic_functions/new_free_error_functions/ft_new_geometry_forms.c \
					graphic_functions/new_free_error_functions/ft_new_structures.c \
					\
					graphic_functions/utils/ft_distance_utils.c \
					graphic_functions/utils/ft_image_functions.c \
					graphic_functions/utils/ft_rgb_to_trgb.c \
					\
					graphic_functions/raycaster/ft_raycaster.c \
					graphic_functions/raycaster/ft_new_raycaster.c \
					graphic_functions/raycaster/ft_ray_textures.c \
					graphic_functions/raycaster/ft_sprites.c \
					graphic_functions/raycaster/ft_new_sprite_ray.c \
					\
					graphic_functions/move_functions/ft_move_in_map.c \
					graphic_functions/move_functions/ft_turn_in_map.c \
					graphic_functions/move_functions/ft_move_bonus.c \
					\
					graphic_functions/ft_window_start.c \
					graphic_functions/ft_hooks_functions.c \
					\
					libmlx.a \
					\
					main.c

BONUS_SRC		=	bonus/ft_music_bonus.c \
					bonus/ft_shadows.c \
					graphic_functions/raycaster/ft_floor_and_ceiling_bonus.c \
					graphic_functions/draw_functions/ft_draw_minimap_bonus.c \

OBJS			=	$(SRC:.c=.o)

NAME			=	cub3D

all: 		$(NAME)

$(NAME):	
			@$(MINILIBX)
			@$(LIBFT)
			@$(CC) $(FRAMEWORKS) $(CFLAGS) $(SRC) $(INCLUDE) -o $(NAME)

bonus:	
			@$(MINILIBX)
			@$(LIBFT)
			@$(CC) $(FRAMEWORKS) $(CFLAGS) $(BONUS) $(SRC) $(BONUS_SRC) $(INCLUDE) -o $(NAME)

clean:
			@cd libft && make clean
			@cd minilibx && make clean
			
fclean:		clean 
			@rm libmlx.a 
			@rm cub3D 
			@cd libft && make fclean 

re:			fclean all

run:		
			@$(MINILIBX)
			@$(LIBFT)
			@$(CC) $(FRAMEWORKS) $(CFLAGS) $(BONUS) $(SRC) $(BONUS_SRC) $(INCLUDE) -o $(NAME) && ./$(NAME) $(MAP)

frun:
			@$(MINILIBX)
			@$(LIBFT)
			@$(CC) $(FRAMEWORKS) $(SRC) $(INCLUDE) -o $(NAME) && ./$(NAME) $(MAP)

.PHONY:		all bonus clean fclean re run frun