/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:45:26 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/14 16:40:11 by gt-serst         ###   ########.fr       */
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
			if (map[row][col] == EMPTY || map[row][col] == WALL
					|| map[row][col] == COIN || map[row][col] == EXIT
					|| map[row][col] == PLAYER)
				col++;
			else
				return (0);
		}
		row++;
	}
	return (1);
}

static int	is_closed_by_walls(char **map, int width, int height)
{
	int	row;
	int	col;

	col = 0;
	while (map[0][col] && map[height - 1][col])
	{
		if (map[0][col] != WALL || map[height - 1][col] != WALL)
			return (0);
		col++;
	}
	row = 0;
	while (map[row] && (map[row][0] && map[row][width - 1]))
	{
		if (map[row][0] != WALL || map[row][width - 1] != WALL)
			return (0);
		row++;
	}
	return (1);
}

void	parsing(t_program *program, char *argv)
{
	char	*content;

	content = get_map(argv);
	if (!content)
		exit_msg(program->map, "Couldn't get the map");
	program->map = ft_split(content, '\n');
	free(content);
	if (!program->map)
		exit_msg(program->map, "Split failed");
	if (!check_type_of_components(program->map))
		exit_msg(program->map, "Map contains wrong components");
	if (!check_width(program) || !check_height(program))
		exit_msg(program->map, "Map is not rectangular");
	if (!is_closed_by_walls(program->map,
			program->game.map_width, program->game.map_height))
		exit_msg(program->map, "Map not closed by walls");
	if (count_components(program->map, COIN) < 1
		|| count_components(program->map, PLAYER) != 1
		|| count_components(program->map, EXIT) != 1)
		exit_msg(program->map, "Map contains wrong number of components");
}
