/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_chars_in_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:13:04 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/22 16:15:24 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_n_chars_in_str(char *str, char c)
{
	int count;
	int i;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == c)
			count++;
	}
	return (count);
}
