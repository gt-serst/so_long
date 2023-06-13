/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:47:47 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/13 22:41:03 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_rows(char **map)
{
	int	count_rows;

	count_rows = 0;
	while (map[count_rows])
		count_rows++;
	return (count_rows);
}

int	check_width(t_program *program)
{
	int	row;
	int	col;
	int	width;

	width = ft_strlen(program->map[0]);
	row = 0;
	while (program->map[row])
	{
		col = 0;
		while (program->map[row][col])
			col++;
		if (width != col)
			return (0);
		row++;
	}
	program->game.map_width = col;
	return (1);
}

int	check_height(t_program *program)
{
	int	row;
	int	col;
	int	height;

	height = count_rows(program->map);
	col = 0;
	while (program->map[0][col])
	{
		row = 0;
		while (program->map[row])
			row++;
		if (height != row)
			return (0);
		col++;
	}
	program->game.map_height = row;
	return (1);
}
