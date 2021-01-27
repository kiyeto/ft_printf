/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 00:47:55 by abenouda          #+#    #+#             */
/*   Updated: 2019/12/13 00:54:58 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printnbr(int n, int *count)
{
	unsigned int	nbr;

	if (n < 0)
	{
		nbr = n * -1;
		printchar('-', count);
	}
	else
		nbr = n;
	if (n / 10)
		printnbr(nbr / 10, count);
	printchar((nbr % 10) + 48, count);
}

void	printunbr(unsigned int n, int *count)
{
	if (n / 10)
		printunbr(n / 10, count);
	printchar((n % 10) + 48, count);
}

int		printaddress(unsigned long num, int *count)
{
	char	*adress;

	if (num == 0)
	{
		write(1, "0x0", 3);
		*count += 3;
		return (0);
	}
	printstr("0x", count);
	if ((adress = convert(num, 0)) == NULL)
		return (-1);
	printstr(adress, count);
	free(adress);
	return (0);
}
