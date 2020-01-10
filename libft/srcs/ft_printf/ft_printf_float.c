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

/*
**	mantissa: 8 Bytes
**	determinant: 2 Bytes (-1 bit for sign)
*/

char		*get_f(long double f, size_t prec)
{
	char		*ret;
	long double	factor;
	int			dot;

	dot = 1;
	factor = 1.;
	while (f > factor)
	{
		dot++;
		factor *= 10;
	}
	while (f < factor)
	{
		dot--;
		factor /= 10;
	}
	ret = ft_itobase((LL)f, 10);
	ft_strprep(ft_strrepeat("0", dot * -1), &ret);
	ft_strapp(&ret, ft_strrepeat("0", dot + prec + 1));
	if (f < 0)
		ft_strprep("-", &ret);
	if (prec > 0)
	{
		ft_strins(&ret, ".", dot);
		ret[dot + prec + 1] = '\0';
	}
	else
		ret[dot] = '\0';
	return (ret);
}

static void	ft_printf_float_flag_cor(t_flags *f)
{
	if (!(f->prec_f))
	{
		if (f->type == 'f' || f->type == 'F')
			f->prec = 6;
		else
			ft_error("ERROR: float called with invalid type");
	}
	if ((f->type == 'g' || f->type == 'G') && f->prec_f && f->prec == 0)
		f->prec = 1;
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
		arg = get_f(va_arg(list, long double), flags->prec);
	else
		arg = get_f(va_arg(list, double), flags->prec);
	if (flags->type == ft_toupper(flags->type))
		ft_strupper(arg);
	return (arg);
}
