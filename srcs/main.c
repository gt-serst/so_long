/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:26:49 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/05 17:12:09 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_print_map(char **map)
{
	int	row;

	row = 0;
	while (map[row])
	{
		printf("%s\n", map[row]);
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
	ft_printf("Error\n%s", msg);
	system("leaks so_long");
	exit(errno);
}

static void	ft_check_extension(char *argv)
{
	while (argv && *argv != '.')
		argv++;
	if (!ft_strnstr(argv, ".ber", ft_strlen(argv)))
	{
		ft_printf("Error\nWrong map extension, expected .ber\n");
		exit(errno);
	}
}

int	main(int ac, char **av)
{
	t_program	program;

	if (ac != 2)
		return (1);
	ft_check_extension(av[1]);
	ft_parsing(&program, av[1]);
	ft_get_player_position(&program);
	ft_mlx_init(&program);
	ft_free_arr(program.map);
	return (0);
}
