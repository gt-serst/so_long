/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:34:45 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/31 15:20:09 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_load_data(t_program *program)
{
	program->img[0].path = "xpm/tile5.xpm";
	program->img[1].path = "xpm/lava_tile1.xpm";
	program->img[2].path = "xpm/gold.xpm";
	program->img[3].path = "xpm/lich-king.xpm";
	program->img[4].path = "xpm/hearthstone.xpm";
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
	int	index;

	switch (program->map[row][col])
	{
		case '0':
			index = 0;
			break;
		case '1':
			index = 1;
			break;
		case 'C':
			index = 2;
			break;
		case 'P':
			index = 3;
			break;
		case 'E':
			index = 4;
			break;
		default:
			return ;
	}
	ft_put_asset_to_window(program, col * 64, row * 64, index, program->img[index].path);
}
