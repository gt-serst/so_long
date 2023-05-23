/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:26:18 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/23 20:13:12 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_mlx_init(t_program *program)
{
	program->mlx = mlx_init();
	if (program->mlx == 0)
		ft_exit(program->map, "Mlx error");
	program->window = ft_new_window(program->mlx, 1920, 1080, "Hello world!");
	ft_put_background_assets(program);
	ft_put_core_assets(program);
	mlx_loop(program->mlx);
}
