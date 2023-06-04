/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:26:57 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/04 22:11:30 by geraudtsers      ###   ########.fr       */
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
	_player = 3,
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

typedef struct	s_game {
	t_vector	position;
	t_vector	new;
	t_vector	old;
	int			c;
	int			coins;
	int			m;
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
char		**ft_get_map(char **map, char *argv);
char		**ft_delete_nl(char **map);
int			ft_count_components(char **map, char charset);
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
void		ft_put_asset_to_window(t_program *program, int x, int y, int index);

/*				MLX ASSETS				*/
void		ft_load_data(t_program *program);
void		ft_rendering(t_program *program);
void		ft_identify_sprite(t_program *program, int row, int col);

/*				GAME					*/
void		ft_game_init(t_program *program);

/*				MOTION					*/
void		ft_motion_manager(t_program *program, t_game *game);
void		ft_forward_motion(t_program *program, t_game *game);
void		ft_backward_motion(t_program *program, t_game *game);
void		ft_right_motion(t_program *program, t_game *game);
void		ft_left_motion(t_program *program, t_game *game);

/*				CLEANING DATA			*/
void		ft_free_arr(char **arr);

/*				ERROR MANAGEMENT		*/
void		ft_exit(char **map, char *msg);

void		ft_print_map(char **map);

#endif
