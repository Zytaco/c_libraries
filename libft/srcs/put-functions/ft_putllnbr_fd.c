/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putllnbr_fd.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 15:58:03 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/12/18 15:58:04 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void			ft_putllnbr_fd(long long n, int fd)
{
	if (n == -9223372036854775808LL)
		ft_putstr("-9223372036854775808");
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putullnbr_fd(-1 * n, fd);
	}
	else
		ft_putullnbr_fd(n, fd);
}
