/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_free_array.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 14:48:45 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/07 14:48:45 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libsort.h"

void	sort_free_array(t_array **trash)
{
	free((*trash)->array);
	(*trash)->array = NULL;
	free(*trash);
	*trash = NULL;
}
