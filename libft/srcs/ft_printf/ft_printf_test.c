/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 17:40:09 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/12/18 17:40:10 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	int ret1;
	int r;

	ret1 = printf("%5c\n", 'c');
	r = ft_printf("%5c\n", 'c');
}
