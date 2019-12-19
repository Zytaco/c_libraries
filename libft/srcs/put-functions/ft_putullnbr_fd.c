/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putullnbr_fd.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 15:54:47 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/12/18 15:54:48 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** maximum ULL value:
** 18446744073709551615
*/

void			ft_putullnbr_fd(unsigned long long n, int fd)
{
	char	s[21];
	int		i;

	if (n == 0)
		write(fd, "0", 1);
	else
	{
		s[20] = '\0';
		i = 20;
		while (n > 0)
		{
			i--;
			s[i] = (n % 10) + '0';
			n /= 10;
		}
		ft_putstr_fd(s + i, fd);
	}
}
