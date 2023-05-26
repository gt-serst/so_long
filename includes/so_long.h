/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:26:57 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/26 18:44:31 by geraudtsers      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# define SPRITES_NB 10000

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
	int	row;
	int	col;
}				t_map;

typedef struct	s_program {
	char		**map;
	void		*mlx;
	t_window	window;
	t_image		img[SPRITES_NB];
	t_image		sprites[SPRITES_NB];
	t_image		sprite;
}				t_program;

typedef struct	s_game {
	t_map	player_position;
}				t_game;

/*				PARSING					*/
void		ft_parsing(t_program *program, char *argv);
int			ft_open_fd(char *argv);
char		**ft_get_map(t_program *program, char *argv);
void		ft_delete_nl(t_program *program);
int			ft_count_rows(char **map);
int			ft_check_length(char **map);
int			ft_check_width(char **map);

/*				FLOOD FILL				*/
void		ft_get_player_position(char **map);

/*				MLX INIT				*/
void		ft_mlx_init(t_program *program);

/*				MLX GRAPHIC				*/
t_window	ft_new_window(void *mlx, int width, int height, char *name);
t_image		ft_new_sprite(void *mlx, char *path);
void		ft_put_asset_to_window(t_program *program, int x, int y, int index, char *path);

/*				MLX ASSETS				*/
void		ft_load_data(t_program *program);
void		ft_rendering(t_program *program);
void		ft_identify_sprite(t_program *program, int row, int col, int index);

/*				GAME					*/
void	ft_game_init(t_program *program);

/*				CLEANING DATA			*/
void		ft_free_arr(char **arr);

/*				ERROR MANAGEMENT		*/
void		ft_exit(char **map, char *msg);

void		ft_print_map(t_program *program);

#endif
