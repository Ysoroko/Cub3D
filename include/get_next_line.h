/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:55:38 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/26 15:22:45 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

char		*ft_strcpy(char *line);
int			get_next_line(int fd, char **line);
int			ft_save_to_line(char **line, char *str_buff, size_t line_size);
int			ft_free(char *s_buff, char *rem, int s_b_flag, int r_flag);

#endif
