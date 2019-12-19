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
	"-111111111111111111111111111111111111111111111111111111111111111",
	"-2021110011022210012102010021220101220221",
	"-13333333333333333333333333333333", "-1104332401304422434310311212",
	"-1540241003031030222122211", "-22341010611245052052300",
	"-777777777777777777777", "-67404283172107811827", "-9223372036854775807",
	"-1728002635214590697", "-41a792678515120367", "-10b269549075433c37",
	"-4340724c6c71dc7a7", "-160e2ad3246366807", "-7FFFFFFFFFFFFFFF",
	"-33d3d8307b214008", "-16agh595df825fa7", "-ba643dci0ffeehh",
	"-5cbfjia3fh26ja7", "-2heiciiie82dh97", "-1adaibb21dckfa7",
	"-i6k448cf4192c2", "-acd772jnc9l0l7", "-64ie1focnn5g77", "-3igoecjbmca687",
	"-27c48l5b37oaop", "-1bk39f3ah3dmq7", "-q1se8f0m04isb", "-hajppbc1dc207",
	"-bm03i95hia437", "-7VVVVVVVVVVVV", "-5hg4ck9jd4u37", "-3tdtk1v8j6tpp",
	"-2pijmikexrxp7", "-1y2p0ij32e8e7"};

	ft_putstr_fd(exceptions[base - 2], fd);
}

static void		exceptions_u(int base, int fd)
{
	const char *exceptions[35] = {
	"-111111111111111111111111111111111111111111111111111111111111111",
	"-2021110011022210012102010021220101220221",
	"-13333333333333333333333333333333", "-1104332401304422434310311212",
	"-1540241003031030222122211", "-22341010611245052052300",
	"-777777777777777777777", "-67404283172107811827", "-9223372036854775807",
	"-1728002635214590697", "-41A792678515120367", "-10B269549075433C37",
	"-4340724C6C71DC7A7", "-160E2AD3246366807", "-7FFFFFFFFFFFFFFF",
	"-33D3D8307B214008", "-16AGH595DF825FA7", "-BA643DCI0FFEEHH",
	"-5CBFJIA3FH26JA7", "-2HEICIIIE82DH97", "-1ADAIBB21DCKFA7",
	"-I6K448CF4192C2", "-ACD772JNC9L0L7", "-64IE1FOCNN5G77", "-3IGOECJBMCA687",
	"-27C48L5B37OAOP", "-1BK39F3AH3DMQ7", "-Q1SE8F0M04ISB", "-HAJPPBC1FC207",
	"-BM03I95HIA437", "-7VVVVVVVVVVVV", "-5HG4CK9JD4U37", "-3TDTK1V8J6TPP",
	"-2PIJMIKEXRXP7", "-1Y2P0IJ32E8E7"};

	ft_putstr_fd(exceptions[base - 2], fd);
}

void			ft_putllbase_fd(LL n, int base,
														int fd, char up_case)
{
	if (base < 2 || base > 36)
		return ;
	else if (n == -9223372036854775807LL)
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
