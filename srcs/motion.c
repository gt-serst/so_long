/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:37:28 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/14 11:06:19 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	is_walkable(t_program *program, char c)
{
	if (c == EMPTY || c == COIN
		|| (c == EXIT && (program->game.coins == program->game.coins_counter)))
		return (1);
	else
		return (0);
}

void	forward_motion(t_program *program, t_game *game)
{
	game->old.x = game->actual.x;
	game->old.y = game->actual.y;
	game->current.x = game->actual.x - 64;
	game->current.y = game->actual.y;
	if (is_walkable(program, program->map[game->current.x / 64]
			[game->current.y / 64]) == 1)
		motion_manager(program, game);
}

void	backward_motion(t_program *program, t_game *game)
{
	game->old.x = game->actual.x;
	game->old.y = game->actual.y;
	game->current.x = game->actual.x + 64;
	game->current.y = game->actual.y;
	if (is_walkable(program, program->map[game->current.x / 64]
			[game->current.y / 64]) == 1)
		motion_manager(program, game);
}

void	right_motion(t_program *program, t_game *game)
{
	game->old.x = game->actual.x;
	game->old.y = game->actual.y;
	game->current.x = game->actual.x;
	game->current.y = game->actual.y + 64;
	if (is_walkable(program, program->map[game->current.x / 64]
			[game->current.y / 64]) == 1)
		motion_manager(program, game);
}

void	left_motion(t_program *program, t_game *game)
{
	game->old.x = game->actual.x;
	game->old.y = game->actual.y;
	game->current.x = game->actual.x;
	game->current.y = game->actual.y - 64;
	if (is_walkable(program, program->map[game->current.x / 64]
			[game->current.y / 64]) == 1)
		motion_manager(program, game);
}
