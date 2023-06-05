/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_graphic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:26:15 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/05 13:37:38 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_close_window(t_program *program)
{
	ft_free_arr(program->map);
	exit(0);
}

t_window	ft_new_window(t_program *program, int widht, int height, char *name)
{
	t_window	window;

	window.reference = mlx_new_window(program->mlx, widht, height, name);
	window.size.x = widht;
	window.size.y = height;
	mlx_hook(window.reference, 17, 0, ft_close_window, program);
	return (window);
}

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.reference = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels = mlx_get_data_addr(img.reference, &img.bits_per_pixel,
			&img.line_size, &img.endian);
	return (img);
}

void	ft_put_asset_to_window(t_program *program, int x, int y, int index)
{
	program->sprite[index] = ft_new_sprite(program->mlx,
			program->img[index].path);
	if (index == 2)
	{
		program->sprite[index].position.x = x + 16;
		program->sprite[index].position.y = y + 16;
	}
	else
	{
		program->sprite[index].position.x = x;
		program->sprite[index].position.y = y;
	}
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite[index].reference, program->sprite[index].position.x,
		program->sprite[index].position.y);
}
