/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:26:57 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/31 16:46:13 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# define IMG_NB 5

typedef enum e_sprite {
	_emptyspace = 0,
	_wall = 1,
	_coins = 2,
	_player = 3,
	_exit_opened = 4,
}	t_sprite;

typedef struct	s_vector {
	int	x;
	int	y;
}				t_vector;

typedef struct	s_window {
	void		*reference;
	t_vector	size;
}				t_window;

typedef struct	s_image {
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
	char		*path;
	t_vector	position;
}				t_image;

typedef struct	s_map {
	int	col;
	int	row;
}				t_map;

typedef struct	s_game {
	t_vector	position;
	t_vector	new_position;
	t_vector	old_position;
	int			collectibles;
	int			coins;
	int			moves;
}				t_game;

typedef struct	s_program {
	char		**map;
	void		*mlx;
	t_window	window;
	t_image		img[IMG_NB];
	t_image		sprite[IMG_NB];
	t_game		game;
}				t_program;

/*				PARSING					*/
void		ft_parsing(t_program *program, char *argv);
int			ft_open_fd(char *argv);
char		**ft_get_map(t_program *program, char *argv);
void		ft_delete_nl(t_program *program);
int			ft_count_components(t_program *program, char charset);
int			ft_count_rows(char **map);
int			ft_check_length(char **map);
int			ft_check_width(char **map);

/*				FLOOD FILL				*/
void		ft_get_player_position(char **map);

/*				MLX INIT				*/
void		ft_mlx_init(t_program *program);

/*				MLX GRAPHIC				*/
t_window	ft_new_window(t_program *program, int width, int height, char *name);
int			ft_close_window(t_program *program);
t_image		ft_new_sprite(void *mlx, char *path);
void		ft_put_asset_to_window(t_program *program, int x, int y, int index, char *path);

/*				MLX ASSETS				*/
void		ft_load_data(t_program *program);
void		ft_rendering(t_program *program);
void		ft_identify_sprite(t_program *program, int row, int col);

/*				GAME					*/
void		ft_game_init(t_program *program);

/*				MOTION					*/
int			ft_motion_manager(t_program *program);
int			ft_forward_motion(t_program *program);
int			ft_backward_motion(t_program *program);
int			ft_right_motion(t_program *program);
int			ft_left_motion(t_program *program);

/*				CLEANING DATA			*/
void		ft_free_arr(char **arr);

/*				ERROR MANAGEMENT		*/
void		ft_exit(char **map, char *msg);

void		ft_print_map(t_program *program);

#endif
