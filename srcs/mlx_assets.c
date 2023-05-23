/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:34:45 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/23 20:13:26 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_put_background_assets(t_program *program)
{
	int	row;
	int	col;
	int	x;
	int	y;

	row = 0;
	y = 0;
	while (program->map[row])
	{
		col = 0;
		x = 0;
		while (program->map[row][col])
		{
			if (program->map[row][col] == '1')
				ft_put_sprite_to_window(program, x , y, "xpm/lava_tile1.xpm");
			if (program->map[row][col] == '0' || program->map[row][col] == 'C'
					|| program->map[row][col] == 'P' || program->map[row][col] == 'E')
				ft_put_sprite_to_window(program, x, y, "xpm/tile5.xpm");
			x += 64;
			col++;
		}
		y += 64;
		row++;
	}
}

void	ft_put_core_assets(t_program *program)
{
	int	row;
	int	col;
	int	x;
	int	y;

	row = 0;
	y = 0;
	while (program->map[row])
	{
		col = 0;
		x = 0;
		while (program->map[row][col])
		{
			if (program->map[row][col] == 'C')
				ft_put_sprite_to_window(program, x, y, "xpm/gold.xpm");
			else if (program->map[row][col] == 'P')
				ft_put_sprite_to_window(program, x, y, "xpm/lich-king.xpm");
			else if (program->map[row][col] == 'E')
				ft_put_sprite_to_window(program, x, y, "xpm/hearthstone.xpm");
			x += 64;
			col++;
		}
		y += 64;
		row++;
	}
}
