/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:37:28 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/13 22:55:07 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	is_walkable(t_program *program, char c)
{
	if (c == '0' || c == 'C'
		|| (c == 'E' && (program->game.coins == program->game.coins_counter)))
		return (1);
	else
		return (0);
}

void	forward_motion(t_program *program, t_game *game)
{
	game->old.x = game->effect.x;
	game->old.y = game->effect.y;
	game->new.x = game->effect.x - 64;
	game->new.y = game->effect.y;
	if (is_walkable(program, program->map[game->new.x / 64]
			[game->new.y / 64]) == 1)
		motion_manager(program, game);
}

void	backward_motion(t_program *program, t_game *game)
{
	game->old.x = game->effect.x;
	game->old.y = game->effect.y;
	game->new.x = game->effect.x + 64;
	game->new.y = game->effect.y;
	if (is_walkable(program, program->map[game->new.x / 64]
			[game->new.y / 64]) == 1)
		motion_manager(program, game);
}

void	right_motion(t_program *program, t_game *game)
{
	game->old.x = game->effect.x;
	game->old.y = game->effect.y;
	game->new.x = game->effect.x;
	game->new.y = game->effect.y + 64;
	if (is_walkable(program, program->map[game->new.x / 64]
			[game->new.y / 64]) == 1)
		motion_manager(program, game);
}

void	left_motion(t_program *program, t_game *game)
{
	game->old.x = game->effect.x;
	game->old.y = game->effect.y;
	game->new.x = game->effect.x;
	game->new.y = game->effect.y - 64;
	if (is_walkable(program, program->map[game->new.x / 64]
			[game->new.y / 64]) == 1)
		motion_manager(program, game);
}
