# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/21 15:58:16 by ysoroko           #+#    #+#              #
#    Updated: 2021/01/28 14:44:00 by ysoroko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc

SWIFTC			=	swiftc

CFLAGS			=	-Wall -Wextra -Werror

INCLUDE			=	-I include

FRAMEWORKS		=	-l mlx -framework OpenGL -framework AppKit

MINILIBX		=	cd minilibx && make

MAP				=	"maps/map2.cub"

MODULE_SRC=	minilibx/mlx_image.swift \
			minilibx/mlx_window.swift \
			minilibx/mlx_init.swift 

MODULE_OBJ=$(MODULE_SRC:.swift=.swiftmodule)

MLXSRC	=	minilibx/font.c \
			minilibx/mlx_png.c \
			minilibx/mlx_rgb.c \
			minilibx/mlx_string_put.c \
			minilibx/mlx_xpm.c 

MLXOBJS			=	$(MLXSRC:.c = .o)

SRC				=	get_next_line/get_next_line_utils.c \
					get_next_line/get_next_line.c \
					\
					libft/ft_strtrim.c \
					libft/ft_atoi.c \
					libft/ft_isdigit.c \
					libft/ft_strlen.c \
					libft/ft_has_other_chars.c \
					libft/ft_n_ints_in_line.c \
					libft/ft_strchr.c \
					libft/ft_n_chars_in_str.c \
					libft/ft_strdup.c \
					libft/ft_strjoin.c \
					libft/ft_split.c \
					libft/ft_putchar_fd.c \
					libft/ft_putstr_fd.c \
					libft/ft_putendl_fd.c \
					libft/ft_putstr_tab.c \
					libft/ft_longest_strlen_in_strtab.c \
					libft/ft_char_alloc.c \
					libft/ft_str_tab_len.c \
					libft/ft_calloc.c \
					libft/ft_bzero.c \
					libft/ft_n_chars_in_str_tab.c \
					libft/ft_wrong_extension.c \
					libft/ft_strlcmp.c \
					libft/ft_strchrset.c \
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
					graphic_functions/ft_free_and_new_functions.c \
					graphic_functions/ft_window_start.c \
					graphic_functions/ft_rgb_to_trgb.c \
					\
					main.c

OBJS			=	$(SRC:.c=.o)

NAME			=	cub3D

all: 		$(NAME)

$(NAME):	
			$(CC) $(CFLAGS) $(SRC) $(INCLUDE) $(FRAMEWORKS) -o $(NAME)

clean:
			rm -f $(NAME)

fclean:		clean
			cd minilibx && make clean;

re:			fclean all

run:		
			$(CC) $(CFLAGS) $(SRC) $(INCLUDE) $(FRAMEWORKS) -o $(NAME) && ./$(NAME) $(MAP)

frun:
			@ $(MINILIBX) ;
			$(CC) $(SRC) $(INCLUDE) $(FRAMEWORKS) -o $(NAME) && ./$(NAME) $(MAP)


.PHONY:		all clean fclean re run frun