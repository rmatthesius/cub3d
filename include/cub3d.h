/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:13:51 by rmatthes          #+#    #+#             */
/*   Updated: 2024/11/04 14:01:12 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "libs.h"

# ifndef WINDOW_WIDTH

#  define WINDOW_WIDTH 640

# endif

# ifndef WINDOW_HEIGHT

#  define WINDOW_HEIGHT 480

# endif

# define TEX_SIZE 64
# define MOVESPEED 0.0125
# define ROTSPEED 0.015

enum e_texture_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_texinfo
{
	char			*north; //
	char			*south; //
	char			*west; //
	char			*east; //
	int				*floor; //
	int				*ceiling; //
	unsigned long	hex_floor; //
	unsigned long	hex_ceiling; //
	int				size; //
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
}	t_texinfo;

typedef struct s_mapinfo
{
	int			fd; //
	int			line_count; //
	char		*path; //
	char		**file; //
	int			height; //
	int			width; //
	int			index_end_of_map; //
}	t_mapinfo;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_player
{
	char	dir;//
	double	pos_x;//
	double	pos_y;//
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		rotate;
}	t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	t_mapinfo	mapinfo;
	char		**map;
	t_player	player;
	t_ray		ray;
	int			**texture_pixels;
	int			**textures;
	t_texinfo	texinfo;
}	t_data;

int		on_destroy(t_data *data);
int		on_maximize(t_data *data);
void	mlx_hooks(t_data *data);

//init
void	init_data(t_data *data);
void	init_player(t_player *player);
void	init_mapinfo(t_mapinfo *mapinfo);
void	init_img_clean(t_img *img);
void	init_texinfo(t_texinfo *textures);
bool	init_mlx(t_data *data);
bool	init_textures(t_data *data);
int		*xpm_to_img(t_data *data, char *path, int i, int *buffer);
bool	init_tex_img(t_data *data, t_img *img, char *path);
void	init_ray(t_ray *ray);

//parse
bool	parse_args(t_data *data, char *path);
bool	get_file(t_data *data);
bool	set_file_info(t_data *data, char *path);

//check
bool	check_arg(char *path);
bool	n_exist(char *path);
bool	is_dir(char *path);
bool	is_cub_file(char *path);
bool	is_xpm_file(char *path);
bool	check_tex_paths(t_data *data);
bool	check_colors(t_data *data);
bool	check_map(t_data *data);
bool	check_walls(t_data *data, int i);
bool	check_spaces_in_map(char **tmp);

//clean
bool	clean_file(t_data *data);
bool	clean_empty_lines(t_data *data);
void	remove_line(t_data *data, int i);
bool	is_empty(char *str);

//get_file_data
bool	get_file_data(t_data *data);
bool	get_color_hex(t_data *data, int *rgb, char c);
bool	get_tex_colors(t_data *data, char *str, int i);
bool	copy_tex_colors(int	*int_arr, char **rgb);
size_t	arr_len(char **arr);
bool	copy_tex_path(char **tex_path, char *str);
bool	get_tex_paths(t_data *data, char *str);
bool	get_texinfo(t_data *data);
bool	get_map(t_data *data);
bool	get_map_dim(t_data *data);
void	get_height(t_data *data);
void	get_biggest_len(t_data *data);
void	set_player_start_pos(t_data *data, int y, int x);
void	set_dir_plane_W_E(t_data *data);
void	set_dir_plane_N_S(t_data *data);

//render
bool	render_images(t_data *data);

//raycast

bool	raycasting(t_player *player, t_data *data);
void	calculate_line_height(t_ray *ray, t_data *data, t_player *player);
void	init_raycasting_info(int i, t_ray *ray, t_player *player);
void	update_texture_pixels(t_data *data, t_texinfo *tex, t_ray *ray, int x);
void	get_texture_index(t_data *data, t_ray *ray);
void	perform_dda(t_data *data, t_ray *ray);
void	set_dda(t_ray *ray, t_player *player);

//movement
void	ft_w_key(t_data *data);
void	ft_s_key(t_data *data);
void	ft_a_key(t_data *data);
void	ft_d_key(t_data *data);
void	ft_left_key(t_data *data);
void	ft_right_key(t_data *data);
int		ft_game_loop(t_data *data);

#endif
