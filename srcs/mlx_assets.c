/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:34:45 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/07 11:09:42 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_data(t_program *program)
{
	program->img[0].path = "assets/xpm/lava.xpm";
	program->img[1].path = "assets/xpm/wall.xpm";
	program->img[2].path = "assets/xpm/crystal.xpm";
	program->img[3].path = "assets/xpm/player.xpm";
	program->img[4].path = "assets/xpm/door.xpm";
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

void	identify_sprite(t_program *program, int row, int col)
{
	put_asset_to_window(program, col * 64, row * 64, 0);
	if (program->map[row][col] == '1')
		put_asset_to_window(program, col * 64, row * 64, 1);
	else if (program->map[row][col] == 'C')
		put_asset_to_window(program, col * 64, row * 64, 2);
	else if (program->map[row][col] == 'P')
		put_asset_to_window(program, col * 64, row * 64, 3);
	else if (program->map[row][col] == 'E')
		put_asset_to_window(program, col * 64, row * 64, 4);
}
