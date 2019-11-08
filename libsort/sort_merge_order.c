/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_merge_order.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 17:54:55 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/07 17:54:55 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libsort.h"

t_array		*sort_merge_sort(t_array *a, t_array *b)
{
	U_INT	pos_a;
	U_INT	pos_b;
	t_array	*new;

	new = sort_new_array(NULL, a->size + b->size);
	pos_a = 0;
	pos_b = 0;
	while (pos_a < a->size || pos_b < b->size)
	{
		if ((pos_a < a->size && pos_b >= b->size) ||
											a->array[pos_a] <= b->array[pos_b])
		{
			new->array[pos_a + pos_b] = a->array[pos_a];
			pos_a++;
		}
		else
		{
			new->array[pos_a + pos_b] = a->array[pos_b];
			pos_b++;
		}
	}
	sort_free_array(&a);
	sort_free_array(&b);
	return (new);
}
