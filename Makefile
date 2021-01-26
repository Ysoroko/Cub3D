# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/21 15:58:16 by ysoroko           #+#    #+#              #
#    Updated: 2021/01/26 12:13:35 by ysoroko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror

INCLUDE			=	-I include

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
					\
					extract_t_map/ft_parameters_utils.c \
					extract_t_map/ft_extract_t_map.c \
					extract_t_map/ft_errors_utils.c \
					extract_t_map/ft_map_utils.c \
					extract_t_map/ft_parameters_errors.c

OBJS			=	$(SRC:.c=.o)

NAME			=	cub3D

all: 		$(NAME)

$(NAME):	
			$(CC) $(CFLAGS) $(SRC) main.c && ./a.out

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

run:		
			$(CC) $(CFLAGS) $(SRC) main.c $(INCLUDE) -o $(NAME) && ./$(NAME)

frun:
			$(CC) $(SRC) main.c $(INCLUDE) -o $(NAME) && ./$(NAME)

aclean:
			rm -f $(NAME)




.PHONY:		all clean fclean re bonus