/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:11:52 by ysoroko           #+#    #+#             */
/*   Updated: 2021/01/22 15:06:16 by ysoroko          ###   ########.fr       */
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
	printf(BOLD_RED);
	if (n == 1)
		printf("%s\n", ERROR_1);
	else if (n == 2)
		printf("%s\n", ERROR_2);
	else if (n == 3)
		printf("%s\n", ERROR_3);
	else if (n == 4)
		printf("%s\n", ERROR_4);
	else if (n == 5)
		printf("%s\n", ERROR_5);
	else if (n == 6)
		printf("%s\n", ERROR_6);
	else if (n == 7)
		printf("%s\n", ERROR_7);
	else if (n == 8)
		printf("%s\n", ERROR_8);
	else if (n == 9)
		printf("%s\n", ERROR_9);
	printf(COLOR_RESET);
	return (0);
}

/*
** FT_DEFINED
** This function will check if the specified arguments are already defined
** 1st argument is a string, 3 others are int to be able to verify
** any possible line containing parameters
** It will return 1 if any is defined, 0 otherwise
*/

int		ft_defined(char *str, int a, int b, int c)
{
	if (str || a || b || c)
		return (ALREADY_DEFINED_ERROR);
	return (0);
}
