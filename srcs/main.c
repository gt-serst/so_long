/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:26:49 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/19 18:11:03 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_print_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		printf("%s\n", matrix[i]);
		i++;
	}
}

void	ft_free_arr(char **arr)
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

void	ft_exit(char **matrix, char *msg)
{
	ft_free_arr(matrix);
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

static char	**ft_matrix_dup(char **matrix)
{
	int		i;
	char	**copy;

	copy = malloc(sizeof(char *) * (ft_count_rows(matrix) + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (matrix[i])
	{
		copy[i] = ft_strdup(matrix[i]);
		i++;
	}
	copy[i] = 0;
	return (copy);
}

int	main(int ac, char **av)
{
	char	**matrix;
	char	**copy;

	if (ac != 2)
		return (1);
	ft_check_extension(av[1]);
	matrix = ft_parsing(av[1]);
	copy = ft_matrix_dup(matrix);
	if (!copy)
		return (1);
	ft_get_player_position(copy);
	ft_free_arr(copy);
	ft_init_mlx(matrix);
	ft_print_matrix(matrix);
	ft_free_arr(matrix);
	//system("leaks so_long");
	return (0);
}
