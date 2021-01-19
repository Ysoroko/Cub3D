/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:53:13 by ysoroko           #+#    #+#             */
/*   Updated: 2020/12/23 11:18:12 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
** Returns the position of '\n' in the string, -1 otherwise
*/

static int		ret_in_str(char *str)
{
	int i;

	if (str == 0)
		return (-1);
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

/*
** When there is a '\n' in the middle of the saved line, it saves all after
** the first '\n' encountered in the static remainer and returns its address
*/

static char		*save_remainer(char **line, int i)
{
	char	*remainer;
	int		remainer_size;
	int		j;

	j = 0;
	remainer_size = ft_strlen(&(*line)[i + 1]);
	if (!(remainer = malloc(sizeof(*remainer) * (remainer_size + 1))))
		return (0);
	while ((*line)[i + 1] != 0)
	{
		remainer[j] = (*line)[i + 1];
		i++;
		j++;
	}
	remainer[j] = 0;
	(*line)[ret_in_str(*line)] = 0;
	return (remainer);
}

/*
** 2 possible cases:
** -Remainer has no '\n' inside, then we just copy it to *line. Returns 2.
** -Remainer has a '\n' inside, then we copy all until it and stop gnl. Ret = 1.
** Returns -1 if an error was encountered
*/

static int		ft_copy_from_remainer(char **rem, char **line, size_t *line_s)
{
	char	*temp_remainer;
	int		n;

	temp_remainer = 0;
	if (ret_in_str(*rem) < 0)
	{
		*line_s = ft_strlen(*rem);
		if (!ft_save_to_line(line, *rem, *line_s))
			return (-1);
		free(*rem);
		return (2);
	}
	else
	{
		n = ret_in_str(*rem);
		if (!(temp_remainer = ft_strcpy(&(*rem)[n + 1])))
			return (-1);
		(*rem)[n] = 0;
		*line_s = ft_strlen(*rem);
		if (!ft_save_to_line(line, *rem, *line_s))
			return (ft_free(temp_remainer, 0, 1, 0) - 1);
		free(*rem);
		*rem = temp_remainer;
		return (1);
	}
}

/*
** Checks if there is a remainer left from the previous call of get_next_line.
** If there's a remainer, uses ft_copy_from_remainer and returns its value
** If there is no remainer, returns 0
** Returns -1 in case of error
*/

ssize_t			ft_remainer(char **rem, char **line, size_t *l_s, char **s_buff)
{
	int	r;

	*l_s = 0;
	if (*rem != 0)
	{
		r = ft_copy_from_remainer(rem, line, l_s);
		if (r == 1 || r == -1)
			return (ft_free(*s_buff, *rem, 1, 0 - r) + r);
		*rem = 0;
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*remainer[OPEN_MAX];
	char		*str_buff;
	ssize_t		read_ret;
	size_t		line_size;

	if (!(str_buff = malloc(sizeof(*str_buff) * (BUFFER_SIZE + 1)))
		|| fd <= -1 || fd > OPEN_MAX || line == 0 || BUFFER_SIZE <= 0)
		return (ft_free(str_buff, remainer[fd], 1, 1) - 1);
	*line = 0;
	if ((read_ret = ft_remainer(&(remainer[fd]), line, &line_size, &str_buff)))
		return ((int)read_ret);
	while ((read_ret = read(fd, str_buff, BUFFER_SIZE)) >= 0)
	{
		str_buff[read_ret] = 0;
		line_size += read_ret;
		if (!ft_save_to_line(line, str_buff, line_size))
			return (ft_free(str_buff, remainer[fd], 1, 1) - 1);
		if (ret_in_str(*line) >= 0 || read_ret == 0)
			break ;
	}
	if (read_ret == -1 || read_ret == 0)
		return (ft_free(str_buff, remainer[fd], 1, 1) + read_ret);
	if (!(remainer[fd] = save_remainer(line, ret_in_str(*line))))
		return (ft_free(str_buff, remainer[fd], 1, 1) - 1);
	return (ft_free(str_buff, remainer[fd], 1, 0) + 1);
}
