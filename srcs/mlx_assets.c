/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:34:45 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/05 13:31:37 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_load_data(t_program *program)
{
	program->img[0].path = "xpm/lava.xpm";
	program->img[1].path = "xpm/wall.xpm";
	program->img[2].path = "xpm/crystal.xpm";
	program->img[3].path = "xpm/player.xpm";
	program->img[4].path = "xpm/door.xpm";
}

void	ft_rendering(t_program *program)
{
	int	row;
	int	col;

	row = 0;
	while (program->map[row])
	{
		col = 0;
		while (program->map[row][col])
		{
			ft_identify_sprite(program, row, col);
			col++;
		}
		row++;
	}
}

void	ft_identify_sprite(t_program *program, int row, int col)
{
	ft_put_asset_to_window(program, col * 64, row * 64, 0);
	if (program->map[row][col] == '1')
		ft_put_asset_to_window(program, col * 64, row * 64, 1);
	else if (program->map[row][col] == 'C')
		ft_put_asset_to_window(program, col * 64, row * 64, 2);
	else if (program->map[row][col] == 'P')
		ft_put_asset_to_window(program, col * 64, row * 64, 3);
	else if (program->map[row][col] == 'E')
		ft_put_asset_to_window(program, col * 64, row * 64, 4);
}
