/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 23:19:24 by abenouda          #+#    #+#             */
/*   Updated: 2019/12/19 00:08:26 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printdu_w(int num, t_flags *flg, int *count)
{
	int spaces;

	spaces = flg->width - numlen(num);
	if (flg->minus == 0)
	{
		while (spaces-- > 0)
		{
			if (flg->zero == 1 && flg->prcn <= unumlen(num)
					&& flg->prcn >= 0)
				printchar(' ', count);
			else if (flg->zero == 1)
				printchar('0', count);
			else
				printchar(' ', count);
		}
		printnbr(num, count);
	}
	else
	{
		printnbr(num, count);
		while (spaces-- > 0)
			printchar(' ', count);
	}
}

void	printds_p(int *count, int num, int spaces)
{
	while (spaces-- > 0)
		printchar(' ', count);
	printchar('-', count);
	printunbr(num * -1, count);
}

void	printds_zero(int *count, int num, int spaces)
{
	printchar('-', count);
	while (spaces-- > 0)
		printchar('0', count);
	printunbr(num * -1, count);
}

void	printds_w(int num, t_flags *flg, int *count)
{
	int spaces;

	spaces = flg->width - numlen(num) - 1;
	if (flg->minus == 0)
	{
		if (flg->zero == 1 && flg->prcn <= unumlen(num) &&
				flg->prcn >= 0)
			printds_p(count, num, spaces);
		else if (flg->zero == 1)
			printds_zero(count, num, spaces);
		else
		{
			while (spaces-- > 0)
				printchar(' ', count);
			printnbr(num, count);
		}
	}
	else
	{
		printnbr(num, count);
		while (spaces-- > 0)
			printchar(' ', count);
	}
}
