/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:47:26 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/04 22:27:22 by geraudtsers      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_update_player_position(char **map, t_game *game)
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
				game->position.x = row;
				game->position.y = col;
				break ;
			}
			col++;
		}
		row++;
	}
}

static void	ft_update_position(t_program *program, t_game *game)
{
	program->map[game->old.x][game->old.y] = '0';
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite[_emptyspace].reference, game->old.y * 64,
		game->old.x * 64);
	program->map[game->new.x][game->new.y] = 'P';
	ft_update_player_position(program->map, game);
	program->game.m++;
	ft_putnbr_fd(program->game.m, 0);
	write(0, "\n", 1);
}

static void	ft_coins_manager(t_program *program, t_game *game)
{
	program->game.coins++;
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite[_emptyspace].reference, game->new.y * 64,
		game->new.x * 64);
	ft_update_position(program, game);
}

static void	ft_game_manager(t_program *program)
{
	program->game.m++;
	ft_putnbr_fd(program->game.m, 0);
	write(0, "\n", 1);
	ft_close_window(program);
}

void	ft_motion_manager(t_program *program, t_game *game)
{
	if (program->map[game->new.x][game->new.y] == '0')
		ft_update_position(program, game);
	if (program->map[game->new.x][game->new.y] == 'C')
		ft_coins_manager(program, game);
	if (program->map[game->new.x][game->new.y] == 'E')
		ft_game_manager(program);
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
		program->sprite[_player].reference, game.position.y * 64,
		game.position.x * 64);
	return (0);
}

void	ft_game_init(t_program *program)
{
	program->game.c = ft_count_components(program->map, 'C');
	program->game.coins = 0;
	program->game.m = 0;
	mlx_key_hook(program->window.reference, ft_input, program);
}
