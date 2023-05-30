/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:26:49 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/30 17:07:28 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_print_map(t_program *program)
{
	int	row;

	row = 0;
	while (program->map[row])
	{
		printf("%s\n", program->map[row]);
		row++;
	}
}

void	ft_free_arr(char **arr)
{
	int	row;

	row = 0;
	while (arr && arr[row])
	{
		free(arr[row]);
		row++;
	}
	free(arr);
}

void	ft_exit(char **map, char *msg)
{
	ft_free_arr(map);
	write(1, "Error\n", 6);
	write(1, msg, ft_strlen(msg));
	//system("leaks so_long");
	exit(errno);
}

static void ft_check_extension(char *argv)
{
	while (argv && *argv != '.')
		argv++;
	if (!ft_strnstr(argv, ".ber", ft_strlen(argv)))
	{
		write(1, "Error\n", 6);
		write(1, "Wrong map extension, expected .ber\n", 31);
		exit(errno);
	}
}

static char	**ft_clone(char **map)
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

int	main(int ac, char **av)
{
	t_program	program;
	char		**clone;

	if (ac != 2)
		return (1);
	ft_check_extension(av[1]);
	ft_parsing(&program, av[1]);
	clone = ft_clone(program.map);
	if (!clone)
		return (1);
	ft_get_player_position(clone);
	ft_free_arr(clone);
	ft_mlx_init(&program);
	ft_print_map(&program);
	ft_free_arr(program.map);
	//system("leaks so_long");
	return (0);
}
