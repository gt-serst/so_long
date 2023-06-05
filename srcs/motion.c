/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:37:28 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/05 10:07:22 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_is_walkable(t_program *program, char c)
{
	if (c == '0' || c == 'C'
		|| (c == 'E' && (program->game.c == program->game.coins)))
		return (1);
	else
		return (0);
}

void	ft_forward_motion(t_program *program, t_game *game)
{
	game->old.x = game->effect.x;
	game->old.y = game->effect.y;
	game->new.x = game->effect.x - 64;
	game->new.y = game->effect.y;
	if (ft_is_walkable(program, program->map[game->new.x / 64]
			[game->new.y / 64]) == 1)
		ft_motion_manager(program, game);
}

void	ft_backward_motion(t_program *program, t_game *game)
{
	game->old.x = game->effect.x;
	game->old.y = game->effect.y;
	game->new.x = game->effect.x + 64;
	game->new.y = game->effect.y;
	if (ft_is_walkable(program, program->map[game->new.x / 64]
			[game->new.y / 64]) == 1)
		ft_motion_manager(program, game);
}

void	ft_right_motion(t_program *program, t_game *game)
{
	game->old.x = game->effect.x;
	game->old.y = game->effect.y;
	game->new.x = game->effect.x;
	game->new.y = game->effect.y + 64;
	if (ft_is_walkable(program, program->map[game->new.x / 64]
			[game->new.y / 64]) == 1)
		ft_motion_manager(program, game);
}

void	ft_left_motion(t_program *program, t_game *game)
{
	game->old.x = game->effect.x;
	game->old.y = game->effect.y;
	game->new.x = game->effect.x;
	game->new.y = game->effect.y - 64;
	if (ft_is_walkable(program, program->map[game->new.x / 64]
			[game->new.y / 64]) == 1)
		ft_motion_manager(program, game);
}
