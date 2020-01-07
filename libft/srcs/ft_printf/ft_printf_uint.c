/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_uint.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 12:43:11 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/12/17 12:43:11 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_uint_flag_cor(t_flags *f)
{
	f->space = 0;
	f->plus = 0;
	if (f->smallest + f->small + f->big + f->biggest > 1)
		ft_error("ERROR: ft_printf: multiple size flags are active on a %s.");
	if (f->minus && f->zero)
		f->zero = 0;
}

void		ft_printf_uint_width(t_flags flags, int arg_len, char bef)
{
	char c;

	if (flags.minus && bef || (!flags.minus && !bef))
		return ;
	if (flags.zero)
		c = '0';
	else
		c = ' ';
	while (flags.width > arg_len)
	{
		write(1, c, 1);
		arg_len++;
	}
}

char		ft_printf_uint_getstr(t_flags flags, int base, char upper)
{
	char	*s;
	ULL		a;

	if (flags.smallest)
		a = va_arg(flags.list, U char);
	else if (flags.small)
		a = va_arg(flags.list, U short);
	else if (flags.big)
		a = va_arg(flags.list, UL);
	else if (flags.biggest)
		a = va_arg(flags.list, ULL);
	s = ft_ulltoabase(a, base);
	if (flags.prec_f)
		s[flags.prec] = '\0';
	if (base == 8)
		ft_strprepp("0", &s);
	else if (base == 16)
		ft_strprepp("0X", &s);
	if (!upper)
		ft_strlower(s);
	return (s);	
}

void		ft_printf_uint(t_flags flags, int base, char upper)
{
	char	*s;
	int		arg_len;

	s = ft_printf_uint_getstr(flags, base, upper);
	ft_printf_uint_flag_cor(&flags);
	arg_len = ft_strlen(s);
	ft_printf_uint_width(flags, arg_len, 1);
	*(flags.count) += arg_len;
	ft_putstr(s);
	free(s);
	ft_printf_uint_width(flags, arg_len, 0);
}
