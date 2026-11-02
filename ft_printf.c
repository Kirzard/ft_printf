/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadupin <tadupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:40:11 by tadupin           #+#    #+#             */
/*   Updated: 2026/11/02 15:16:58 by tadupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"


static int	which_arg(va_list	arg, char param)
{
	int	count;

	count = 1;
	if (param == 'c')
		ft_putchar_fd(va_arg(arg, int), 1);
	else if (param == 's')
		count = ft_putstr_count(va_arg(arg, char *), 1);
	else if (param == 'p')
		count = put_adr_hex((unsigned long long)va_arg(arg, void *), 0);
	else if (param == 'd')
		count = ft_putnbr_count(va_arg(arg, int), 1);
	else if (param == 'i')
		count = ft_putnbr_count(va_arg(arg, int), 1);
	else if (param == 'u')
		count = ft_putunsnbr_count(va_arg(arg, unsigned int), 1);
	else if (param == 'x' || param == 'X')
		count = ft_putnbr_hex(va_arg(arg, int), param);
	else if (param == '%')
		ft_putchar_fd('%', 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		arg;
	size_t		i;
	int			count;

	i = 0;
	count = 0;
	va_start(arg, format);
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			ft_putchar_fd(format[i], 1);
			i++;
			count++;
		}
		if (!format[i])
			break ;
		i++;
		count += which_arg(arg, format[i]);
		i++;
	}
	va_end(arg);
	return (count);
}
/*#include<stdio.h>
int main()
{
	
	printf("d :%d\n", ft_printf(":%c:", '0'));
	printf("d :%d\n", printf(":%c:", '0'));
	printf("d :%d\n", ft_printf(": %c :", '0'));
	printf("d :%d\n", printf(": %c :", '0'));
	printf("d :%d\n", ft_printf(": %c:", '0' - 256));
	printf("d :%d\n", printf(": %c:", '0' - 256));
	printf("d :%d\n", ft_printf(":%c :", '0' + 256));
	printf("d :%d\n", printf(":%c :", '0' + 256));
	printf("d :%d\n", ft_printf(": %c %c %c :", '0', 0, '1'));
	printf("d :%d\n", printf(": %c %c %c :", '0', 0, '1'));

	return (0);
}*/