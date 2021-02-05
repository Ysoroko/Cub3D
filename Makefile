# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/21 15:58:16 by ysoroko           #+#    #+#              #
#    Updated: 2021/02/04 18:11:50 by ysoroko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc

SWIFTC			=	swiftc

CFLAGS			=	-Wall -Wextra -Werror

INCLUDE			=	-I include

FRAMEWORKS		=	-lmlx -framework OpenGL -framework AppKit

MINILIBX		=	@ cd minilibx && make ; mv libmlx.a ..

LIBFT			=	@ cd libft && make ;

MAP				=	"maps/map2.cub"

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
					graphic_functions/ft_new_structures.c \
					graphic_functions/ft_window_start.c \
					graphic_functions/ft_rgb_to_trgb.c \
					graphic_functions/ft_image_functions.c \
					graphic_functions/ft_draw_empty_forms.c \
					graphic_functions/ft_draw_filled_in_forms.c \
					graphic_functions/ft_new_geometry_forms.c \
					graphic_functions/ft_hooks_functions.c \
					graphic_functions/ft_error_utils.c \
					graphic_functions/ft_draw_minimap.c \
					\
					libmlx.a \
					\
					main.c \
					

BONUS_SRC		=	SRC \
					bonus/ft_trgb_utils.c

OBJS			=	$(SRC:.c=.o)

NAME			=	cub3D

all: 		$(NAME)

$(NAME):	
			@$(MINILIBX) ;
			@$(CC) $(FRAMEWORKS) $(CFLAGS) $(SRC) $(INCLUDE)  -o $(NAME)

clean:
			@rm -f libmlx.a;
			@rm -f $(NAME)

fclean:		clean
			@cd minilibx && make clean
			@cd libft && make fclean

re:			fclean all

run:		
			@$(MINILIBX)
			@$(LIBFT)
			@$(CC) $(FRAMEWORKS) $(CFLAGS) $(SRC) $(INCLUDE) -o $(NAME) && ./$(NAME) $(MAP)

frun:
			@$(MINILIBX)
			@$(LIBFT)
			@$(CC) $(FRAMEWORKS) $(SRC) $(INCLUDE) -o $(NAME) && ./$(NAME) $(MAP)

.PHONY:		all clean fclean re run frun