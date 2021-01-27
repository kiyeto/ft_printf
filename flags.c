/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:12:37 by abenouda          #+#    #+#             */
/*   Updated: 2019/12/15 22:03:37 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_num(char *ptr, int *i)
{
	int	res;

	res = 0;
	while (*ptr >= '0' && *ptr <= '9')
	{
		res = (res * 10) + (*ptr - '0');
		(*i)++;
		ptr++;
	}
	return (res);
}

void	get_precision(char *str, int *i, va_list args, t_flags *flg)
{
	(*i)++;
	if (ft_isdigit(str[*i]))
		flg->prcn = get_num(&str[*i], i);
	else if (str[*i] == '*')
	{
		(*i)++;
		flg->prcn = va_arg(args, int);
		if (flg->prcn < 0)
			flg->prcn = -1;
	}
	else
		flg->prcn = 0;
}

void	get_star_value(va_list args, int *i, t_flags *flg)
{
	(*i)++;
	flg->width = va_arg(args, int);
	if (flg->width < 0)
	{
		flg->minus = 1;
		flg->width *= -1;
	}
}

void	get_flags(char *str, int *i, va_list args, t_flags *flg)
{
	(*i)++;
	while (is_conversion("cspduixX%", str[*i]) == NULL)
	{
		if (str[*i] == '0')
		{
			flg->zero = 1;
			(*i)++;
		}
		if (str[*i] == '-')
		{
			flg->minus = 1;
			(*i)++;
		}
		if (ft_isdigit(str[*i]) == 1)
			flg->width = get_num(&str[*i], i);
		else if (str[*i] == '*')
			get_star_value(args, i, flg);
		if (str[*i] == '.')
			get_precision(str, i, args, flg);
	}
	if (flg->minus != 0 || flg->zero != 0 || flg->prcn >= 0 || flg->width > 0)
		flg->flag_exist = 1;
}
