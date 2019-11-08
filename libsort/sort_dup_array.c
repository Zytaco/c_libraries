/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_dup_array.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 14:45:45 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/07 14:45:45 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libsort.h"

t_array	*sort_dup_array(t_array *original)
{
	return (sort_new_array(original->array, original->size));
}
