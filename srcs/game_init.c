/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:21:50 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/13 15:47:54 by gt-serst         ###   ########.fr       */
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
			if (map[row][col] == 'P')
			{
				game->effect.x = row * 64;
				game->effect.y = col * 64;
				break ;
			}
			col++;
		}
		row++;
	}
}

static int	user_input(int key, t_program *program)
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
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite[game.old.y][game.old.x].reference, game.effect.y,
		game.effect.x);
	return (0);
}

void	game_init(t_program *program)
{
	program->game.c = count_components(program->map, 'C');
	program->game.coins = 0;
	program->game.m = 0;
	mlx_hook(program->window.reference, 2, (1L << 0), user_input, program);
}
