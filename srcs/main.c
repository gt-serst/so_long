/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:26:49 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/13 15:28:03 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_arr(char **arr)
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

void	exit_msg(char **map, char *msg)
{
	if (map)
		free_arr(map);
	ft_printf("Error\n%s", msg);
	exit(errno);
}

static void	check_extension(char *argv)
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
	check_extension(av[1]);
	program.map = NULL;
	parsing(&program, av[1]);
	get_player_position(&program);
	display_init(&program);
	free_arr(program.map);
	return (0);
}
