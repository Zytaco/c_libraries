/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_str.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 12:42:28 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/12/17 12:42:28 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_str_flag_cor(t_flags *f)
{
	if (f->smallest + f->small + f->big + f->biggest > 1)
		ft_error("ERROR: ft_printf: multiple size flags are active on a %s.");
	if (f->minus && f->zero)
		f->zero = 0;
}

void		ft_printf_char_width(t_flags flags, int arg_len, char bef)
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

void		ft_printf_str(t_flags f)
{
	char	*s;
	int		arg_len;

	ft_printf_str_flag_cor(&f);
	s = va_arg(f.list, char*);
	arg_len = ft_strlen(s);
	if (arg_len > f.prec)
	{
		s[f.prec] = '\0';
		arg_len = f.prec;
	}
	(*f.count) += ft_max(arg_len, f.width);
	ft_printf_char_width(f, 1, 1);
	ft_putstr(s);
	ft_printf_char_width(f, 1, 0);
}
