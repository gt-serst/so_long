/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_graphic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:26:15 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/13 15:49:34 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(t_program *program)
{
	if (program->window.reference != NULL)
		mlx_destroy_window(program->mlx, program->window.reference);
	if (program->map != NULL)
		free_arr(program->map);
	exit(0);
}

t_window	new_window(t_program *program, int widht, int height, char *name)
{
	t_window	window;

	window.reference = mlx_new_window(program->mlx, widht, height, name);
	if (window.reference == NULL)
		exit_msg(program->map, "Couldn't connect to the window\n");
	window.size.x = widht;
	window.size.y = height;
	mlx_hook(window.reference, 17, 0, close_window, program);
	return (window);
}

t_image	new_sprite(t_program *program, void *mlx, char *path)
{
	t_image	img;

	img.reference = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	if (img.reference == NULL)
		exit_msg(program->map, "Couldn't save asset\n");
	img.pixels = mlx_get_data_addr(img.reference, &img.bits_per_pixel,
			&img.line_size, &img.endian);
	if (img.pixels == NULL)
		exit_msg(program->map, "Couldn't get address\n");
	return (img);
}

void	put_asset_to_window(t_program *program, int x, int y, char *path)
{
	program->sprite[x][y] = new_sprite(program, program->mlx, path);
	if (ft_strncmp(path, "assets/xpm/crystal.xpm", ft_strlen(path)))
	{
		program->sprite[x][y].position.x = x + 16;
		program->sprite[x][y].position.y = y + 16;
	}
	else
	{
		program->sprite[x][y].position.x = x;
		program->sprite[x][y].position.y = y;
	}
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite[x][y].reference, program->sprite[x][y].position.x,
		program->sprite[x][y].position.y);
}
