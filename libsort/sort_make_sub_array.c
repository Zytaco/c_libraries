/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_sub_array.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 13:28:52 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/07 13:28:52 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libsort.h"

t_array	*sort_make_sub_array(t_array *a, U_INT start, U_INT end)
{
	U_INT	i;
	t_array	*new;

	if (start > end)
	{
		i = start;
		start = end;
		end = start;
	}
	else if (start == end)
		return (NULL);
	new = malloc(sizeof(t_array));
	new->array = malloc(sizeof(int) * (end - start));
	i = start;
	while (i < end)
	{
		new->array[i] = a->array[i];
		i++;
	}
	return (new);
}
