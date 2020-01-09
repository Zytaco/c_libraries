/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itobase.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/28 17:26:22 by tide-jon       #+#    #+#                */
/*   Updated: 2019/06/28 17:26:24 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char			*ft_itoabase(LL n, int base)
{
	char	*s;
	int		len;

	if (base <= 1)
		return (NULL);
	len = ft_count_digits(n);
	if (n < 0)
		len++;
	s = ft_strnew(len);
	if (n < 0)
		s[0] = '-';
	while (len > 0)
	{
		len--;
		s[len] = n % base + '0';
		n /= base;
	}
	return (s);
}
