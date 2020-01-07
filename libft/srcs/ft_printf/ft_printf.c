/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 16:59:19 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/12/16 16:59:19 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_printf_space(char *arg, t_flags flags)
{
	int i;

	if (!flags.space || flags.plus)
		return (arg);
	if (flags.type == 'a'  || flags.type == 'A' || flags.type == 'd' ||
	flags.type == 'e' || flags.type == 'E' || flags.type == 'f' ||
	flags.type == 'F' || flags.type == 'g' || flags.type == 'G' ||
	flags.type == 'i')
	{
		i = ft_skipstr(arg, "0 ");
		if (arg[i] != '-' && arg[i] != '+')
			arg = ft_strins(&arg, "+", i);
	}
}

char			*ft_printf_plus(char *arg, t_flags flags)
{
	int i;

	if (!flags.plus)
		return (arg);
	if (flags.type == 'a'  || flags.type == 'A' || flags.type == 'd' ||
	flags.type == 'e' || flags.type == 'E' || flags.type == 'f' ||
	flags.type == 'F' || flags.type == 'g' || flags.type == 'G' ||
	flags.type == 'i')
	{
		i = ft_skipstr(arg, "0 ");
		if (arg[i] != '-' && arg[i] != '+')
			arg = ft_strins(&arg, "+", i);
	}
	return (arg);
}

char			*ft_printf_hash(char *arg, t_flags flags)
{
	if (!flags.hash)
		return (arg);
	if (flags.type == 'o')
		arg = ft_strprepp("0", &arg);
	else if (flags.type == 'x')
		arg = ft_strprepp("0x", &arg);
	else if (flags.type == 'X')
		arg = ft_strprepp("0X", &arg);
	else if ((flags.type == 'a' || flags.type == 'A' || flags.type == 'e' ||
	flags.type == 'E' || flags.type == 'f' || flags.type == 'F' ||
	flags.type == 'g' || flags.type == 'G') && !ft_strchr(arg, '.'))
		arg = ft_strapp(&arg, ".");
	return (arg);
}

char			*ft_printf_prec(char *arg, t_flags flags)
{
	int dot;

	if (!flags.prec_f)
		return (arg);
	if (flags.type == 'd' || flags.type == 'i' || flags.type == 'o' ||
	flags.type == 'u' || flags.type == 'x' || flags.width == 'X')
	{
		if (ft_strlen(arg) < flags.prec)
			arg = ft_strprepp(ft_strrepeat("0",
										flags.prec - ft_strlen(arg)), &arg);
	}
	return (arg);
}

char			*ft_printf_add_width(char *arg, int len, t_flags flags)
{
	char	*filler;

	if (len <= flags.width)
		return (arg);
	if (flags.zero && !(flags.type == 'd' || flags.type == 'i'
	|| flags.type == 'o' || flags.type == 'u' || flags.type == 'x' ||
	flags.width == 'X'))
		filler = ft_strrepeat("0", flags.width - len);
	else
		filler = ft_strrepeat(" ", flags.width - len);
	if (flags.minus)
		arg = ft_strprepp(filler, &arg);
	else
		arg = ft_strapp(&arg, filler);
	return (arg);
}

void			ft_printf_print_w_p(char *arg, int *count, t_flags flags)
{
	int		len;

	arg = ft_printf_prec(arg, flags);
	arg = ft_printf_add_width(arg, ft_strlen(arg), flags);
	arg = ft_printf_hash(arg, flags);
	*count += ft_strlen(arg);
	ft_putstr(arg);
	free(arg);
}

static int		flag_checks_one(t_flags *fl, char *format, int i)
{
	if (format[i] == '#')
		fl->hash = 1;
	else if (format[i] == '0')
		fl->zero = 1;
	else if (format[i] == '-' && !ft_isdigit(format[i + 1]))
		fl->minus = 1;
	else if (format[i] == '+')
		fl->plus = 1;
	else if (format[i] == ' ')
		fl->space = 1;
	else if (format[i] == 'd' && format[i + 1] == 'd')
		fl->smallest = 1;
	else if (format[i] == 'd' && format[i + 1] != 'd' && format[i - 1] != 'd')
		fl->small = 1;
	else if (format[i] == 'l' && format[i + 1] != 'l' && format[i - 1] != 'l')
		fl->big = 1;
	else if (format[i] == 'l' && format[i + 1] == 'l')
		fl->biggest = 1;
	else
		return (flag_checks_two(fl, format, i));
	return (1);
}

static int		flag_checks_two(t_flags *fl, char *format, int i)
{
	if (format[i] == 'L')
		fl->float_biggest = 1;
	else if (ft_isdigit(format[i]) && format[i - 1] != '.')
	{
		fl->width_f = 1;
		fl->width = ft_atoi(format + i);
	}
	else if (format[i] == '.' && ft_isdigit(format[i + 1]))
	{
		fl->prec_f = 1;
		fl->prec = ft_atoi(format + i + 1);
	}
	else
		return (0);
	return (1);
}

void			get_flags(const char *format, int i, t_flags flags)
{
	while (format[i])
	{
		if (format[i] == 'c')
			ft_printf_char(flags);
		else if (format[i] == 's')
			ft_printf_str(flags);
		else if (format[i] == 'p')
			ft_printf_str(flags);
		else if (format[i] == 'd' || format[i] == 'i')
			ft_printf_str(flags);
		else if (format[i] == 'o')
			ft_printf_str(flags);
		else if (format[i] == 'u')
			ft_printf_str(flags);
		else if (format[i] == 'x')
			ft_printf_str(flags);
		else if (format[i] == 'X')
			ft_printf_str(flags);
		else if (flag_checks_one(&flags, format, i))
			i++;
		else
			return ;
	}
}

int				ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list list;

	va_start(list, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			get_flags(format, i + 1,
			(t_flags){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, &count, list});
		}
		else
		{
			write(1, format + i, 1);
			count++;
		}
		i++;
	}
	va_end(list);
	return (count);
}
