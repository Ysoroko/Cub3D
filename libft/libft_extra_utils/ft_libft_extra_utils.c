/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_extra_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:38:17 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/19 16:39:31 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;

	if (!str || !to_find)
		return (0);
	i = -1;
	if (to_find[0] == '\0')
		return (str);
	while (str[++i] != '\0')
	{
		j = 0;
		while (to_find[j] == str[i + j - 1] && str[i + j - 1] != 0
				&& to_find[j] != 0)
		{
			j++;
		}
		if (to_find[j] == 0 && j != 0)
			return (&(str[i - 1]));
	}
	return (0);
}
