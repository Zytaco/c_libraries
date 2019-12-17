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

#include "../../includes/libft.h"
#include <stdarg.h>

static void	recognise_arg(const char *format, int *len, va_list list)
{
	int			pos;
	const char	*key = "cspdiouxX%";
	void		(*const f[])(const char *, int *, va_list) = {
	ft_printf_char, ft_printf_str, ft_printf_pointer, ft_printf_int,
	ft_printf_int, ft_printf_oct, ft_printf_unsint, ft_printf_hexL,
	ft_printf_hexU, ft_printf_perc};

	pos = ft_skipnstr((char*)format, (char*)key);
	if (!format[pos])
		ft_error("Loose % given to ft_printf");
	pos = ft_skipstr((char*)key, (char[2]){format[pos], '\0'});
}

int			ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list list;

	va_start(list, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			recognise_arg(format + i, &len, list);
		else
			write(1, format + i, 1);
		i++;
	}
	return (len + i);
}
