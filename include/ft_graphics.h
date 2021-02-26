/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:22:26 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/26 11:40:05 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GRAPHICS_H
# define FT_GRAPHICS_H

#include "ft_map_functions.h"
#include "ft_geometry_forms.h"
#include "ft_params_and_colors.h"
#include "libft.h"
#include "../minilibx/mlx.h"
#include <math.h>

typedef struct  s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct		s_frame
{
	t_square	*ceiling;
	t_square	*floor;
	t_square	*minimap_wall;
	t_square	*minimap_background;
	int			units;
	char		player_direction;
}					t_frame;

typedef struct		s_graph
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		*img_ptr;
	int			*f_ptr;
	int			f_trgb;
	int			c_trgb;
	void		*param;
	t_circle	*circle;
	t_line		*line;
	t_map		*map;
	double		move_speed;
	int			res_width;
	int			res_height;
	t_frame		*frame;
}					t_graph;

typedef struct	s_sprite 
{
	double			x;
	double			y;
	char		texture_sprite;
}				t_sprite;

typedef struct	s_sprite_ray
{
	t_sprite	**sprite_array;
	int			num_sprites;
	double		*z_buffer;
	int			*sprite_order;
	double		*sprite_distance;
	t_point		*spr;
	double		inv_det;
	t_point		*transform;
	int			sprite_screen_x;
	t_point		*draw_start;
	t_point		*draw_end;
	int			sprite_width;
	int			sprite_height;	
	t_point		*tex;
	t_point		*texture_size;
}				t_sprite_ray;

typedef struct	s_ray
{
	t_graph		*graph;
	char		**map;
	int			map_width;
	int			map_height;
	int			hit;
	int			side;
	int			health;
	double		fov;
	double		camera_x;
	double		perp_wall_dist;
	t_point		*pos;
	t_point		*in_map;
	t_point		*res;
	t_point		*plane;
	t_point		*direction;
	t_point		*ray_dir;
	t_point		*delta_dist;
	t_point		*side_dist;
	t_point		*step;
	t_line		*line;
	t_image		*north_texture;
	t_image		*south_texture;
	t_image		*east_texture;
	t_image		*west_texture;
	t_image		*sprite_texture;
	int			texture_width;
	int			texture_height;
	int			sprite_width;
	int			sprite_height;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		tex_step;
	double		tex_pos;
	t_image		*floor_texture;
	t_image		*ceiling_texture;
	t_image		*sprite_two_texture;
	t_image		*heart_texture;
	t_image		*gun_texture[2];
	t_point		*ray_dir_0;
	t_point		*ray_dir_1;
	int			p;
	double		pos_z;
	double		row_distance;
	t_point		*floor_step;
	t_point		*floor;
	t_point		*cell;
	t_point		*tex;
	t_sprite_ray	*sprite_ray;
}				t_ray;

/*
** FT_NEW_STRUCTURES
*/

t_graph			*ft_new_t_graph(t_map *map);
t_image			*ft_new_t_image(void);
t_frame			*ft_new_t_frame(t_graph *graph);

/*
** FT_WINDOW_START
*/

t_graph			*ft_window_start(t_map *map, int save);
void			ft_draw_background(t_graph *graph);
void			ft_next_frame(t_graph *graph, t_ray *ray);

/*
** FT_RGB_TO_TRGB
*/

int				ft_rgb_to_trgb(int t, int r, int g, int b);

/*
** FT_IMAGE_FUNCTIONS
*/

t_image			*ft_image(void *mlx_ptr, int width, int height);
t_image			*ft_image_from_file(void *mlx_ptr, int width,
								int height, char *path);
void			my_mlx_pixel_put(t_image *image, int x, int y, int color);
void			my_mlx_pixel_get(t_image *image, int x, int y, int *trgb_color);

/*
** FT_DRAW_LINE
*/

void			ft_draw_line(t_line *line, t_graph *graph, int trgb);

/*
** FT_DRAW_VERTICAL_LINE
*/

void			ft_draw_vertical_line(int x, double a_y,
										double b_y, t_ray *ray, int *text);

/*
** FT_DRAW_FILLED_IN_FORMS
*/

void			ft_draw_fsquare(t_square *square, t_graph *graph, int trgb);
void			ft_draw_fcircle(t_circle *circle, t_graph *graph, int trgb);
void			ft_draw_circle(t_circle *circle, t_graph *graph, int trgb);

/*
** FT_NEW_GEOMETRY_FORMS
*/

t_square		*ft_new_square(double x, double y, double width, double height);
t_line			*ft_new_line(double a_x, double a_y, double angle, double len);
t_circle		*ft_new_circle(double x, double y, double radius, double prox);
t_point			*ft_new_point(double x, double y);
void			ft_limit_points_within_map(double *x, double *y, t_graph *graph);

/*
** FT_HOOKS_FUNCTIONS
*/

int				ft_keys_binding(int keycode, t_ray *ray);
int				ft_mouse_hooks(int keycode, t_ray *ray);
int				ft_window_closed(void);

/*
** FT_ERROR_UTILS
*/

void			ft_malloc_fail(void);
void			ft_mlx_fail(void);
void			ft_create_fail(void);
void			ft_close_fail(void);

/*
** FT_DRAW_MINIMAP
*/

void			ft_draw_minimap(t_graph *graph, t_ray *ray);

/*
** FT_MOVE_IN_MAP
*/

void			ft_move_and_collide(t_graph *graph, int direction, t_ray *ray);
void			ft_reposition_line(t_ray *ray, t_circle *cir, double a, 
												t_line *line);
double			ft_dist_to_wall(t_graph *graph, char **map,
							double units, double angle);

/*
** FT_TURN_IN_MAP
*/

void			ft_turn(t_graph *graph, int direction, t_ray *ray);

/*
** RAYCASTER
*/

t_ray			*ft_new_raycaster(t_graph *graph, t_map *map);
void			ft_raycaster(t_ray *ray);
void			ft_textures(t_ray *ray, int x);
void			ft_floor_and_ceiling_raycasting(t_ray *ray);

/*
** BONUS
*/

void			ft_play_step_sound(void);
void			ft_play_background_music(void);
void			ft_play_hurt_sound(void);
void			ft_play_game_over_sound(void);
void			ft_stop_all_afplay_sounds(void);
void			ft_apply_shadow_to_floor(double dist, int res, int *color);
void			ft_apply_shadow_to_textures(double dist, int *color);
void			ft_apply_shadow_to_sprites(double dist, int *color);
void			ft_move_bonus(t_graph *graph, int direction, t_ray *ray);
void			ft_draw_hud(t_ray *ray);
void			ft_display_knife(t_ray *ray, t_image *texture);
void			ft_attack(t_ray *ray);
void			ft_recieve_damage(t_ray *ray);
void			ft_game_over(t_ray *ray, t_graph *graph);
void			ft_initialize_bonus_sprites(t_ray *ray, t_map *map);
int				ft_key_release(int keycode, t_ray *ray);
void			ft_free_sprite_ray(t_sprite_ray *sprite_ray);

/*
** SPRITES RAYCASTER
*/

t_sprite_ray	*ft_new_sprite_ray(char **map, t_ray *ray);
void			ft_sprites_raycaster(t_ray *ray, t_sprite_ray *s_ray);
void			ft_sort_sprites_tab(int *spr_order,
								double *spr_dist, int n_spr);

/*
** SAVE
*/

int				ft_get_r(int trgb);
int				ft_get_g(int trgb);
int				ft_get_b(int trgb);
void			ft_save_to_bmp(t_graph *graph);

#endif