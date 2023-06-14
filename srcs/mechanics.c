/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:04:46 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/14 13:07:46 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	action(t_program *program, t_game *game)
{
	program->map[game->old.x / 64][game->old.y / 64] = EMPTY;
	program->map[game->current.x / 64][game->current.y / 64] = PLAYER;
	update_player_position(program->map, game);
	program->game.movements_counter++;
	ft_printf("%d\n", program->game.movements_counter);
}

void	motion_manager(t_program *program, t_game *game)
{
	if (program->map[game->current.x / 64][game->current.y / 64] == COIN)
		program->game.coins_counter++;
	else if (program->map[game->current.x / 64][game->current.y / 64] == EXIT)
	{
		program->game.movements_counter++;
		ft_printf("%d\nWell done, another step forward for the Undead Scourge!\n",
		program->game.movements_counter);
		close_window(program);
	}
	action(program, game);
}
