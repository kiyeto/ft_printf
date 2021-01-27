/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 00:28:45 by abenouda          #+#    #+#             */
/*   Updated: 2019/12/18 21:13:39 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prints_pm(int *count, char *s, int *i, t_flags *flg)
{
	int p;

	p = flg->prcn;
	while (g_spaces-- > 0)
		printchar(' ', count);
	while (p-- > 0)
	{
		printchar(s[*i], count);
		(*i)++;
	}
}

void	prints_pnom(char *s, int *count, int *i, t_flags *flg)
{
	int p;

	p = flg->prcn;
	while (p-- > 0)
	{
		printchar(s[*i], count);
		(*i)++;
	}
	while (g_spaces-- > 0)
		printchar(' ', count);
}
