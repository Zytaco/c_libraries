/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_join_arrays.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 17:30:36 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/07 17:30:36 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libsort.h"

static t_array	*make_total_size_array(t_array **array_array)
{
	U_INT	i;
	U_INT	size;

	size = 0;
	i = 0;
	while (array_array[i])
	{
		size += array_array[i]->size;
		i++;
	}
	return (sort_new_array(NULL, size));
}

t_array			*sort_join_arrays(t_array **array_array)
{
	U_INT	i;
	U_INT	j;
	U_INT	pos;
	t_array *new;

	new = make_total_size_array(array_array);
	i = 0;
	pos = 0;
	while (array_array[i])
	{
		j = 0;
		while (j < array_array[i]->size)
		{
			new->array[pos + j] = array_array[i]->array[j];
			j++;
		}
		pos += j;
		sort_free_array(array_array + i);
		i++;
	}
	free(array_array);
	return (new);
}
