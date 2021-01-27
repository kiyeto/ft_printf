/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 21:06:47 by abenouda          #+#    #+#             */
/*   Updated: 2019/12/18 23:18:10 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printu_0prcn(t_flags *flg, int *count)
{
	int spaces;

	spaces = flg->width;
	while (spaces-- > 0)
		printchar(' ', count);
}

void	printu_wp(t_flags *flg, unsigned int num, int *count)
{
	int spaces;
	int zeros;

	spaces = flg->width - flg->prcn;
	zeros = flg->prcn - unumlen(num);
	if (flg->minus == 0)
	{
		while (spaces-- > 0)
			printchar(' ', count);
		while (zeros-- > 0)
			printchar('0', count);
		printunbr(num, count);
	}
	else
	{
		while (zeros-- > 0)
			printchar('0', count);
		printunbr(num, count);
		while (spaces-- > 0)
			printchar(' ', count);
	}
}

void	printu_w(unsigned int num, t_flags *flg, int *count)
{
	int spaces;

	spaces = flg->width - unumlen(num);
	if (flg->minus == 0)
	{
		while (spaces-- > 0)
		{
			if (flg->zero == 1 && flg->prcn <= unumlen(num) && flg->prcn >= 0)
				printchar(' ', count);
			else if (flg->zero == 1)
				printchar('0', count);
			else
				printchar(' ', count);
		}
		printunbr(num, count);
	}
	else
	{
		printunbr(num, count);
		while (spaces-- > 0)
			printchar(' ', count);
	}
}

void	printu_p(unsigned int num, t_flags *flg, int *count)
{
	int spaces;

	spaces = flg->prcn - unumlen(num);
	while (spaces-- > 0)
		printchar('0', count);
	printunbr(num, count);
}

void	print_u(t_flags *flg, va_list args, int *count)
{
	unsigned int num;

	num = va_arg(args, unsigned int);
	if (flg->flag_exist == 0 || (flg->width <= unumlen(num) &&
		flg->prcn <= unumlen(num)))
	{
		if (num == 0 && flg->prcn == 0)
			printu_0prcn(flg, count);
		else
			printunbr(num, count);
		return ;
	}
	if (flg->width >= unumlen(num) && flg->prcn > unumlen(num))
		printu_wp(flg, num, count);
	if (flg->width >= unumlen(num) && flg->prcn <= unumlen(num))
	{
		if (num == 0 && flg->prcn == 0)
			printu_0prcn(flg, count);
		else
			printu_w(num, flg, count);
	}
	if (flg->width < unumlen(num) && flg->prcn > unumlen(num))
		printu_p(num, flg, count);
}
