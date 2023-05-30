/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:45:26 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/30 15:30:42 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_count_components(t_program *program, char charset)
{
	int	row;
	int col;
	int	count;

	row = 0;
	count = 0;
	while (program->map[row])
	{
		col = 0;
		while (program->map[row][col])
		{
			if (program->map[row][col] == charset)
				count++;
			col++;
		}
		row++;
	}
	return (count);
}

static int	ft_check_type_of_components(t_program *program)
{
	int	row;
	int	col;

	row = 0;
	while (program->map[row])
	{
		col = 0;
		while (program->map[row][col])
		{
			if (program->map[row][col] == 48 || program->map[row][col] == 49
					|| program->map[row][col] == 'C' || program->map[row][col] == 'E'
					|| program->map[row][col] == 'P')
				col++;
			else
				return (0);
		}
		row++;
	}
	return (1);
}

static int	ft_is_rectangular(t_program *program)
{
	if (!ft_check_length(program->map) || !ft_check_width(program->map))
		return (0);
	return (1);
}

static int	ft_is_closed_by_walls(t_program *program)
{
	int	row;
	int	col;

	row = 0;
	while (program->map[0][row] || program->map[ft_count_rows(program->map) - 1][row])
	{
		if (program->map[0][row] != 49 || program->map[ft_count_rows(program->map) - 1][row] != 49)
			return (0);
		row++;
	}
	col = 0;
	while (program->map[col] && (program->map[col][0] || program->map[col][ft_strlen(program->map[col]) - 1]))
	{
		if (program->map[col][0] != 49 || program->map[col][ft_strlen(program->map[col]) - 1] != 49)
			return (0);
		col++;
	}
	return (1);
}

void	ft_parsing(t_program *program, char *argv)
{
	char	*map;

	program->map = ft_get_map(program, argv);
	if (!program->map)
		exit(errno);
	if (!program->map)
	{
		write(1, "Error\nEmpty map\n", 15);
		exit(errno);
	}
	ft_delete_nl(program);
	if(!ft_is_closed_by_walls(program))
		ft_exit(program->map, "Map not closed by walls\n");
	if (!ft_is_rectangular(program))
		ft_exit(program->map, "Map is not rectangular\n");
	if (!ft_check_type_of_components(program))
		ft_exit(program->map, "Wrong component\n");
	if (ft_count_components(program, 'C') < 1 || ft_count_components(program, 'P' != 1
				|| ft_count_components(program, 'E') != 1))
		ft_exit(program->map, "Wrong number of components\n");
}
