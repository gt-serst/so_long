/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:17:38 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/13 15:50:19 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_init(t_program *program)
{
	program->mlx = mlx_init();
	if (program->mlx == NULL)
		exit_msg(program->map, "Mlx error\n");
	program->window = new_window(program, ft_strlen(program->map[0]) * 64,
			count_rows(program->map) * 64, "Wrath of the Lich King");
	//load_data(program);
	rendering(program);
	game_init(program);
	mlx_loop(program->mlx);
}
