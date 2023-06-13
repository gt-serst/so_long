/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_graphic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:26:15 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/14 00:42:31 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(t_program *program)
{
	if (program->window.reference != NULL)
	{
		mlx_destroy_window(program->mlx, program->window.reference);
		program->window.reference = NULL;
	}
	if (program->map != NULL)
		free_arr(program->map);
	free(program->mlx);
	exit(EXIT_SUCCESS);
}

/*
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
*/

void	put_sprite_to_window(t_program *program, t_image sprite, int x, int y)
{
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->sprite.width * x,
		program->sprite.height * y);
}
