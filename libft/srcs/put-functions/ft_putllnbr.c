/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putllnbr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/28 17:08:07 by tide-jon       #+#    #+#                */
/*   Updated: 2019/06/28 17:08:58 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void			ft_putllnbr(long long n)
{
	ft_putllnbr_fd(n, 1);
}
