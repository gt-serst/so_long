/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:47:26 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/31 17:01:06 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_update_player_position(t_program *program)
{
	int	row;
	int	col;

	row = 0;
	while (program->map[row])
	{
		col = 0;
		while (program->map[row][col])
		{
			if (program->map[row][col] == 'P')
			{
				program->game.position.x = row;
				program->game.position.y = col;
				break ;
			}
			col++;
		}
		row++;
	}
}

void	ft_update_position(t_program *program)
{
	printf("New position x: %d\n", program->game.old_position.y * 64);
	printf("New position y: %d\n", program->game.old_position.x * 64);
	program->map[program->game.old_position.x][program->game.old_position.y] = '0';
	mlx_put_image_to_window(program->mlx, program->window.reference,
			program->sprite[_emptyspace].reference, program->game.old_position.y * 64,
			program->game.old_position.x * 64);
	program->map[program->game.new_position.x][program->game.new_position.y] = 'P';
	ft_update_player_position(program);
	program->game.moves++;
	ft_putnbr_fd(program->game.moves, 0);
	write(0, "\n", 1);
}

void	ft_loot_manager(t_program *program)
{
	program->game.coins++;
	mlx_put_image_to_window(program->mlx, program->window.reference,
			program->sprite[_emptyspace].reference, program->game.new_position.y * 64, program->game.new_position.x * 64);
	ft_update_position(program);
}

void	ft_game_manager(t_program *program)
{
	if (program->game.collectibles == program->game.coins)
	{
		program->game.moves++;
		ft_putnbr_fd(program->game.moves, 0);
		write(0, "\n", 1);
		ft_close_window(program);
	}
}

int	ft_motion_manager(t_program *program)
{
	printf("Type of component: %c\n", program->map[program->game.new_position.x][program->game.new_position.y]);
	switch (program->map[program->game.new_position.x][program->game.new_position.y])
	{
		case '0':
			ft_update_position(program);
			return (1);
/*
		case '1':
			return (0);
*/
		case 'C':
			ft_loot_manager(program);
			return (1);
		case 'E':
			ft_game_manager(program);
		default:
			return (0);
	}
}

int	ft_input(int key, t_program *program)
{
	printf("Old player x position: %d\n", program->game.position.y * 64);
	printf("Old player y position: %d\n ", program->game.position.x * 64);
	if (key == 124)
		if (ft_right_motion(program) == 1)
			program->game.position.y++;
	if (key == 123)
		if (ft_left_motion(program) == 1)
			program->game.position.y--;
	if (key == 125)
		if (ft_backward_motion(program) == 1)
			program->game.position.x++;
	if (key == 126)
		if (ft_forward_motion(program) == 1)
			program->game.position.x--;
	if (key == 53)
	{
		mlx_destroy_window(program->mlx, program->window.reference);
		ft_close_window(program);
	}
	printf("New player x position: %d\n", program->game.position.y * 64);
	printf("New player y position: %d\n ", program->game.position.x * 64);
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite[_player].reference, program->game.position.y * 64, program->game.position.x * 64);
	return (0);
}

void	ft_game_init(t_program *program)
{
	ft_update_player_position(program);
	program->game.collectibles = ft_count_components(program, 'C');
	program->game.coins = 0;
	program->game.moves = 0;
	mlx_key_hook(program->window.reference, ft_input, program);
}
