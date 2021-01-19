/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:55:38 by ysoroko           #+#    #+#             */
/*   Updated: 2020/12/23 11:15:44 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <limits.h>

char		*ft_strcpy(char *line);
int			get_next_line(int fd, char **line);
size_t		ft_strlen(char *str);
int			ft_save_to_line(char **line, char *str_buff, size_t line_size);
int			ft_free(char *s_buff, char *rem, int s_b_flag, int r_flag);

#endif
