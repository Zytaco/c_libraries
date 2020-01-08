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

char			*ft_printf_get_arg(t_flags *flags, va_list list, char type)
{
	if (type == 'd' || type == 'i' || type == 'D')
		return (ft_printf_int(flags, 10, 1));
	else if (type == 'o' || type == 'O')
		return (ft_printf_uint(flags, 8, 1));
	else if (type == 'u' || type == 'U')
		return (ft_printf_uint(flags, 10, 1));
	else if (type == 'x' || type == 'X')
		return (ft_printf_uint(flags, 16, type == 'X' ? 1 : 0));
	else if (type == 'e' || type == 'E')
		return (ft_strdup(""));
	else if (type == 'f' || type == 'F')
		return (ft_strdup(""));
	else if (type == 'g' || type == 'G')
		return (ft_strdup(""));
	else if (type == 'a' || type == 'A')
		return (ft_strdup(""));
	else if (type == 'c' || type == 'C')
		return (ft_printf_char(flags));
	else if (type == 's' || type == 'S')
		return (ft_printf_str(flags));
	else if (type == 'p')
		return (ft_printf_pointer(flags));
	else if (type == 'n')
		return (ft_strdup(""));
	return (ft_printf_perc(flags));
}

void			get_flags(const char *f, int i, t_flags flags)
{
	char *arg;

	while (f[i] && f[i] != 'd' && f[i] != 'i' && f[i] != 'D' && f[i] != 'o' &&
	f[i] != 'O' && f[i] != 'u' && f[i] != 'U' && f[i] != 'x' && f[i] != 'X' &&
	f[i] != 'e' && f[i] != 'E' && f[i] != 'f' && f[i] != 'F' && f[i] != 'g' &&
	f[i] != 'G' && f[i] != 'a' && f[i] != 'A' && f[i] != 'c' && f[i] != 'C' &&
	f[i] != 's' && f[i] != 'S' && f[i] != 'p' && f[i] != 'n' && f[i] != '%')
		flag_checks_one(&flags, f, i);
	if (!f[i])
		return ;
	flags.type = f[i];
	arg = ft_printf_get_arg(&flags, flags.list, f[i]);
	arg = ft_printf_hash(arg, flags);
	arg = ft_printf_plus(arg, flags);
	arg = ft_printf_space(arg, flags);
	arg = ft_printf_prec(arg, flags);
	arg = ft_printf_width(arg, flags);
	*(flags.count) += ft_strlen(arg);
	ft_putstr(arg);
	free(arg);
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
			(t_flags){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
														&count, list, '\0'});
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
