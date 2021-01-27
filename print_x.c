/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 01:20:44 by abenouda          #+#    #+#             */
/*   Updated: 2019/12/18 23:34:01 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printx_w(unsigned int num, char *s, t_flags *flg, int *count)
{
	int spaces;

	spaces = flg->width - xlen(num);
	if (flg->minus == 0)
	{
		while (spaces-- > 0)
		{
			if (flg->zero == 1 && flg->prcn <= xlen(num)
				&& flg->prcn >= 0)
				printchar(' ', count);
			else if (flg->zero == 1)
				printchar('0', count);
			else
				printchar(' ', count);
		}
		printstr(s, count);
	}
	else
	{
		printstr(s, count);
		while (spaces-- > 0)
			printchar(' ', count);
	}
	free(s);
	return (0);
}

void	printx_0prcn(t_flags *flg, int *count)
{
	int spaces;

	spaces = flg->width;
	while (spaces-- > 0)
		printchar(' ', count);
}

void	printx_p(t_flags *flg, int *count, unsigned int num, char *s)
{
	int spaces;

	spaces = flg->prcn - xlen(num);
	while (spaces-- > 0)
		printchar('0', count);
	printstr(s, count);
	free(s);
}

void	printx_nop(unsigned int num, t_flags *flg, int *count, char *s)
{
	if (num == 0 && flg->prcn == 0)
		printx_0prcn(flg, count);
	else
		printstr(s, count);
	free(s);
}

int		print_x(t_flags *flg, va_list args, int *count, int x)
{
	unsigned int	num;
	char			*s;

	num = va_arg(args, unsigned int);
	if ((s = convert(num, x)) == NULL)
		return (-1);
	if (flg->flag_exist == 0 || (flg->width <= xlen(num)
			&& flg->prcn <= xlen(num)))
		printx_nop(num, flg, count, s);
	else if (flg->width >= xlen(num) && flg->prcn > xlen(num))
		printx_wp(num, s, flg, count);
	else if (flg->width >= xlen(num) && flg->prcn <= xlen(num))
	{
		if (num == 0 && flg->prcn == 0)
			printx_0prcn(flg, count);
		else
			printx_w(num, s, flg, count);
	}
	else if (flg->width < xlen(num) && flg->prcn > xlen(num))
		printx_p(flg, count, num, s);
	return (0);
}
