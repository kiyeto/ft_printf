/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 02:04:20 by abenouda          #+#    #+#             */
/*   Updated: 2019/12/16 01:30:15 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		numlen(int nb)
{
	int i;

	i = 1;
	if (nb == -2147483648)
		return (10);
	if (nb < 0)
		nb *= -1;
	while (nb /= 10)
		i++;
	return (i);
}

int		unumlen(unsigned int nb)
{
	int i;

	i = 1;
	while (nb /= 10)
		i++;
	return (i);
}

int		slen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		xlen(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}
