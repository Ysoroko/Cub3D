/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:47:00 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/21 18:19:45 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_map_functions.h"
#include "../include/libft.h"
#include "../include/get_next_line.h"

/*
** FT_PRINT_RELATED_ERROR
** This function will take an error number as an argument and print the related
** error string defined in "ft_map_functions.h" header
*/

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

/*
** FT_ALREADY_DEFINED
** This function will check if the specified arguments are already defined
** 1st argument is a string, 3 others are int to be able to verify
** any possible line containing parameters
** It will return 1 if any is defined, 0 otherwise
*/

int		ft_already_defined(char *str, int a, int b, int c)
{
	if (str || a || b || c)
		return (1);
	return (0);
}
