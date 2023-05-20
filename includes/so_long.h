/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:26:57 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/20 23:29:20 by geraudtsers      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include "../libft/libft.h"
# include "../minilibx-opengl/mlx.h"

typedef struct s_graphic
{
	int		pixel_x;
	int		pixel_y;
	char	*path;
}				t_graphic;

typedef struct s_vector
{
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
}				t_image;

typedef struct	s_program {
	void		*mlx;
	t_window	window;
	t_image		sprite;
	t_vector	sprite_position;
}				t_program;

/*				PARSING					*/
char	**ft_parsing(char *argv);
int		ft_open_fd(char *argv);
int		ft_count_lines(char *argv);
char	**ft_delete_nl(char **matrix);
int		ft_count_rows(char **matrix);
int		ft_check_length(char **matrix);
int		ft_check_width(char **matrix);
int		ft_get_nb_of_components(char **matrix);

/*				FLOOD FILL				*/
void	ft_get_player_position(char **matrix);

/*				MLX INIT				*/
void	ft_mlx_init(char **matrix);

/*				GRAPHIC MANAGEMENT		*/
void	ft_put_sprite_to_window(t_program *program, t_graphic *graphic);
t_image	ft_new_sprite(void *mlx, char *path);

/*				CLEANING DATA			*/
void	ft_free_arr(char **arr);

/*				ERROR MANAGEMENT		*/
void	ft_exit(char **matrix, char *msg);

void	ft_print_matrix(char **matrix);

#endif
