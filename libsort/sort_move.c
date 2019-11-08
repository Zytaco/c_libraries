/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_move.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 15:14:45 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/07 15:14:45 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libsort.h"

void		sort_move(int *array, U_INT size, U_INT now, U_INT new)
{
	U_INT	i;
	int		x;

	if (new == now || new >= size || now >= size)
		return ;
	x = array[now];
	if (new < now)
	{
		i = new;
		while (i + 1 <= now)
		{
			array[i + 1] = array[i];
			i++;
		}
	}
	else
	{
		i = now;
		while (i + 1 <= new)
		{
			array[i] = array[i + 1];
			i++;
		}
	}
	array[new] = x;
}
