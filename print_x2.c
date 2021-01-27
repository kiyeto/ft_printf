/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 02:43:59 by abenouda          #+#    #+#             */
/*   Updated: 2019/12/18 23:34:00 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printx_wp(unsigned int num, char *s, t_flags *flg, int *count)
{
	int spaces;
	int zeros;

	spaces = flg->width - flg->prcn;
	zeros = flg->prcn - xlen(num);
	if (flg->minus == 0)
	{
		while (spaces-- > 0)
			printchar(' ', count);
		while (zeros-- > 0)
			printchar('0', count);
		printstr(s, count);
	}
	else
	{
		while (zeros-- > 0)
			printchar('0', count);
		printstr(s, count);
		while (spaces-- > 0)
			printchar(' ', count);
	}
	free(s);
	return (0);
}
