/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:37:28 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/04 22:27:20 by geraudtsers      ###   ########.fr       */
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
	game->old.x = game->position.x;
	game->old.y = game->position.y;
	game->new.x = game->position.x - 1;
	game->new.y = game->position.y;
	if (ft_is_walkable(program, program->map[game->new.x][game->new.y]) == 1)
		ft_motion_manager(program, game);
}

void	ft_backward_motion(t_program *program, t_game *game)
{
	game->old.x = game->position.x;
	game->old.y = game->position.y;
	game->new.x = game->position.x + 1;
	game->new.y = game->position.y;
	if (ft_is_walkable(program, program->map[game->new.x][game->new.y]) == 1)
		ft_motion_manager(program, game);
}

void	ft_right_motion(t_program *program, t_game *game)
{
	game->old.x = game->position.x;
	game->old.y = game->position.y;
	game->new.x = game->position.x;
	game->new.y = game->position.y + 1;
	if (ft_is_walkable(program, program->map[game->new.x][game->new.y]) == 1)
		ft_motion_manager(program, game);
}

void	ft_left_motion(t_program *program, t_game *game)
{
	game->old.x = game->position.x;
	game->old.y = game->position.y;
	game->new.x = game->position.x;
	game->new.y = game->position.y - 1;
	if (ft_is_walkable(program, program->map[game->new.x][game->new.y]) == 1)
		ft_motion_manager(program, game);
}
