/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadupin <tadupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 12:22:46 by tadupin           #+#    #+#             */
/*   Updated: 2026/10/29 13:45:39 by tadupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_count(int n, int fd)
{
	int		count;
	char	p;

	count = 0;
	if (n == -2147483648)
	{
		write(fd, &"-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		count++;
		n *= -1;
	}
	if (n > 9)
		count += ft_putnbr_count(n / 10, fd);
	p = n % 10 + '0';
	count++;
	write(fd, &p, 1);
	return (count);
}
