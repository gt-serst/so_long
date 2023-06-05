/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:47:58 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/05 16:00:18 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_find_collectible(char **map, int row, int col, int walls)
{
	int	n;
	int	m;

	n = ft_strlen(map[0]) - 1;
	m = ft_count_rows(map) - 1;
	if (row < 0 || row >= m || col < 0 || col >= n || map[row][col] == walls
			|| map[row][col] == 'E')
		return ;
	else
	{
		map[row][col] = walls;
		ft_find_collectible(map, row + 1, col, walls);
		ft_find_collectible(map, row - 1, col, walls);
		ft_find_collectible(map, row, col + 1, walls);
		ft_find_collectible(map, row, col - 1, walls);
	}
}

static void	ft_find_exit(char **map, int row, int col, int walls)
{
	int	n;
	int	m;

	n = ft_strlen(map[0]) - 1;
	m = ft_count_rows(map) - 1;
	if (row < 0 || row >= m || col < 0 || col >= n || map[row][col] == walls)
		return ;
	else
	{
		map[row][col] = walls;
		ft_find_exit(map, row + 1, col, walls);
		ft_find_exit(map, row - 1, col, walls);
		ft_find_exit(map, row, col + 1, walls);
		ft_find_exit(map, row, col - 1, walls);
	}
}

static int	ft_get_collectible_position(char **map)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col] && map[row][col] != 'C')
			col++;
		if (map[row][col] == 'C')
			return (1);
		row++;
	}
	return (0);
}

static int	ft_get_exit_position(char **map)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col] && map[row][col] != 'E')
			col++;
		if (map[row][col] == 'E')
			return (1);
		row++;
	}
	return (0);
}

void	ft_flood_fill(t_program *program)
{
	char	**map;
	int		row;
	int		col;

	map = ft_create_clone(program->map);
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col] && map[row][col] != 'P')
			col++;
		if (map[row][col] == 'P')
		{
			ft_find_collectible(map, row, col, 49);
			if (ft_get_collectible_position(map))
				ft_exit(map, "No valid path found\n");
			ft_free_arr(map);
			map = ft_create_clone(program->map);
			ft_find_exit(map, row, col, 49);
			if (ft_get_exit_position(map))
				ft_exit(map, "No valid path found\n");
			ft_free_arr(map);
			break ;
		}
		row++;
	}
}
