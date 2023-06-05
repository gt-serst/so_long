/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:53:12 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/05 17:04:51 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_ff_collectible(char **map, int row, int col, int walls)
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
		ft_ff_collectible(map, row + 1, col, walls);
		ft_ff_collectible(map, row - 1, col, walls);
		ft_ff_collectible(map, row, col + 1, walls);
		ft_ff_collectible(map, row, col - 1, walls);
	}
}

void	ft_ff_exit(char **map, int row, int col, int walls)
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
		ft_ff_exit(map, row + 1, col, walls);
		ft_ff_exit(map, row - 1, col, walls);
		ft_ff_exit(map, row, col + 1, walls);
		ft_ff_exit(map, row, col - 1, walls);
	}
}

int	ft_is_collectible_reached(char **map)
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
			return (0);
		row++;
	}
	return (1);
}

int	ft_is_exit_reached(char **map)
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
			return (0);
		row++;
	}
	return (1);
}
