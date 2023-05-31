/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:37:28 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/31 16:57:12 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_is_walkable(t_program *program, char c)
{
	if (c == '0' || c == 'C' || (c == 'E' && (program->game.collectibles == program->game.coins)))
		return (1);
	else
		return (0);
}

int	ft_forward_motion(t_program *program)
{
	printf("Forward motion\n");
	program->game.old_position.x = program->game.position.x;
	program->game.old_position.y = program->game.position.y;
	program->game.new_position.x = program->game.position.x - 1;
	program->game.new_position.y = program->game.position.y;
	printf("old_position x = %d\n", program->game.old_position.x);
	printf("old_position y = %d\n", program->game.old_position.y);
	printf("new_position x = %d\n", program->game.new_position.x);
	printf("new_position y = %d\n", program->game.new_position.y);
	if (ft_is_walkable(program, program->map[program->game.new_position.x][program->game.new_position.y]) == 1)
	{
		ft_motion_manager(program);
		return (1);
	}
	else
		return (0);
}

int	ft_backward_motion(t_program *program)
{
	program->game.old_position.x = program->game.position.x;
	program->game.old_position.y = program->game.position.y;
	program->game.new_position.x = program->game.position.x + 1;
	program->game.new_position.y = program->game.position.y;
	if (ft_is_walkable(program, program->map[program->game.new_position.x][program->game.new_position.y]) == 1)
	{
		ft_motion_manager(program);
		return (1);
	}
	else
		return (0);
}

int	ft_right_motion(t_program *program)
{
	program->game.old_position.x = program->game.position.x;
	program->game.old_position.y = program->game.position.y;
	program->game.new_position.x = program->game.position.x;
	program->game.new_position.y = program->game.position.y + 1;
	if (ft_is_walkable(program, program->map[program->game.new_position.x][program->game.new_position.y]) == 1)
	{
		ft_motion_manager(program);
		return (1);
	}
	else
		return (0);
}

int	ft_left_motion(t_program *program)
{
	program->game.old_position.x = program->game.position.x;
	program->game.old_position.y = program->game.position.y;
	program->game.new_position.x = program->game.position.x;
	program->game.new_position.y = program->game.position.y - 1;
	if (ft_is_walkable(program, program->map[program->game.new_position.x][program->game.new_position.y]) == 1)
	{
		ft_motion_manager(program);
		return (1);
	}
	else
		return (0);
}
