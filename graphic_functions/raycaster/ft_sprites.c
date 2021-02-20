/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:34:55 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/20 15:48:10 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

static void	ft_setup(t_ray *ray)
{
	int	n_sprites;

	n_sprites = ft_n_chars_in_str_tab(ray->map, '2');
}

static void	ft_sprites_from_map_to_t_list(char **map)
{
	int		i;
	int		j;
	t_list	*lst;

	lst = ft_lstnew(0);
	i = 0;
	while (map[i++])
	{
		j = 0;
		while (map[i][j++])
		{
			if (map[i][j] == '2')
				ft_lstadd_back(&lst, ft_lstnew(ft_new_point(j, i)));
		}
	}
}

void	ft_sprites_raycaster(t_ray *ray)
{
	int	n_sprites;

	n_sprites = ft_n_chars_in_str_tab(ray->map, '2');

}