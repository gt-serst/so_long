/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:26:57 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/07 11:24:43 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "../libft/libft.h"
# include <mlx.h>

# define IMG_NB 6

typedef struct s_vector {
	int	x;
	int	y;
}				t_vector;

typedef struct s_window {
	void		*reference;
	t_vector	size;
}				t_window;

typedef struct s_image {
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
	char		*path;
	t_vector	position;
}				t_image;

typedef struct s_game {
	t_vector	effect;
	t_vector	new;
	t_vector	old;
	int			c;
	int			coins;
	int			m;
}				t_game;

typedef struct s_program {
	char		**map;
	void		*mlx;
	t_window	window;
	t_image		img[IMG_NB];
	t_image		sprite[IMG_NB];
	t_game		game;
}				t_program;

/*				PARSING					*/
void		parsing(t_program *program, char *argv);
int			open_fd(char *argv);
char		**get_map(char **map, char *argv);
char		**remove_nl(char **map);
int			count_components(char **map, char charset);
int			count_rows(char **map);
int			check_length(char **map);
int			check_width(char **map);

/*				FLOOD FILL				*/
void		get_player_position(t_program *program);
void		ff_collectible(char **map, int row, int col, int walls);
void		ff_exit(char **map, int row, int col, int walls);
int			is_collectible_reached(char **map);
int			is_exit_reached(char **map);

/*				MLX INIT					*/
void		display_init(t_program *program);

/*				MLX GRAPHIC				*/
t_window	new_window(t_program *program, int width,
				int height, char *name);
int			close_window(t_program *program);
t_image		new_sprite(t_program *program, void *mlx, char *path);
void		put_asset_to_window(t_program *program, int x, int y, int index);

/*				MLX ASSETS				*/
void		load_data(t_program *program);
void		rendering(t_program *program);
void		identify_sprite(t_program *program, int row, int col);

/*				GAME INIT				*/
void		game_init(t_program *program);
void		update_player_position(char **map, t_game *game);

/*				MOTION					*/
void		motion_manager(t_program *program, t_game *game);
void		forward_motion(t_program *program, t_game *game);
void		backward_motion(t_program *program, t_game *game);
void		right_motion(t_program *program, t_game *game);
void		left_motion(t_program *program, t_game *game);

/*				MECHANICS				*/
void		move_to_next_tile(t_program *program, t_game *game);
void		loot_gold(t_program *program, t_game *game);
void		quit_game(t_program *program);

/*				CLEANING DATA			*/
void		free_arr(char **arr);

/*				ERROR MANAGEMENT		*/
void		exit_msg(char **map, char *msg);

#endif
