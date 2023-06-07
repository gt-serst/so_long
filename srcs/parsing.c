/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:45:26 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/07 12:09:12 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_components(char **map, char charset)
{
	int	row;
	int	col;
	int	count;

	row = 0;
	count = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == charset)
				count++;
			col++;
		}
		row++;
	}
	return (count);
}

static int	check_type_of_components(char **map)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == 48 || map[row][col] == 49
					|| map[row][col] == 'C' || map[row][col] == 'E'
					|| map[row][col] == 'P')
				col++;
			else
				return (0);
		}
		row++;
	}
	return (1);
}

static int	is_rectangular(char **map)
{
	if (!check_length(map) || !check_width(map))
		return (0);
	return (1);
}

static int	is_closed_by_walls(char **map)
{
	int	row;
	int	col;

	col = 0;
	while (map[0][col] && map[count_rows(map) - 1][col])
	{
		if (map[0][col] != 49 || map[count_rows(map) - 1][col] != 49)
			return (0);
		col++;
	}
	row = 0;
	while (map[row] && (map[row][0] && map[row][ft_strlen(map[row]) - 1]))
	{
		if (map[row][0] != 49 || map[row][ft_strlen(map[row]) - 1] != 49)
			return (0);
		row++;
	}
	return (1);
}

void	parsing(t_program *program, char *argv)
{
	program->map = get_map(program->map, argv);
	if (!program->map)
	{
		ft_printf("Malloc allocation failed\n");
		exit(errno);
	}
	if (!(*program->map))
	{
		ft_printf("Error\nEmpty map\n");
		exit(errno);
	}
	program->map = remove_nl(program->map);
	if (!check_type_of_components(program->map))
		exit_msg(program->map, "Map contains wrong components\n");
	if (!is_rectangular(program->map))
		exit_msg(program->map, "Map is not rectangular\n");
	if (!is_closed_by_walls(program->map))
		exit_msg(program->map, "Map not closed by walls\n");
	if (count_components(program->map, 'C') < 1
		|| count_components(program->map, 'P') != 1
		|| count_components(program->map, 'E') != 1)
		exit_msg(program->map, "Map contains wrong number of components\n");
}
