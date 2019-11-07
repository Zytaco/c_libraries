/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_shuffle_sort.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 17:14:33 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/07 17:14:36 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libsort.h"

void		sort_swap(t_array *arr, U_INT a, U_INT b)
{
	int temp;

	if (a < 0 || a >= arr->size || b < 0 || b >= arr->size)
		return ;
	temp = arr->array[a];
	arr->array[a] = arr->array[b];
	arr->array[b] = temp;
}

void		sort_shuffle_sort(t_array *a)
{
	U_INT start;
	U_INT end;
	U_INT i;

	start = 0;
	end = a->size - 1;
	while (start + 1 < end)
	{
		i = start;
		while (i + 1 <= end)
		{
			if (a->array[i] > a->array[i + 1])
				sort_swap(a, i, i + 1);
			i++;
		}
		end--;
		i = end;
		while (start <= i)
		{
			if (a->array[i] > a->array[i + 1])
				sort_swap(a, i, i + 1);
			i--;
		}
		start++;
	}
}
