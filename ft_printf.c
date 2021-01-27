/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:19:29 by abenouda          #+#    #+#             */
/*   Updated: 2019/12/17 11:26:31 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	g_flags;
int		g_count;

void	init_flags(t_flags *f)
{
	f->minus = 0;
	f->zero = 0;
	f->width = 0;
	f->prcn = -1;
	f->flag_exist = 0;
}

int		ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	i = -1;
	g_count = 0;
	va_start(args, str);
	while (str[++i] != '\0')
	{
		init_flags(&g_flags);
		if (str[i] == '%')
		{
			get_flags((char*)str, &i, args, &g_flags);
			if (convert_to(str[i], args, &g_flags, &g_count) == -1)
				return (-1);
		}
		else
			printchar(str[i], &g_count);
	}
	va_end(args);
	return (g_count);
}
