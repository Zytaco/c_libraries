/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_cpy_array.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 17:34:23 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/07 17:34:24 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libsort.h"

void	sort_cpy_array(t_array *from, t_array *into)
{
	U_INT i;

	if (!from || !into)
		return ;
	i = 0;
	while (i < from->size && i < into->size)
	{
		into->array[i] = from->array[i];
		i++;
	}
}
