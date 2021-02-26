# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/21 15:58:16 by ysoroko           #+#    #+#              #
#    Updated: 2021/02/26 16:38:41 by ysoroko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror

INCLUDE			=	-I include

BONUS			=	-D BONUS=1

SAVE			=	--save

FRAMEWORKS		=	-lmlx -framework OpenGL -framework AppKit

MINILIBX		=	@ cd minilibx && make ; mv libmlx.a ..

LIBFT			=	@ cd libft && make ;

BONUS_MAP		=	"maps/ultimate_bonus_map.cub"

STANDARD_MAP	=	"maps/map9.cub"

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
					\
					graphic_functions/ft_window_start.c \
					graphic_functions/ft_hooks_functions.c \
					\
					save/ft_extract_rgb.c \
					save/ft_save_to_bmp.c \
					\
					libmlx.a \
					\
					main.c

BONUS_SRC		=	bonus/ft_music_bonus.c \
					bonus/ft_shadows_bonus.c \
					bonus/ft_hud_bonus.c \
					bonus/ft_damage_bonus.c \
					bonus/ft_knife_bonus.c \
					bonus/ft_floor_and_ceiling_bonus.c \
					bonus/ft_draw_minimap_bonus.c \
					bonus/ft_move_bonus.c \
					bonus/ft_new_raycaster_bonus.c \
					bonus/ft_draw_line_bonus.c \
					bonus/ft_free_sprite_ray_bonus.c 


OBJS			=	$(SRC:.c=.o)

NAME			=	cub3D

all: 		$(NAME)

$(NAME):	
			@$(LIBFT)
			@$(CC) $(FRAMEWORKS) $(CFLAGS) $(SRC) $(INCLUDE) -o $(NAME)

bonus:	
			@$(LIBFT)
			@$(CC) $(FRAMEWORKS) $(CFLAGS) $(BONUS) $(SRC) $(BONUS_SRC) $(INCLUDE) -o $(NAME)

clean:
			@cd libft && make clean
			
fclean:		clean 
			@rm -rf cub3D 
			@rm -rf save.bmp
			@cd libft && make fclean 

re:			fclean all

run:
			@$(LIBFT)
			@$(CC) $(FRAMEWORKS) $(SRC) $(INCLUDE) -o $(NAME) && ./$(NAME) $(STANDARD_MAP)
			
brun:		
			@$(LIBFT)
			@$(CC) $(FRAMEWORKS) $(CFLAGS) $(BONUS) $(SRC) $(BONUS_SRC) $(INCLUDE) -o $(NAME) && ./$(NAME) $(BONUS_MAP)

frun:
			@$(LIBFT)
			@$(CC) $(FRAMEWORKS) $(BONUS) $(SRC) $(BONUS_SRC) $(INCLUDE) -o $(NAME) && ./$(NAME) $(BONUS_MAP)

save:
			@$(LIBFT)
			@$(CC) $(FRAMEWORKS) $(SRC) $(INCLUDE) -o $(NAME) && ./$(NAME) $(STANDARD_MAP) $(SAVE)

.PHONY:		all bonus clean fclean re run brun frun save