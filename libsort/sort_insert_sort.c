/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_insert_sort.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 14:10:01 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/07 14:10:01 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libsort.h"

static void	maximize_array(t_array *a)
{
	int		*array;
	U_INT	size;
	U_INT	i;

	array = a->array;
	size = a->size;
	i = 0;
	while (i < size)
	{
		array[i] = INT32_MAX;
		i++;
	}
}

static int	pop_elem(t_array *a, U_INT pos)
{
	int		*array;
	U_INT	size;
	U_INT	i;
	int		x;

	array = a->array;
	size = a->size;
	x = a->array[pos];
	i = pos;
	while (i < size)
	{
		array[i] = array[i + 1];
		i++;
	}
	return (x);
}

static void	insert(int *array, int x)
{
	U_INT i;

	i = 0;
	while (x > array[i])
		i++;
	array[i] = x;
}

void		sort_insert_sort(t_array *a)
{
	U_INT	size;
	t_array	*cpy;

	if (a->size <= 1)
		return ;
	cpy = sort_dup_array(a);
	maximize_array(a);
	size = cpy->size;
	while (size > 0)
	{
		insert(a->array, pop_elem(cpy, 0));
		size--;
	}
	sort_free_array(&cpy);
}
