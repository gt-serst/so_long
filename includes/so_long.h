/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:26:57 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/23 20:13:21 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include "../libft/libft.h"
# include "../minilibx-opengl/mlx.h"

# define SPRITES_NB 10

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct	s_asset {
	char	*path;
}				t_asset;

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
}				t_image;

typedef struct s_map
{
	int	row;
	int	col;
}				t_map;

typedef struct	s_program {
	char		**map;
	void		*mlx;
	t_window	window;
	t_image		img;
	t_asset		sprites[SPRITES_NB];
}				t_program;

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
void		ft_put_sprite_to_window(t_program *program, int x, int y, char *path);

/*				MLX ASSETS				*/
void		ft_put_background_assets(t_program *program);
void		ft_put_core_assets(t_program *program);

/*				CLEANING DATA			*/
void		ft_free_arr(char **arr);

/*				ERROR MANAGEMENT		*/
void		ft_exit(char **map, char *msg);

void		ft_print_map(t_program *program);

#endif
