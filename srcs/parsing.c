/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:45:26 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/15 17:17:21 by geraudtsers      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_check_type_of_components(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == 48 || matrix[i][j] == 49
					|| matrix[i][j] == 'C' || matrix[i][j] == 'E'
					|| matrix[i][j] == 'P')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

static int	ft_is_rectangular(char **matrix)
{
	if (!ft_check_length(matrix) || !ft_check_width(matrix))
		return (0);
	return (1);
}

static int	ft_is_closed_by_walls(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[0][i] || matrix[ft_count_rows(matrix) - 1][i])
	{
		if (matrix[0][i] != 49 || matrix[ft_count_rows(matrix) - 1][i] != 49)
			return (0);
		i++;
	}
	j = 0;
	while (matrix[j] && (matrix[j][0] || matrix[j][ft_strlen(matrix[j]) - 1]))
	{
		if (matrix[j][0] != 49 || matrix[j][ft_strlen(matrix[j]) - 1] != 49)
			return (0);
		j++;
	}
	return (1);
}

static char	**ft_get_matrix(char *argv)
{
	int		i;
	int		map;
	char	*line;
	char	**matrix;

	map = ft_open_fd(argv);
	matrix = malloc(sizeof(char *) * (ft_count_lines(argv) + 1));
	if (!matrix)
		return (NULL);
	i = 0;
	line = get_next_line(map);
	while (line)
	{
		matrix[i] = line;
		line = get_next_line(map);
		i++;
	}
	matrix[i] = 0;
	close(map);
	return (matrix);
}

char	**ft_parsing(char *argv)
{
	char	**matrix;

	matrix = ft_get_matrix(argv);
	if (!matrix)
		return (NULL);
	if (!(*matrix))
	{
		write(1, "Error\nEmpty map\n", 15);
		exit(errno);
	}
	matrix = ft_delete_nl(matrix);
	if(!ft_is_closed_by_walls(matrix))
		ft_exit(matrix, "Map not closed by walls\n");
	if (!ft_is_rectangular(matrix))
		ft_exit(matrix, "Map is not rectangular\n");
	if (!ft_check_type_of_components(matrix))
		ft_exit(matrix, "Wrong component\n");
	if (!ft_get_nb_of_components(matrix))
		ft_exit(matrix, "Too many components\n");
	return (matrix);
}
