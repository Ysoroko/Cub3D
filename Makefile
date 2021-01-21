# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/21 15:58:16 by ysoroko           #+#    #+#              #
#    Updated: 2021/01/21 16:47:24 by ysoroko          ###   ########.fr        #
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
					\
					map_functions/ft_map_utils.c \
					map_functions/ft_extract_map_info.c \
					map_functions/ft_map_errors.c

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

aclean:
			rm -f $(NAME)




.PHONY:		all clean fclean re bonus