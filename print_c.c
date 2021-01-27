/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:35:06 by abenouda          #+#    #+#             */
/*   Updated: 2019/12/18 18:32:27 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(va_list args, t_flags *flg, int *count)
{
	unsigned int	i;
	int				spaces;

	i = va_arg(args, int);
	spaces = flg->width - 1;
	if (flg->minus == 0)
	{
		while (spaces-- > 0)
			printchar(' ', count);
		printchar(i, count);
	}
	else
	{
		printchar(i, count);
		while (spaces-- > 0)
			printchar(' ', count);
	}
}
