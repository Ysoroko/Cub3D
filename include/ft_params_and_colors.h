/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params_and_colors.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 13:49:53 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/19 11:28:23 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARAMS_AND_COLORS_H
# define FT_PARAMS_AND_COLORS_H

/*
** Colors
*/

#define MAP_BACKGROUND_COLOR 0x00F2BC94
#define WALL_COLOR 0x0030110D
#define PLAYER_COLOR 0x001F8AC0
#define SPRITE_COLOR 0x00722620
#define DIRECTION_COLOR 0x00FFFFFF

/*
** Parameters
*/

#define WALKING_SPEED 0.3
#define TURNING_SPEED 0.2
#define MAX_RATIO 3
#define LINE_LENGTH 20

/*
** Keyboard keys
*/

# define ESCAPE_KEY 53

# define RIGHT_ARROW_KEY 124
# define LEFT_ARROW_KEY 123
# define UP_ARROW_KEY 126
# define DOWN_ARROW_KEY 125

# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2
# define Q_KEY 12
# define E_KEY 14

# define SPACEBAR_KEY 49
# define LCONTROL_KEY 256

/*
** Directions
*/

# define WALK_FORWARD 1
# define WALK_BACKWARD -1
# define WALK_LEFT -2
# define WALK_RIGHT 2

# define TURN_RIGHT 1
# define TURN_LEFT -1

/*
** Events and masks used for hook functions
*/

# define KEY_PRESS_EVENT 2
# define DESTROY_EVENT 17

# define KEY_PRESS_MASK 1L<<0
# define STRUCTURE_NOTIFY_MASK 1L<<17

/*
** Textures
*/

# define TEXTURE_W 64
# define TEXTURE_H 64
# define SPRITE_H 64
# define SPRITE_W 64

#endif