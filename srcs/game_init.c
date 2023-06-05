/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:01:50 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/05 13:09:35 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_update_player_position(char **map, t_game *game)
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

static int	ft_input(int key, t_program *program)
{
	t_game	game;

	ft_update_player_position(program->map, &game);
	if (key == 124 || key == 65363)
		ft_right_motion(program, &game);
	if (key == 123 || key == 65361)
		ft_left_motion(program, &game);
	if (key == 125 || key == 65364)
		ft_backward_motion(program, &game);
	if (key == 126 || key == 65362)
		ft_forward_motion(program, &game);
	if (key == 53 || key == 65307)
	{
		mlx_destroy_window(program->mlx, program->window.reference);
		ft_close_window(program);
	}
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite[3].reference, game.effect.y,
		game.effect.x);
	return (0);
}

void	ft_game_init(t_program *program)
{
	program->game.c = ft_count_components(program->map, 'C');
	program->game.coins = 0;
	program->game.m = 0;
	mlx_key_hook(program->window.reference, ft_input, program);
}