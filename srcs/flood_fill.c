/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:47:58 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/05 17:11:20 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**ft_create_clone(char **map)
{
	int		row;
	char	**clone;

	clone = malloc(sizeof(char *) * (ft_count_rows(map) + 1));
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

static void	ft_flood_fill(t_program *program, int row, int col)
{
	char	**map;

	map = ft_create_clone(program->map);
	if (!map)
		ft_exit(map, "Malloc allocation failed\n");
	ft_ff_collectible(map, row, col, 49);
	if (!ft_is_collectible_reached(map))
		ft_exit(map, "No valid path found\n");
	ft_free_arr(map);
	map = ft_create_clone(program->map);
	if (!map)
		ft_exit(map, "Malloc allocation failed");
	ft_ff_exit(map, row, col, 49);
	if (!ft_is_exit_reached(map))
		ft_exit(map, "No valid path found\n");
	ft_free_arr(map);
}

void	ft_get_player_position(t_program *program)
{
	int		row;
	int		col;

	row = 0;
	while (program->map[row])
	{
		col = 0;
		while (program->map[row][col] && program->map[row][col] != 'P')
			col++;
		if (program->map[row][col] == 'P')
		{
			ft_flood_fill(program, row, col);
			break ;
		}
		row++;
	}
}
