/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 15:02:58 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/08 14:23:14 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_memdel(void **ap)
{
	if (ap != 0)
	{
		*ap = (void*)0;
		free(*ap);
	}
}
