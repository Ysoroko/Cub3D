/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_music_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:38:10 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/23 11:14:12 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

void	ft_play_background_music(void)
{
	system("afplay bonus/night.mp3 &>/dev/null &");
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
		system("afplay -v 0.1 bonus/step1.mp3 &>/dev/null &");
	else if (!(i % 5) && !(j % 2))
		system("afplay -v 0.1 bonus/step2.mp3 &>/dev/null &");
	i++;
	j++;
}

/*
** FT_STOP_ALL_AFPLAY_SOUNDS
** This function is used to stop all the playing afplay sounds
** It is called when we close the cub3D window
*/

void	ft_stop_all_afplay_sounds(void)
{
	system("killall afplay");
}
