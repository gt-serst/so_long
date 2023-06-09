/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:26:57 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/14 15:45:57 by gt-serst         ###   ########.fr       */
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

# define EMPTY '0'
# define WALL '1'
# define COIN 'C'
# define PLAYER 'P'
# define EXIT 'E'

# define EMPTY_XPM "assets/xpm/empty.xpm"
# define WALL_XPM "assets/xpm/wall.xpm"
# define COIN_XPM "assets/xpm/coin.xpm"
# define PLAYER_XPM "assets/xpm/player.xpm"
# define EXIT_XPM "assets/xpm/exit.xpm"

typedef struct s_vector {
	int	x;
	int	y;
}				t_vector;

typedef struct s_window {
	void		*reference;
}				t_window;

typedef struct s_image {
	void		*reference;
	int			width;
	int			height;
}				t_image;

typedef struct s_game {
	int			map_width;
	int			map_height;
	t_vector	actual;
	t_vector	current;
	t_vector	old;
	int			coins;
	int			coins_counter;
	int			movements_counter;
}				t_game;

typedef struct s_program {
	char		**map;
	void		*mlx;
	t_window	window;
	t_image		empty;
	t_image		wall;
	t_image		coin;
	t_image		player;
	t_image		exit;
	t_image		sprite;
	t_game		game;
}				t_program;

/*				PARSING					*/
void		parsing(t_program *program, char *argv);
int			open_fd(char *argv);
char		*get_map(char *argv);
int			count_components(char **map, char charset);
int			count_rows(char **map);
int			check_width(t_program *program);
int			check_height(t_program *program);

/*				FLOOD FILL				*/
void		get_player_position(t_program *program);
void		ff_collectible(char **map, int row, int col, int walls);
void		ff_exit(char **map, int row, int col, int walls);
int			is_collectible_reached(char **map);
int			is_exit_reached(char **map);

/*				INIT					*/
void		game_init(t_program *program);
void		sprites_init(t_program *program);
int			close_window(t_program *program);

/*				RENDERING				*/
void		rendering(t_program *program);

/*				INPUT				*/
int			user_input(int key, t_program *program);
void		update_player_position(char **map, t_game *game);

/*				MOTION					*/
void		motion_manager(t_program *program, t_game *game);
void		forward_motion(t_program *program, t_game *game);
void		backward_motion(t_program *program, t_game *game);
void		right_motion(t_program *program, t_game *game);
void		left_motion(t_program *program, t_game *game);

/*				CLEANING DATA			*/
void		free_arr(char **arr);
void		destroy_images(t_program *program);

/*				ERROR MANAGEMENT		*/
void		exit_msg(char **map, char *msg);

#endif
