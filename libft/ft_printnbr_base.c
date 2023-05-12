/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:35:19 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/12 16:40:53 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!base[i])
		return (0);
	if (base[0] == 0 || base[1] == 0)
		return (0);
	while (base[i] != 0)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != 0)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

static int	ft_convert_base(long nbr, char *base, int len_base)
{
	int	print_length;

	print_length = 0;
	if (nbr < (long)len_base)
		return (ft_printchar(base[nbr]));
	print_length = ft_convert_base(nbr / len_base, base, len_base);
	return (print_length + ft_convert_base(nbr % len_base, base, len_base));
}

int	ft_printnbr_base(long nbr, char *base)
{
	int	len_base;
	int	print_length;

	len_base = ft_strlen(base);
	print_length = 0;
	if (ft_check_base(base))
	{
		if (nbr == 0)
			print_length = ft_printchar(base[0]);
		else if (nbr < 0)
		{
			print_length += ft_printchar('-');
			nbr = -nbr;
			print_length += ft_convert_base(nbr, base, len_base);
		}
		else
			print_length += ft_convert_base(nbr, base, len_base);
	}
	return (print_length);
}
