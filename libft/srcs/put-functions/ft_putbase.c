/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putbase.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/19 12:22:51 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/12/19 12:22:51 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putbase(int n, int base, int fd, int up_case)
{
	ft_putllbase_fd(n, base, 1, up_case);
}
