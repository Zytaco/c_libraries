/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 13:33:30 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/11 12:54:41 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_itoa(long long n)
{
	char	*s;
	int		len;

	len = ft_count_digits(n);
	if (n < 0)
		len++;
	s = ft_strnew(len);
	if (n < 0)
		s[0] = '-';
	while (len > 0)
	{
		len--;
		s[len] = n % 10 + '0';
		n /= 10;
	}
	return (s);
}
