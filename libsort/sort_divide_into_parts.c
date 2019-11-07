/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_divide_into_parts.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 13:40:11 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/07 13:40:11 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libsort.h"

/*
** Returns a NULL-terminated array of n_of_parts array-objects.
** The last array may be smaller than the rest.
*/

t_array		**sort_divide_into_parts(t_array *a, U_INT n_of_parts)
{
	t_array	**array_array;
	U_INT	i;
	U_INT	part_size;

	if (!a || n_of_parts <= 0)
		return (NULL);
	array_array = malloc(sizeof(t_array*) * (n_of_parts + 1));
	part_size = (a->size + n_of_parts - 1) / n_of_parts;
	i = 0;
	while (i < n_of_parts - 1)
	{
		array_array[i] = sort_make_sub_array(a, part_size * i,
														part_size * (i + 1));
		i++;
	}
	array_array[i] = sort_make_sub_array(a, part_size * i, a->size);
	array_array[i + 1] = NULL;
	return (array_array);
}
