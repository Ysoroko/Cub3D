/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_knife_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:25:08 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/26 13:41:53 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

void		ft_display_knife(t_ray *ray, t_image *texture)
{
	int	trgb;
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	x = ray->res->x / 2 - GUN_W / 2;
	y = ray->res->y - GUN_H;
	if (ray->res->x < SPRITE_W || ray->res->y < SPRITE_H)
		return ;
	while (++i < (GUN_W))
	{
		j = -1;
		x += 1;
		y = ray->res->y - GUN_H;
		while (++j < (GUN_H))
		{
			my_mlx_pixel_get(texture, i, j, &trgb);
			if ((trgb & 0x00FFFFFF) != 0)
				my_mlx_pixel_put(ray->graph->img_ptr, x, y, trgb);
			y++;
		}
	}
}

int			ft_key_release(int keycode, t_ray *ray)
{
	t_image *temp;

	if (keycode == SPACEBAR_KEY)
	{
		temp = ray->gun_texture[0];
		ray->gun_texture[0] = ray->gun_texture[1];
		ray->gun_texture[1] = temp;
		system("afplay bonus/knife_on.mp3 &>/dev/null &");
		ft_reposition_line(ray, ray->graph->circle,
			ray->graph->line->angle, ray->graph->line);
		ft_next_frame(ray->graph, ray);
	}
	return (0);
}

static void	ft_kill_enemy(t_ray *ray)
{
	double	move_speed;
	char	next_pos_x;
	char	next_pos_y;

	move_speed = ray->graph->move_speed;
	next_pos_x = ray->map[(int)(ray->pos->x + ray->direction->x *
						move_speed)][(int)ray->pos->y];
	next_pos_y = ray->map[(int)(ray->pos->x)]
				[(int)(ray->pos->y + ray->direction->y * move_speed)];
	if (next_pos_x == '5')
	{
		system("afplay -v 0.1 bonus/ghost_death.mp3 &>/dev/null &");
		ray->map[(int)(ray->pos->x + ray->direction->x * move_speed)]
							[(int)ray->pos->y] = '0';
	}
	if (next_pos_y == '5')
	{
		system("afplay -v 0.1 bonus/ghost_death.mp3 &>/dev/null &");
		ray->map[(int)(ray->pos->x)]
			[(int)(ray->pos->y + ray->direction->y * move_speed)] = '0';
	}
	ft_free_sprite_ray(ray->sprite_ray);
	ray->sprite_ray = ft_new_sprite_ray(ray->map, ray);
}

void		ft_attack(t_ray *ray)
{
	t_image			*temp;
	static	t_image	*first;

	if (!first)
		first = ray->gun_texture[0];
	if ((temp = ray->gun_texture[0]) == first)
	{
		ray->gun_texture[0] = ray->gun_texture[1];
		ray->gun_texture[1] = temp;
		system("afplay bonus/knife_off.mp3 &>/dev/null &");
	}
	ft_reposition_line(ray, ray->graph->circle,
		ray->graph->line->angle, ray->graph->line);
	ft_kill_enemy(ray);
	ft_next_frame(ray->graph, ray);
}
