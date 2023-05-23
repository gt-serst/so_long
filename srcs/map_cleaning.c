/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaned_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:57:06 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/23 20:03:14 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_open_fd(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\nFile error\n", 16);
		exit(errno);
	}
	return (fd);
}

static int	ft_count_strs(char *argv)
{
	int		fd;
	int		strs;
	char	*line;

	fd = ft_open_fd(argv);
	strs = 0;
	line = get_next_line(fd);
	while (line)
	{
		strs++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (strs);
}

void	ft_delete_nl(t_program *program)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (program->map[row])
	{
		col = 0;
		while (program->map[row][col])
		{
			if (program->map[row][col] == '\n')
				program->map[row][col] = '\0';
			col++;
		}
		row++;
	}
}

char	**ft_get_map(t_program *program, char *argv)
{
	int		row;
	int		fd;
	char	*line;

	fd = ft_open_fd(argv);
	program->map = malloc(sizeof(char *) * (ft_count_strs(argv) + 1));
	if (!program->map)
		return (NULL);
	row = 0;
	line = get_next_line(fd);
	while (line)
	{
		program->map[row] = line;
		line = get_next_line(fd);
		row++;
	}
	program->map[row] = 0;
	close(fd);
	return (program->map);
}
