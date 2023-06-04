/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:47:17 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/04 21:56:35 by geraudtsers      ###   ########.fr       */
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

char	**ft_delete_nl(char **map)
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

char	**ft_get_map(char **map, char *argv)
{
	int		row;
	int		fd;
	char	*line;

	fd = ft_open_fd(argv);
	map = malloc(sizeof(char *) * (ft_count_strs(argv) + 1));
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
