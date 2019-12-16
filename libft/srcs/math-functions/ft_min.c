/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_min.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 14:11:51 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/11 14:11:52 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

long long	ft_min(long long a, long long b)
{
	if (a <= b)
		return (a);
	return (b);
}
