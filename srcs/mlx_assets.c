/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:34:45 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/04 22:10:53 by geraudtsers      ###   ########.fr       */
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

	if (program->map[row][col] == '0')
		index = 0;
	else if (program->map[row][col] == '1')
		index = 1;
	else if (program->map[row][col] == 'C')
		index = 2;
	else if (program->map[row][col] == 'P')
		index = 3;
	else if (program->map[row][col] == 'E')
		index = 4;
	ft_put_asset_to_window(program, col * 64, row * 64, index);
}
