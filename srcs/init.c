/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:17:38 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/14 13:07:07 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(t_program *program)
{
	if (program->window.reference != NULL)
	{
		mlx_destroy_window(program->mlx, program->window.reference);
		program->window.reference = NULL;
	}
	if (program->map != NULL)
		free_arr(program->map);
	free(program->mlx);
	exit(EXIT_SUCCESS);
}

void	player_init(t_program *program)
{
	program->game.coins = count_components(program->map, COIN);
	program->game.coins_counter = 0;
	program->game.movements_counter = 0;
}

t_image	new_sprite(void *mlx, char *path, t_program *program)
{
	t_image	sprite;

	sprite.reference = mlx_xpm_file_to_image(mlx, path, &sprite.width, &sprite.height);
	if (sprite.reference == NULL)
		exit_msg(program->map, "Couldn't save a sprite\n");
	return (sprite);
}

void	sprites_init(t_program *program)
{
	void	*mlx;

	mlx = program->mlx;
	program->empty = new_sprite(mlx, EMPTY_XPM, program);
	program->wall = new_sprite(mlx, WALL_XPM, program);
	program->coin = new_sprite(mlx, COIN_XPM, program);
	program->player = new_sprite(mlx, PLAYER_XPM, program);
	program->exit = new_sprite(mlx, EXIT_XPM, program);
}

void	game_init(t_program *program)
{
	program->mlx = mlx_init();
	if (program->mlx == NULL)
		exit_msg(program->map, "Mlx error\n");
	program->window.reference = mlx_new_window(program->mlx,
		program->game.map_width * 64, program->game.map_height * 64, "Wrath of the Lich King");
	if (program->window.reference == NULL)
	{
		free(program->window.reference);
		exit_msg(program->map, "Couldn't connect to the window\n");
	}
	mlx_hook(program->window.reference, 17, 0, close_window, program);
	sprites_init(program);
	rendering(program);
	player_init(program);
	mlx_hook(program->window.reference, 2, (1L << 0), user_input, program);
	mlx_loop(program->mlx);
}
