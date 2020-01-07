/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_pointer.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 12:42:36 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/12/17 12:42:36 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_point_flag_cor(t_flags *f)
{
	f->space = 0;
	f->plus = 0;
	if (f->minus && f->zero)
		f->zero = 0;
}

void		ft_printf_point_width(t_flags flags, int arg_len, char bef)
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

char		ft_printf_point_getstr(t_flags flags,  char upper)
{
	char	*s;
	ULL		a;

	a = va_arg(flags.list, void*);
	s = ft_ulltoabase(ft_printf_point_get_arg(flags), 16);
	if (flags.prec_f)
		s[flags.prec] = '\0';
	ft_strprepp("0X", &s);
	if (!upper)
		ft_strlower(s);
	return (s);	
}

void		ft_printf_point(t_flags flags, char upper)
{
	char	*s;
	int		arg_len;

	s = ft_printf_point_getstr(flags, upper);
	ft_printf_point_flag_cor(&flags);
	arg_len = ft_strlen(s);
	ft_printf_point_width(flags, arg_len, 1);
	*(flags.count) += arg_len;
	ft_putstr(s);
	free(s);
	ft_printf_point_width(flags, arg_len, 0);
}
