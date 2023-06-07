/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:47:17 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/07 11:04:57 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	open_fd(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n%s\n", strerror(errno));
		exit(errno);
	}
	return (fd);
}

static int	count_strs(char *argv)
{
	int		fd;
	int		strs;
	char	*line;

	fd = open_fd(argv);
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

char	**remove_nl(char **map)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == '\n')
				map[row][col] = '\0';
			col++;
		}
		row++;
	}
	return (map);
}

char	**get_map(char **map, char *argv)
{
	int		row;
	int		fd;
	char	*line;

	fd = open_fd(argv);
	map = malloc(sizeof(char *) * (count_strs(argv) + 1));
	if (!map)
		return (NULL);
	row = 0;
	line = get_next_line(fd);
	while (line)
	{
		map[row] = line;
		line = get_next_line(fd);
		row++;
	}
	map[row] = 0;
	close(fd);
	return (map);
}
