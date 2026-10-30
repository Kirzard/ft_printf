/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadupin <tadupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 21:02:42 by tadupin           #+#    #+#             */
/*   Updated: 2026/10/29 13:46:14 by tadupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsnbr_count(unsigned int n, int fd)
{
	int		count;
	char	p;

	count = 0;
	if (n > 9)
		count += ft_putunsnbr_count(n / 10, fd);
	p = n % 10 + '0';
	count++;
	write(fd, &p, 1);
	return (count);
}
