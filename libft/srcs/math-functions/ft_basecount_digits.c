/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_basecount_digits.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/19 13:59:49 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/12/19 13:59:49 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_basecount_digits(ULL n, int base)
{
	int digits;

	if (base <= 0)
		return (INT32_MAX);
	else if (base == 1)
		return (n);
	if (n == 0)
		return (1);
	digits = 0;
	while (n != 0)
	{
		digits++;
		n /= base;
	}
	return (digits);
}
