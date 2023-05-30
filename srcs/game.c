/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:47:26 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/30 17:07:12 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_current_player_position(t_program *program)
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

void	ft_update_position(t_program *program, int x, int y)
{
	program->map[program->game.position.x][program->game.position.y] = '0';
	program->map[x][y] = 'P';
	ft_current_player_position(program);
	ft_print_map(program);
	printf("Position X validated: %d\n", program->game.position.x);
	printf("Position Y validated: %d\n", program->game.position.y);
}

void	ft_loot_manager(t_program *program, int x, int y)
{
	program->game.inventory++;
	ft_update_position(program, x, y);
}

int	ft_game_manager(t_program *program)
{
	if (program->game.collectibles == program->game.inventory)
		return (1);
	else
		return (0);
}

int	ft_motion_manager(t_program *program, int x, int y)
{
	printf("New X position: %d\n", x);
	printf("New Y position: %d\n", y);
	printf("Component in new player position: %c\n", program->map[x][y]);
	switch (program->map[x][y])
	{
		case '0':
			ft_update_position(program, x, y);
			return (1);
		case '1':
			return (0);
		case 'C':
			ft_loot_manager(program, x, y);
			return (1);
		case 'E':
			if (ft_game_manager(program))
				return (1);
			else
				return (0);
		default:
			return (0);
	}
}

int	ft_input(int key, t_program *program)
{
	int	x;
	int	y;

	x = program->game.position.x;
	y = program->game.position.y;
	if (key == 124)
		if (ft_motion_manager(program, x, y + 1) == 1)
			program->img[40].position.x += program->img[40].size.x;
	if (key == 123)
		if (ft_motion_manager(program, x, y - 1) == 1)
			program->img[40].position.x -= program->img[40].size.x;
	if (key == 125)
		if (ft_motion_manager(program, x + 1, y) == 1)
			program->img[40].position.y += program->img[40].size.y;
	if (key == 126)
		if (ft_motion_manager(program, x - 1, y) == 1)
			program->img[40].position.y -= program->img[40].size.y;
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->img[40].reference, program->img[40].position.x,
		program->img[40].position.y);
	//printf("Key pressed -> %d\n", key);
	return (0);
}

void	ft_game_init(t_program *program)
{
	ft_current_player_position(program);
	program->game.collectibles = ft_count_components(program, 'C');
	printf("Current X position: %d\n", program->game.position.x);
	printf("Current Y position: %d\n", program->game.position.y);
	mlx_key_hook(program->window.reference, ft_input, program);
}
