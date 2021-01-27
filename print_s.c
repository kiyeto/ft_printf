/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:41:29 by abenouda          #+#    #+#             */
/*   Updated: 2019/12/19 00:10:50 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prints_wp(char *s, t_flags *flg, int *count)
{
	int	p;
	int	i;

	i = 0;
	p = flg->prcn;
	g_spaces = flg->width - flg->prcn;
	if (flg->minus == 0)
		prints_pm(count, s, &i, flg);
	else
		prints_pnom(s, count, &i, flg);
}

void	prints_w(char *s, t_flags *flg, int *count)
{
	g_spaces = flg->width - slen(s);
	if (flg->minus == 0)
	{
		while (g_spaces-- > 0)
			printchar(' ', count);
		printstr(s, count);
	}
	else
	{
		printstr(s, count);
		while (g_spaces-- > 0)
			printchar(' ', count);
	}
}

void	prints_p(char *s, t_flags *flg, int *count)
{
	int	p;
	int	i;

	i = 0;
	g_spaces = flg->width - flg->prcn;
	p = flg->prcn;
	if (flg->prcn == 0)
	{
		g_spaces = flg->width;
		while (g_spaces-- > 0)
			printchar(' ', count);
	}
	else
	{
		if (flg->minus == 0)
			prints_pm(count, s, &i, flg);
		else
			prints_pnom(s, count, &i, flg);
	}
}

void	print_s(t_flags *flg, va_list args, int *count)
{
	char	*s;
	int		len;

	s = va_arg(args, char *);
	if (s == NULL)
		s = "(null)";
	len = slen(s);
	if (flg->flag_exist == 0 || (flg->width <= len
			&& (flg->prcn >= len || flg->prcn == -1)))
	{
		printstr(s, count);
		return ;
	}
	if (flg->width >= len && (flg->prcn < len
			&& flg->prcn >= 0))
		prints_wp(s, flg, count);
	if (flg->width >= len && (flg->prcn >= len
			|| flg->prcn == -1))
		prints_w(s, flg, count);
	if (flg->width < len && (flg->prcn < len
			&& flg->prcn >= 0))
		prints_p(s, flg, count);
}
