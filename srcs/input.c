/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:21:50 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/14 13:08:00 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	update_player_position(char **map, t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == PLAYER)
			{
				game->actual.x = row * 64;
				game->actual.y = col * 64;
				break ;
			}
			col++;
		}
		row++;
	}
}

void	destroy_images(t_program *program)
{
	mlx_destroy_image(program->mlx, program->empty.reference);
	mlx_destroy_image(program->mlx, program->wall.reference);
	mlx_destroy_image(program->mlx, program->coin.reference);
	mlx_destroy_image(program->mlx, program->player.reference);
	mlx_destroy_image(program->mlx, program->exit.reference);
}

int	user_input(int key, t_program *program)
{
	t_game	game;

	update_player_position(program->map, &game);
	if (key == 124)
		right_motion(program, &game);
	if (key == 123)
		left_motion(program, &game);
	if (key == 125)
		backward_motion(program, &game);
	if (key == 126)
		forward_motion(program, &game);
	if (key == 53)
		close_window(program);
	destroy_images(program);
	sprites_init(program);
	rendering(program);
	return (0);
}
