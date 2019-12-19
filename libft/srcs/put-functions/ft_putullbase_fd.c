/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putullbase_fd.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 18:36:15 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/12/18 18:36:15 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** maximum length: 64
** 11111111 11111111 11111111 11111111 11111111 11111111 11111111 11111111
*/

void			ft_putullbase_fd(ULL n, int base, int fd,
																char up_case)
{
	const char	lower[37] = "0123456789abcdefghijklmnopqrstuvwxyz";
	const char	upper[37] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char		s[65];
	int			i;

	if (base < 2 || base > 36)
		return ;
	if (n == 0)
		write(fd, "0", 1);
	else
	{
		s[64] = '\0';
		i = 64;
		while (n > 0)
		{
			i--;
			if (up_case)
				s[i] = upper[n % base];
			else
				s[i] = lower[n % base];
			n /= base;
		}
		ft_putstr_fd(s + i, fd);
	}
}
