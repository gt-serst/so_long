#include "../includes/so_long.h"

char	**ft_delete_nl(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == '\n')
				matrix[i][j] = '\0';
			j++;
		}
		i++;
	}
	return (matrix);
}

int	ft_check_length(char **matrix)
{
	int	i;
	int	j;
	int	length;

	length = ft_strlen(matrix[0]);
	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
			j++;
		if (length != j)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_width(char **matrix)
{
	int	i;
	int	j;
	int	width;

	width = ft_count_rows(matrix);
	j = 0;
	while (matrix[0][j])
	{
		i = 0;
		while (matrix[i])
			i++;
		if (width != i)
			return (0);
		j++;
	}
	return (1);
}
