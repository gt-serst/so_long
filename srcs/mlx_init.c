/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:26:18 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/05 14:40:00 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_mlx_init(t_program *program)
{
	program->mlx = mlx_init();
	if (program->mlx == 0)
		ft_exit(program->map, "Mlx error");
	program->window = ft_new_window(program, ft_strlen(program->map[0]) * 64,
		ft_count_rows(program->map) * 64, "Hello world!");
	ft_load_data(program);
	ft_rendering(program);
	ft_game_init(program);
	mlx_loop(program->mlx);
}
