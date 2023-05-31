/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:47:58 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/31 15:29:49 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_recursive(char **map, int row, int col, int walls)
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
		ft_recursive(map, row + 1, col, walls);
		ft_recursive(map, row - 1, col, walls);
		ft_recursive(map, row, col + 1, walls);
		ft_recursive(map, row, col - 1, walls);
	}
}

static void	ft_flood_fill(char **map, int row, int col, int walls)
{
	if (map[row][col] == walls)
		return ;
	ft_recursive(map, row, col, walls);
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

void	ft_get_player_position(char **map)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col] && map[row][col] != 'P')
			col++;
		if (map[row][col] == 'P')
		{
			ft_flood_fill(map, row, col, 49);
			break ;
		}
		row++;
	}
	if (ft_get_exit_position(map) || ft_get_collectible_position(map))
		ft_exit(map, "No valid path found\n");
}
