/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:47:58 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/14 12:14:02 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**create_clone(char **map)
{
	int		row;
	char	**clone;

	clone = malloc(sizeof(char *) * (count_rows(map) + 1));
	if (!clone)
		return (NULL);
	row = 0;
	while (map[row])
	{
		clone[row] = ft_strdup(map[row]);
		row++;
	}
	clone[row] = 0;
	return (clone);
}

static void	flood_fill(t_program *program, int row, int col)
{
	char	**map;

	map = create_clone(program->map);
	if (!map)
		exit_msg(map, "Malloc allocation failed\n");
	ff_collectible(map, row, col, WALL);
	if (!is_collectible_reached(map))
		exit_msg(map, "No valid path found\n");
	free_arr(map);
	map = create_clone(program->map);
	if (!map)
		exit_msg(map, "Malloc allocation failed");
	ff_exit(map, row, col, WALL);
	if (!is_exit_reached(map))
		exit_msg(map, "No valid path found\n");
	free_arr(map);
}

void	get_player_position(t_program *program)
{
	int		row;
	int		col;

	row = 0;
	while (program->map[row])
	{
		col = 0;
		while (program->map[row][col] && program->map[row][col] != PLAYER)
			col++;
		if (program->map[row][col] == PLAYER)
		{
			flood_fill(program, row, col);
			break ;
		}
		row++;
	}
}
