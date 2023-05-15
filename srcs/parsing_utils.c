#include "../includes/so_long.h"

int	ft_open_fd(char *argv)
{
	int	map;

	map = open(argv, O_RDONLY);
	if (map < 0)
	{
		write(1, "Error\nFile error\n", 16);
		exit(errno);
	}
	return (map);
}

int	ft_count_rows(char **matrix)
{
	int	count_rows;

	count_rows = 0;
	while(matrix[count_rows])
		count_rows++;
	return (count_rows);

}

int	ft_count_lines(char *argv)
{
	int		map;
	int		count_lines;
	char	*line;

	map = ft_open_fd(argv);
	count_lines = 0;
	line = get_next_line(map);
	while (line)
	{
		count_lines++;
		free(line);
		line = get_next_line(map);
	}
	close(map);
	return (count_lines);
}

static int	ft_check_max_nb(int c, int e, int p)
{
	if (c >= 1 && e == 1 && p == 1)
		return (1);
	else
		return (0);
}

int	ft_get_nb_of_components(char **matrix)
{
	int	i;
	int	j;
	int	c;
	int	e;
	int	p;

	i = 0;
	c = 0;
	e = 0;
	p = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == 'C')
				c++;
			else if (matrix[i][j] == 'E')
				e++;
			else if( matrix[i][j] == 'P')
				p++;
			j++;
		}
		i++;
	}
	return (ft_check_max_nb(c, e, p));
}

