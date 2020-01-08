/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_float.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 13:09:31 by jheeresm      #+#    #+#                 */
/*   Updated: 2020/01/08 13:09:31 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_ldtoa(long double f)
{
	f = f - 1 + 1;
	return (ft_strdup(" ERROR(f/F) "));
}

static void	ft_printf_float_flag_cor(t_flags *f)
{
	if (f->smallest + f->small + f->big + f->biggest > 1)
		ft_error("ERROR: ft_printf: multiple size flags are active on a %s.");
	if (f->minus && f->zero)
		f->zero = 0;
}

char		*ft_printf_float(t_flags *flags, va_list list)
{
	char		*arg;

	ft_printf_float_flag_cor(flags);
	if (flags->float_biggest)
		arg = ft_ldtoa(va_arg(list, long double));
	else
		arg = ft_ldtoa(va_arg(list, double));
	if (flags->type == ft_toupper(flags->type))
		ft_strupper(arg);
	return (arg);
}
