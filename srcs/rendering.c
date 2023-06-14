/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:34:45 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/14 16:50:35 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	put_sprite_to_window(t_program *program, t_image sprite,
	int x, int y)
{
	mlx_put_image_to_window(program->mlx, program->window.reference,
		sprite.reference, sprite.width * x, sprite.height * y);
}

static void	identify_sprite(t_program *program, int row, int col)
{
	put_sprite_to_window(program, program->empty, col, row);
	if (program->map[row][col] == WALL)
		put_sprite_to_window(program, program->wall, col, row);
	else if (program->map[row][col] == COIN)
		put_sprite_to_window(program, program->coin, (col * 2), (row * 2));
	else if (program->map[row][col] == PLAYER)
		put_sprite_to_window(program, program->player, col, row);
	else if (program->map[row][col] == EXIT)
		put_sprite_to_window(program, program->exit, col, row);
}

void	rendering(t_program *program)
{
	int	row;
	int	col;

	row = 0;
	while (program->map[row])
	{
		col = 0;
		while (program->map[row][col])
		{
			identify_sprite(program, row, col);
			col++;
		}
		row++;
	}
}
