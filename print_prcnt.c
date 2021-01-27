/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_%.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 06:28:22 by abenouda          #+#    #+#             */
/*   Updated: 2019/12/15 22:05:57 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percent(t_flags *flg, int *count)
{
	int spaces;

	spaces = flg->width - 1;
	if (flg->minus == 0)
	{
		if (flg->zero == 1)
		{
			while (spaces-- > 0)
				printchar('0', count);
		}
		else
		{
			while (spaces-- > 0)
				printchar(' ', count);
		}
		printchar('%', count);
	}
	else
	{
		printchar('%', count);
		while (spaces-- > 0)
			printchar(' ', count);
	}
}
