/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 00:45:53 by abenouda          #+#    #+#             */
/*   Updated: 2019/12/19 00:07:52 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printdu_wp(int num, t_flags *flg, int *count)
{
	int spaces;
	int zeros;

	spaces = flg->width - flg->prcn;
	zeros = flg->prcn - numlen(num);
	if (flg->minus == 0)
	{
		while (spaces-- > 0)
			printchar(' ', count);
		while (zeros-- > 0)
			printchar('0', count);
		printnbr(num, count);
	}
	else
	{
		while (zeros-- > 0)
			printchar('0', count);
		printnbr(num, count);
		while (spaces-- > 0)
			printchar(' ', count);
	}
}

void	printds_wp(int num, t_flags *flg, int *count)
{
	int				spaces;
	int				zeros;
	unsigned int	n;

	n = num * -1;
	spaces = flg->width - flg->prcn - 1;
	zeros = flg->prcn - numlen(num);
	if (flg->minus == 0)
	{
		while (spaces-- > 0)
			printchar(' ', count);
		printchar('-', count);
		while (zeros-- > 0)
			printchar('0', count);
		printunbr(n, count);
	}
	else
	{
		printchar('-', count);
		while (zeros-- > 0)
			printchar('0', count);
		printunbr(n, count);
		while (spaces-- > 0)
			printchar(' ', count);
	}
}
