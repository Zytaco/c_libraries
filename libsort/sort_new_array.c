/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_new_array.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 13:29:30 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/07 13:29:31 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libsort.h"

t_array	*sort_new_array(int *arr, U_INT size)
{
	t_array	*new;
	U_INT	i;

	if (!arr || size <= 0)
		return (NULL);
	new = malloc(sizeof(t_array));
	new->array = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		if (!arr)
			new->array[i] = 0;
		else
			new->array[i] = arr[i];
		i++;
	}
	new->size = size;
	return (new);
}
