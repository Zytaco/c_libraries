/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_flags.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 09:35:58 by jheeresm      #+#    #+#                 */
/*   Updated: 2020/01/08 09:35:59 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char			*ft_printf_plus(char *arg, t_flags flags)
{
	int i;

	if (!flags.plus)
		return (arg);
	if (flags.type == 'a' || flags.type == 'A' || flags.type == 'd' ||
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

char			*ft_printf_space(char *arg, t_flags flags)
{
	int i;

	if (!flags.space || flags.plus)
		return (arg);
	if (flags.type == 'a' || flags.type == 'A' || flags.type == 'd' ||
	flags.type == 'e' || flags.type == 'E' || flags.type == 'f' ||
	flags.type == 'F' || flags.type == 'g' || flags.type == 'G' ||
	flags.type == 'i')
	{
		i = ft_skipstr(arg, "0 ");
		if (arg[i] != '-' && arg[i] != '+')
			arg = ft_strins(&arg, "+", i);
	}
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
	if (flags.zero &&
	!(flags.type == 'd' || flags.type == 'i' || flags.type == 'o' ||
	flags.type == 'u' || flags.type == 'x' || flags.width == 'X'))
		filler = ft_strrepeat("0", flags.width - len);
	else
		filler = ft_strrepeat(" ", flags.width - len);
	if (flags.minus)
		arg = ft_strprepp(filler, &arg);
	else
		arg = ft_strapp(&arg, filler);
	return (arg);
}
