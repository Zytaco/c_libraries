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

char		*float_exceptions(long double f)
{
	union u_float	u_float;

	if (EXP_ALL_ONE)
	{
		if (BIT_63 && !BIT_62 && MANT_ALL_ZERO)
			return (ft_strdup("-inf" + FL_SIGN));
		else
			return (ft_strdup("NaN"));
	}
	else
		return (NULL);
}

size_t		get_double_len(long double f, int base)
{
	size_t	len;

	len = 1;
	while (!(-base < f && f < base))
	{
		len++;
		f /= base;
	}
	return ((f < 0) ? len + 1 : len);
}

char		*get_f(long double f, size_t prec)
{
	char			*ret;
	size_t			double_len;

	ret = float_exceptions(f);
	if (ret)
		return (ret);
	double_len = get_double_len(f, 10);
	ret = ft_strnew(double_len + 1 + prec);
	if (prec != 0)
		ret[double_len] = '.';
	else
		ret[double_len] = '\0';



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
