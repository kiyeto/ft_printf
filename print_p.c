/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 01:24:15 by abenouda          #+#    #+#             */
/*   Updated: 2019/12/15 22:19:13 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		plen(unsigned long n)
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

int		printp_w(unsigned long num, t_flags *flg, int *count)
{
	int	spaces;

	spaces = flg->width - plen(num) - 2;
	if (flg->minus == 0)
	{
		while (spaces-- > 0)
			printchar(' ', count);
		if (printaddress(num, count) == -1)
			return (-1);
	}
	else
	{
		if (printaddress(num, count) == -1)
			return (-1);
		while (spaces-- > 0)
			printchar(' ', count);
	}
	return (0);
}

void	noprecision(t_flags *flg, int *count, int spaces)
{
	if (flg->width > 2)
	{
		spaces = flg->width - 2;
		if (flg->minus == 0)
		{
			while (spaces-- > 0)
				printchar(' ', count);
			printstr("0x", count);
		}
		else
		{
			printstr("0x", count);
			while (spaces-- > 0)
				printchar(' ', count);
		}
	}
	else
		printstr("0x", count);
}

int		print_p(t_flags *flg, va_list args, int *count)
{
	unsigned long	num;
	int				spaces;

	spaces = 0;
	num = (unsigned long)va_arg(args, void *);
	if (flg->prcn == 0 && num == 0)
	{
		noprecision(flg, count, spaces);
		return (0);
	}
	if (flg->flag_exist == 0 || flg->width <= plen(num))
	{
		if (printaddress(num, count) == -1)
			return (-1);
	}
	if (flg->width > plen(num))
		printp_w(num, flg, count);
	return (0);
}
