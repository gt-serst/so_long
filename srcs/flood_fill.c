#include "../includes/so_long.h"

static void ft_recursive(char **matrix, int i, int j, int empty, int walls)
{
	int	n;
	int	m;

	n = ft_strlen(matrix[0]) - 1;
	m = ft_count_rows(matrix) - 1;
	if (i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] == walls)
		return ;
	else
	{
		matrix[i][j] = walls;
		ft_recursive(matrix, i + 1, j, empty, walls);
		ft_recursive(matrix, i - 1, j, empty, walls);
		ft_recursive(matrix, i, j + 1, empty, walls);
		ft_recursive(matrix, i, j - 1, empty, walls);
	}
}

static void	ft_flood_fill(char **matrix, int i, int j, int walls)
{
	if (matrix[i][j] == walls)
		return ;
	ft_recursive(matrix, i, j, 48, walls);
}

static int	ft_get_exit_position(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j] && matrix[i][j] != 'E')
			j++;
		if (matrix[i][j] == 'E')
			return (1);
		i++;
	}
	return (0);
}

static int	ft_get_collectible_position(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j] && matrix[i][j] != 'C')
			j++;
		if (matrix[i][j] == 'C')
			return (1);
		i++;
	}
	return (0);
}

void	ft_get_player_position(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j] && matrix[i][j] != 'P')
			j++;
		if (matrix[i][j] == 'P')
		{
			ft_flood_fill(matrix, i, j, 49);
			break ;
		}
		i++;
	}
	if (ft_get_exit_position(matrix) || ft_get_collectible_position(matrix))
		ft_exit(matrix, "No valid path found\n");
}
