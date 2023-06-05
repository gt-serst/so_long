/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:45:26 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/05 17:22:05 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_count_components(char **map, char charset)
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

static int	ft_check_type_of_components(char **map)
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

static int	ft_is_rectangular(char **map)
{
	if (!ft_check_length(map) || !ft_check_width(map))
		return (0);
	return (1);
}

static int	ft_is_closed_by_walls(char **map)
{
	int	row;
	int	col;

	row = 0;
	while (map[0][row] || map[ft_count_rows(map) - 1][row])
	{
		if (map[0][row] != 49 || map[ft_count_rows(map) - 1][row] != 49)
			return (0);
		row++;
	}
	col = 0;
	while (map[col] && (map[col][0] || map[col][ft_strlen(map[col]) - 1]))
	{
		if (map[col][0] != 49 || map[col][ft_strlen(map[col]) - 1] != 49)
			return (0);
		col++;
	}
	return (1);
}

void	ft_parsing(t_program *program, char *argv)
{
	program->map = ft_get_map(program->map, argv);
	if (!program->map)
	{
		ft_printf("Malloc allocation failed");
		exit(errno);
	}
	if (!program->map)
	{
		ft_printf("Error\nEmpty map\n");
		exit(errno);
	}
	program->map = ft_delete_nl(program->map);
	if (!ft_is_closed_by_walls(program->map))
		ft_exit(program->map, "Map not closed by walls\n");
	if (!ft_is_rectangular(program->map))
		ft_exit(program->map, "Map is not rectangular\n");
	if (!ft_check_type_of_components(program->map))
		ft_exit(program->map, "Map contains wrong components\n");
	if (ft_count_components(program->map, 'C') < 1
		|| ft_count_components(program->map, 'P') != 1
		|| ft_count_components(program->map, 'E') != 1)
		ft_exit(program->map, "Map contains wrong number of components\n");
}
