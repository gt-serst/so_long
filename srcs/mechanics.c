/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:04:46 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/13 15:46:17 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	action(t_program *program, t_game *game)
{
	program->map[game->old.x / 64][game->old.y / 64] = '0';
	mlx_destroy_image(program->mlx, program->sprite[game->old.y]
		[game->old.x].reference);
/*
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite[0].reference, game->old.y,
		game->old.x);
*/
	program->map[game->new.x / 64][game->new.y / 64] = 'P';
	update_player_position(program->map, game);
	program->game.m++;
	ft_printf("%d\n", program->game.m);
}

/*
void	loot_gold(t_program *program, t_game *game)
{
	program->game.coins++;
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite[0].reference, game->new.y,
		game->new.x);
	move_to_next_tile(program, game);
}

void	quit_game(t_program *program)
{
	program->game.m++;
	ft_printf("%d\nWell done, another step forward for the Undead Scourge!\n",
		program->game.m);
	close_window(program);
}
*/

void	motion_manager(t_program *program, t_game *game)
{
/*
	if (program->map[game->new.x / 64][game->new.y / 64] == '0')
		move_to_next_tile(program, game);
*/
	if (program->map[game->new.x / 64][game->new.y / 64] == 'C')
	{
		program->game.coins++;
/*
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->sprite[0].reference, game->new.y,
			game->new.x);
*/
	}
	else if (program->map[game->new.x / 64][game->new.y / 64] == 'E')
	{
		program->game.m++;
		ft_printf("%d\nWell done, another step forward for the Undead Scourge!\n",
		program->game.m);
		close_window(program);
	}
	action(program, game);
}
