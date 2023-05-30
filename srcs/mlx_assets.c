/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:34:45 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/30 16:41:27 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_load_data(t_program *program)
{
	program->sprites[0].path = "xpm/tile5.xpm";
	program->sprites[1].path = "xpm/lava_tile1.xpm";
	program->sprites[2].path = "xpm/gold.xpm";
	program->sprites[3].path = "xpm/lich-king.xpm";
	program->sprites[4].path = "xpm/hearthstone.xpm";
}

void	ft_rendering(t_program *program)
{
	int	row;
	int	col;
	int	index;

	row = 0;
	index = 0;
	while (program->map[row])
	{
		col = 0;
		while (program->map[row][col])
		{
			ft_identify_sprite(program, row, col, index);
			col++;
			index++;
		}
		row++;
	}
}

void	ft_identify_sprite(t_program *program, int row, int col, int index)
{
	char	*path;

	switch (program->map[row][col])
	{
		case '0':
			path = program->sprites[0].path;
			break;
		case '1':
			path = program->sprites[1].path;
			break;
		case 'C':
			path = program->sprites[2].path;
			break;
		case 'P':
			path = program->sprites[3].path;
			break;
		case 'E':
			path = program->sprites[4].path;
			break;
		default:
			return ;
	}
	ft_put_asset_to_window(program, col * 64, row * 64, index, path);
}
