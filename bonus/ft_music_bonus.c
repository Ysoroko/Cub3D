/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_music_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:38:10 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/20 11:34:06 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

void	ft_play_background_music(void)
{
	system("afplay bonus/background.mp3 &>/dev/null &");
}

/*
** FT_PLAY_STEP_SOUND
** This function is responsible for playing a sound whenever
** a player presses wasd buttons
** Combined with key autorepeat this gives a rather unpleasant sound effect
** so two static variables are used here to only play the sounds at a certain
** interval
*/

void	ft_play_step_sound(void)
{
	static int	i;
	static int	j;

	if (!(i % 5) && j % 2)
		system("afplay bonus/step1.mp3 &>/dev/null &");
	else if (!(i % 5) && !(j % 2))
		system("afplay bonus/step2.mp3 &>/dev/null &");
	i++;
	j++;
}
