/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:03:34 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/12 17:17:47 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_format(va_list args, const char *format)
{
	int	print_length;

	print_length = 0;
	if (*format == 'c')
		print_length += ft_printchar(va_arg(args, int));
	else if (*format == '%')
		print_length += ft_printchar(*format);
	else if (*format == 's')
		print_length += ft_printstr(va_arg(args, char *));
	else if (*format == 'p')
		print_length += ft_print_address(va_arg(args, long long),
				"0123456789abcdef");
	else if (*format == 'd' || *format == 'i')
		print_length += ft_printnbr_base(va_arg(args, int), "0123456789");
	else if (*format == 'u')
		print_length += ft_printnbr_base(va_arg(args, unsigned int),
				"0123456789");
	else if (*format == 'x')
		print_length += ft_printnbr_base(va_arg(args, unsigned int),
				"0123456789abcdef");
	else if (*format == 'X')
		print_length += ft_printnbr_base(va_arg(args, unsigned int),
				"0123456789ABCDEF");
	return (print_length);
}

int	ft_printf(const char *format, ...)
{
	int		print_length;
	va_list	args;

	if (!format || *format == '\0')
		return (0);
	va_start(args, format);
	print_length = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			print_length += ft_print_format(args, format);
		}
		else
			print_length += ft_printchar(*format);
		format++;
	}
	va_end(args);
	return (print_length);
}

/*
int	main(void)
{
	int				count_printf;
	int				count_ft_printf;
	char			c;
	char			*s;
	char			*p;
	int				d;
	int				i;
	int				u;
	unsigned int	x;
	unsigned int	X;

	count_printf = 0;
	count_ft_printf = 0;
	c = 'd';
	s = "";
	p = &c;
	d = 14137561456491;
	i = 14137561456491;
	u = -141375;
	x = 14137561456491;
	X = -14137561455555;
	printf("Fonction printf original:\n");
	//count_printf = printf("%s", s);
	count_printf += printf("%c", c);
	count_printf += printf("NULL %s NULL", s);
	count_printf += printf(" %p", p);
	count_printf += printf(" %d ", d);
	count_printf += printf("%i ", i);
	count_printf += printf("%u ", u);
	count_printf += printf("%x", x);
	count_printf += printf(" %X", X);
	count_printf += printf(" %%%% ");
	printf("\n");
	printf("Ma fonction printf:\n");
	//count_ft_printf = ft_printf("%s", s);
	count_ft_printf = ft_printf("%cNULL %s NULL %p %d %i %u %x %X %%%% ",
			c, s, p, d, i, u, x, X);
	printf("\n");
	printf("Count de printf: %d\n", count_printf);
	printf("Count de ft_printf: %d\n", count_ft_printf);
	return (0);
}
*/
