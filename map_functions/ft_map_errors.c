/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:47:00 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/21 17:42:35 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_map_functions.h"
#include "../include/libft.h"
#include "../include/get_next_line.h"

t_map	*ft_print_related_error(int n)
{
	if (n == 1)
		printf("%s", ERROR_1);
	else if (n == 2)
		printf("%s", ERROR_2);
	else if (n == 3)
		printf("%s", ERROR_3);
	else if (n == 4)
		printf("%s", ERROR_4);
	return (0);
}
