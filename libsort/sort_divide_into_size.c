/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_divide_into_size.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 13:53:55 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/07 13:53:56 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libsort.h"

t_array		**sort_divide_into_size(t_array *a, U_INT part_size)
{
	if (!a || part_size <= 0)
		return (NULL);
	return (sort_divide_into_parts(a, (a->size + part_size - 1) / part_size));
}
