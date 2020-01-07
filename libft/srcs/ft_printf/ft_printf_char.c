/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_char.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 12:42:22 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/12/17 12:42:22 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_char_flag_cor(t_flags *f)
{
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

void		ft_printf_char(t_flags flags)
{
	char	c;

	ft_printf_char_flag_cor(&flags);
	(*flags.count) += ft_min(1, flags.width);
	ft_printf_char_width(flags, 1, 1);
	c = va_arg(flags.list, char);
	write(1, &c, 1);
	ft_printf_char_width(flags, 1, 0);
}
