/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:14:34 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/14 16:48:54 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		tmp;
	int		sign;
	int		number;

	tmp = 0;
	sign = 1;
	number = 0;
	while (str[tmp] == 32 || (str[tmp] >= 9 && str[tmp] <= 13))
		tmp++;
	if (str[tmp] == '-')
	{
		sign = -sign;
		tmp++;
	}
	else if (str[tmp] == '+')
		tmp++;
	while (str[tmp] >= '0' && str[tmp] <= '9')
	{
		number = number * 10 + str[tmp] - '0';
		tmp++;
	}
	return (number * sign);
}

/*
int	main()
{
	char	str[] = "";

	printf("%d\n", ft_atoi(str));
	printf("%d", atoi(str));
	return (0);
}
*/
