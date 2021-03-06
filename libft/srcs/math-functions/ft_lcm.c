/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lcm.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 15:04:48 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/12/16 15:04:48 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

LL	ft_lcm(LL a, LL b)
{
	ULL i;

	if (a == 0 || b == 0 || (a < 0 && b > 0) || (a > 0 && b < 0))
		return (-1);
	i = (a < b) ? (b / a) : (a / b);
	while (i * a > 0)
	{
		if (b % (i * a) == 0)
			return (i * a);
		i++;
	}
	return (-1);
}
