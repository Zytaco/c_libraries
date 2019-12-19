/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putllbase_fd.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 18:45:58 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/12/18 18:45:58 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void		exceptions_l(int base, int fd)
{
	const char *exceptions[35] = {
	"-1000000000000000000000000000000000000000000000000000000000000000",
	"-2021110011022210012102010021220101220222",
	"-20000000000000000000000000000000", "-1104332401304422434310311213",
	"-1540241003031030222122212", "-22341010611245052052301",
	"-1000000000000000000000", "-67404283172107811828", "-9223372036854775808",
	"-1728002635214590698", "-41a792678515120368", "-10b269549075433c38",
	"-4340724c6c71dc7a8", "-160e2ad3246366808", "-8000000000000000",
	"-33d3d8307b214009", "-16agh595df825fa8", "-ba643dci0ffeehi",
	"-5cbfjia3fh26ja8", "-2heiciiie82dh98", "-1adaibb21dckfa8",
	"-i6k448cf4192c3", "-acd772jnc9l0l8", "-64ie1focnn5g78", "-3igoecjbmca688",
	"-27c48l5b37oaoq", "-1bk39f3ah3dmq8", "-q1se8f0m04isc", "-hajppbc1dc208",
	"-bm03i95hia438", "-8000000000000", "-5hg4ck9jd4u38", "-3tdtk1v8j6tpq",
	"-2pijmikexrxp8", "-1y2p0ij32e8e8"};

	ft_putstr_fd(exceptions[base - 2], fd);
}

static void		exceptions_u(int base, int fd)
{
	const char *exceptions[35] = {
	"-1000000000000000000000000000000000000000000000000000000000000000",
	"-2021110011022210012102010021220101220222",
	"-20000000000000000000000000000000", "-1104332401304422434310311213",
	"-1540241003031030222122212", "-22341010611245052052301",
	"-1000000000000000000000", "-67404283172107811828", "-9223372036854775808",
	"-1728002635214590698", "-41A792678515120368", "-10B269549075433C38",
	"-4340724C6C71DC7A8", "-160E2AD3246366808", "-8000000000000000",
	"-33D3D8307B214009", "-16AGH595DF825FA8", "-BA643DCI0FFEEHI",
	"-5CBFJIA3FH26JA8", "-2HEICIIIE82DH98", "-1ADAIBB21DCKFA8",
	"-I6K448CF4192C3", "-ACD772JNC9L0L8", "-64IE1FOCNN5G78", "-3IGOECJBMCA688",
	"-27C48L5B37OAOQ", "-1BK39F3AH3DMQ8", "-Q1SE8F0M04ISC", "-HAJPPBC1FC208",
	"-BM03I95HIA438", "-8000000000000", "-5HG4CK9JD4U38", "-3TDTK1V8J6TPQ",
	"-2PIJMIKEXRXP8", "-1Y2P0IJ32E8E8"};

	ft_putstr_fd(exceptions[base - 2], fd);
}

void			ft_putllbase_fd(unsigned long long n, int base,
														int fd, char up_case)
{
	if (base < 2 || base > 36)
		return ;
	else if (n == -9223372036854775808)
	{
		if (up_case)
			exceptions_u(base, fd);
		else
			exceptions_l(base, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putullbase_fd(-1 * n, base, fd, up_case);
	}
	else
		ft_putullbase_fd(n, base, fd, up_case);
}
