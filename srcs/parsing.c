/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:45:26 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/14 00:17:24 by gt-serst         ###   ########.fr       */
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

/*
static int	is_rectangular(char **map)
{
	if (!check_width(map) || !check_height(map))
		return (0);
	return (1);
}
*/
static int	is_closed_by_walls(char **map, int width, int height)
{
	int	row;
	int	col;

	col = 0;
	while (map[0][col] && map[height - 1][col])
	{
		if (map[0][col] != 49 || map[height - 1][col] != 49)
			return (0);
		col++;
	}
	row = 0;
	while (map[row] && (map[row][0] && map[row][width - 1]))
	{
		if (map[row][0] != 49 || map[row][width - 1] != 49)
			return (0);
		row++;
	}
	return (1);
}

void	parsing(t_program *program, char *argv)
{
	char	*content;

	content = get_map(program->map, argv);
	if (!content)
		exit_msg(program->map, "Couldn't get the map");
	program->map = ft_split(content, '\n');
	if (!program->map)
		exit_msg(program->map, "Split failed");
	print_map(program->map);
	if (!check_type_of_components(program->map))
		exit_msg(program->map, "Map contains wrong components\n");
	if (!check_width(program) || !check_height(program))
		exit_msg(program->map, "Map is not rectangular\n");
	if (!is_closed_by_walls(program->map,
		program->game.map_width, program->game.map_height))
		exit_msg(program->map, "Map not closed by walls\n");
	if (count_components(program->map, 'C') < 1
		|| count_components(program->map, 'P') != 1
		|| count_components(program->map, 'E') != 1)
		exit_msg(program->map, "Map contains wrong number of components\n");
}
