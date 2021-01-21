/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 14:58:51 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/21 16:41:46 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
#include "../include/libft.h"

/*
** It's actually strdup with a different name (uses malloc)
*/

char		*ft_strcpy(char *line)
{
	int		i;
	char	*old_line;

	if (line == 0)
		return (0);
	if (!(old_line = malloc(sizeof(*old_line) * (ft_strlen(line) + 1))))
		return (0);
	i = 0;
	while (line[i] != '\0')
	{
		old_line[i] = line[i];
		i++;
	}
	old_line[i] = '\0';
	return (old_line);
}

/*
** Same as strcat, but saves the result in a 3rd, separate string
*/

char		*ft_strcat_to(char *old_line, char *str_buff, char *new_line)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (old_line != 0)
	{
		while (old_line[i] != '\0')
		{
			new_line[i] = old_line[i];
			i++;
		}
	}
	while (str_buff[j] != '\0')
	{
		new_line[i] = str_buff[j];
		i++;
		j++;
	}
	new_line[i] = '\0';
	return (new_line);
}

/*
** Adds the read str_buff to *line. The necessary malloc size is line_size
*/

int			ft_save_to_line(char **line, char *str_buff, size_t line_size)
{
	char *old_line;

	old_line = 0;
	if (*line != 0)
	{
		if (!(old_line = ft_strcpy(*line)))
		{
			free(*line);
			*line = 0;
			return (0);
		}
	}
	free(*line);
	if (!(*line = malloc(sizeof(**line) * (line_size + 1))))
		return (ft_free(old_line, 0, 1, 0));
	*line = ft_strcat_to(old_line, str_buff, *line);
	free(old_line);
	return (1);
}

/*
** Frees str_buff / the remainer if the corresponding flags are "1"
** Then, returns 0 to be used in return in get_next_line
*/

int			ft_free(char *s_buff, char *rem, int s_b_flag, int r_flag)
{
	if (s_b_flag == 1)
		free(s_buff);
	if (r_flag == 1)
		free(rem);
	return (0);
}
