/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:36:57 by abenouda          #+#    #+#             */
/*   Updated: 2019/12/18 23:08:25 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printd_p(t_flags *flg, int *count, int num)
{
	int spaces;

	if (num >= 0)
	{
		spaces = flg->prcn - numlen(num);
		while (spaces-- > 0)
			printchar('0', count);
		printnbr(num, count);
	}
	else
	{
		spaces = flg->prcn - numlen(num);
		printchar('-', count);
		while (spaces-- > 0)
			printchar('0', count);
		printunbr(num * -1, count);
	}
}

void	printd_nop(t_flags *flg, int *count, int num)
{
	int spaces;

	if (num == 0 && flg->prcn == 0)
	{
		spaces = flg->width;
		while (spaces-- > 0)
			printchar(' ', count);
	}
}

void	printd_wp(t_flags *flg, int *count, int num)
{
	if (num >= 0)
		printdu_wp(num, flg, count);
	else
		printds_wp(num, flg, count);
}

void	print_d(t_flags *flg, va_list args, int *count)
{
	int	num;

	num = va_arg(args, int);
	if (flg->flag_exist == 0 || (flg->width <= numlen(num)
		&& flg->prcn <= numlen(num)))
	{
		if (num == 0 && flg->prcn == 0)
			printd_nop(flg, count, num);
		else
			printnbr(num, count);
		return ;
	}
	if (flg->width >= numlen(num) && flg->prcn > numlen(num))
		printd_wp(flg, count, num);
	if (flg->width >= numlen(num) && flg->prcn <= numlen(num))
	{
		if (num == 0 && flg->prcn == 0)
			printd_nop(flg, count, num);
		else if (num >= 0)
			printdu_w(num, flg, count);
		else
			printds_w(num, flg, count);
	}
	if (flg->width < numlen(num) && flg->prcn > numlen(num))
		printd_p(flg, count, num);
}
