/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:53:36 by abenouda          #+#    #+#             */
/*   Updated: 2019/12/18 23:24:23 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_flag
{
	long		width;
	long		prcn;
	int			minus;
	int			zero;
	int			flag_exist;
}				t_flags;

int				g_spaces;

void			printchar(char c, int *count);

void			printnbr(int n, int *count);

void			printunbr(unsigned int n, int *count);

void			printstr(char *s, int *count);

int				printaddress(size_t num, int *count);

int				ft_isdigit(int c);

char			*is_conversion(char *str, int c);

int				convert_to(char c, va_list args, t_flags *flg, int *count);

void			get_flags(char *str, int *i, va_list args, t_flags *flg);

int				ft_printf(const char *str, ...);

void			print_c(va_list args, t_flags *flg, int *count);

int				numlen(int nb);

int				unumlen(unsigned int nb);

int				slen(char *str);

int				xlen(unsigned int n);

int				plen(size_t n);

void			print_u(t_flags *flg, va_list args, int *count);

void			printu_0precision(t_flags *flg, int *count);

void			printu_wp(t_flags *flg, unsigned int num, int *count);

void			printu_w(unsigned int num, t_flags *flg, int *count);

void			printu_p(unsigned int num, t_flags *flg, int *count);

void			print_percent(t_flags *flg, int *count);

void			print_d(t_flags *flg, va_list args, int *count);

void			printd_p(t_flags *flg, int *count, int num);

void			printd_nop(t_flags *flg, int *count, int num);

void			printd_wp(t_flags *flg, int *count, int num);

void			printds_w(int num, t_flags *flg, int *count);

void			printds_p(int *count, int num, int spaces);

void			printds_zero(int *count, int num, int spaces);

void			printdu_w(int num, t_flags *flg, int *count);

void			printdu_wp(int num, t_flags *flg, int *count);

void			printds_wp(int num, t_flags *flg, int *count);

void			print_s(t_flags *flg, va_list args, int *count);

void			prints_p(char *s, t_flags *flg, int *count);

void			prints_w(char *s, t_flags *flg, int *count);

void			prints_wp(char *s, t_flags *flg, int *count);

void			prints_pm(int *count, char *s, int *i, t_flags *flg);

void			prints_pnom(char *s, int *count, int *i, t_flags *flg);

char			*convert(size_t num, int x);

int				print_x(t_flags *flg, va_list args, int *count, int x);

void			printx_nop(unsigned int num, t_flags *flg, int *count, char *s);

void			printx_p(t_flags *flg, int *count, unsigned int num, char *s);

void			printx_0prcn(t_flags *flg, int *count);

int				printx_w(unsigned int num, char *s, t_flags *flg, int *count);

int				printx_wp(unsigned int num, char *s, t_flags *flg, int *count);

int				print_p(t_flags *flg, va_list args, int *count);

void			noprecision(t_flags *flg, int *count, int spaces);

int				printp_w(size_t num, t_flags *flg, int *count);

#endif
