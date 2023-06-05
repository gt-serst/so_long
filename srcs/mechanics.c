/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:04:46 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/05 13:36:36 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_move_tile(t_program *program, t_game *game)
{
	program->map[game->old.x / 64][game->old.y / 64] = '0';
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite[_emptyspace].reference, game->old.y,
		game->old.x);
	program->map[game->new.x / 64][game->new.y / 64] = 'P';
	ft_update_player_position(program->map, game);
	program->game.m++;
	ft_putnbr_fd(program->game.m, 0);
	write(0, "\n", 1);
}

void	ft_loot_gold(t_program *program, t_game *game)
{
	program->game.coins++;
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite[_emptyspace].reference, game->new.y,
		game->new.x);
	ft_move_tile(program, game);
}

void	ft_quit_game(t_program *program)
{
	program->game.m++;
	ft_putnbr_fd(program->game.m, 0);
	write(0, "\n", 1);
	ft_close_window(program);
}

void	ft_motion_manager(t_program *program, t_game *game)
{
	if (program->map[game->new.x / 64][game->new.y / 64] == '0')
		ft_move_tile(program, game);
	if (program->map[game->new.x / 64][game->new.y / 64] == 'C')
		ft_loot_gold(program, game);
	if (program->map[game->new.x / 64][game->new.y / 64] == 'E')
		ft_quit_game(program);
}