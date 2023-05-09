/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:45:26 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/09 17:46:57 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	ft_count_lines(int fd)
{
	int		count_lines;
	char	*line;

	count_lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		count_lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count_lines);
}

int	ft_parsing(char **av)
{
	int		map;
	int		count_lines;
	char	*line;
	char	**matrix;
	int		i;

	map = open(av[1], O_RDONLY);
	if (map < 0)
		ft_exit_msg();
	count_lines = ft_count_lines(map);
	map = open(av[1], O_RDONLY);
	if (map < 0)
		ft_exit_msg();
	matrix = malloc(sizeof(char *) * (count_lines + 1));
	if (!matrix)
		return (0);
	i = 0;
	line = get_next_line(map);
	while (line)
	{
		matrix[i] = line;
		printf("%s\n", matrix[i]);
		line = get_next_line(map);
		i++;
	}
	ft_free_arr(matrix);
	close(map);
	return (1);
}
