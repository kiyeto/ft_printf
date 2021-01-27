/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 02:03:18 by abenouda          #+#    #+#             */
/*   Updated: 2019/12/13 01:04:52 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	low_hex(unsigned int i)
{
	char	low[16];
	int		a;

	a = -1;
	while (++a < 16)
	{
		if (a > 9)
			low[a] = a + 87;
		else
			low[a] = a + '0';
	}
	return (low[i]);
}

char	cap_hex(unsigned int i)
{
	char	low[16];
	int		a;

	a = -1;
	while (++a < 16)
	{
		if (a > 9)
			low[a] = a + 55;
		else
			low[a] = a + '0';
	}
	return (low[i]);
}

char	*convert(unsigned long num, int x)
{
	char	*ptr;
	int		i;

	i = plen(num);
	if ((ptr = malloc(i + 1)) == NULL)
		return (NULL);
	ptr[i--] = '\0';
	if (num == 0)
		ptr[i] = '0';
	while (num != 0 && x == 0)
	{
		ptr[i] = low_hex(num % 16);
		num /= 16;
		i--;
	}
	while (num != 0 && x == 1)
	{
		ptr[i] = cap_hex(num % 16);
		num /= 16;
		i--;
	}
	return (ptr);
}
