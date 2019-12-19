/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utoabase.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/19 13:54:04 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/12/19 13:54:04 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_countu_digits(ULL n)
{
	return (1);
}

char	*ft_itoabase(LL n, int base)
{
	char	*s;
	int		len;

	if (base <= 1)
		return (NULL);
	len = ft_count_digits(n);
	s = ft_strnew(len);
	while (len > 0)
	{
		len--;
		s[len] = n % base + '0';
		n /= base;
	}
	return (s);
}
