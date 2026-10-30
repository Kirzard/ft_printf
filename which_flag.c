/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadupin <tadupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 12:46:03 by tadupin           #+#    #+#             */
/*   Updated: 2026/10/30 12:57:19 by tadupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	if_valid_param(char c)
{
	char *valid_param;
	int	i;

	i = 0;
	valid_param = "cspdiuxX%";
	while(valid_param[i])
	{
		if(c == valid_param[i])
			return (1);
		i++;
	}
	return (0);
}
int	which_flag(char *param, int *flag)
{
	char *sub;
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (param[i] == '-' || param[i] == '0')
	{
		if(param[i] == '-')
			flag[0] = 1;
		else
			flag[0] = 2;
		i++;
		while(!if_valid_param(param[i]))
			i++;
		sub = ft_substr(param, 1, i);
		if (!sub)
			return (1);
		flag[1] = ft_atoi(sub);
		free(sub);
		count = i;
	}
	return (count);
}