/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_music.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:38:10 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/19 17:46:41 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

void	ft_play_background_music(void)
{
	system("afplay bonus/background.mp3 &>/dev/null &");
}

void	ft_play_step_sound(void)
{
	static int	i;
	static int	j;

	if (!(i % 3) && j % 2)
		system("afplay bonus/step1.mp3 &>/dev/null &");
	else if (!(i % 3) && !(j % 2))
		system("afplay bonus/step2.mp3 &>/dev/null &");
	i++;
	j++;
}
