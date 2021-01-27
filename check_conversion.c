/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 00:30:51 by abenouda          #+#    #+#             */
/*   Updated: 2019/12/17 11:41:17 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*is_conversion(char *str, int c)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] == c)
			return (&str[i]);
	return (NULL);
}

int		convert_to(char c, va_list args, t_flags *flg, int *count)
{
	if (c == 'c')
		print_c(args, flg, count);
	if (c == '%')
		print_percent(flg, count);
	if (c == 'i' || c == 'd')
		print_d(flg, args, count);
	if (c == 's')
		print_s(flg, args, count);
	if (c == 'u')
		print_u(flg, args, count);
	if (c == 'x')
		if (print_x(flg, args, count, 0) == -1)
			return (-1);
	if (c == 'X')
		if (print_x(flg, args, count, 1) == -1)
			return (-1);
	if (c == 'p')
		if (print_p(flg, args, count) == -1)
			return (-1);
	return (0);
}
