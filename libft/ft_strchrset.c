/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:50:53 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/26 15:22:13 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Same as ft_strchr, but instead of looking for only one character,
** is looking for one of the characters of the charser
** Returns the address of the first occurence of one of the charset characters
** or a NULL pointer if none were found
*/

char	*ft_strchrset(char *str, char *charset)
{
	int		i;
	char	*found;

	i = -1;
	while (str[++i])
	{
		if ((found = ft_strchr(charset, str[i])) != 0)
			return (found);
	}
	return (0);
}
