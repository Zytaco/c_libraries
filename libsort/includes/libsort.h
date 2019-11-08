/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libsort.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 17:50:03 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/04 17:50:03 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSORT_H
# define LIBSORT_H
# include <stdlib.h>

# define U_INT unsigned int

typedef struct		s_array
{
	U_INT			size;
	int				*array;
}					t_array;

t_array				*sort_new_array(int *arr, U_INT len);
t_array				*sort_make_sub_array(t_array *a, U_INT start, U_INT end);
t_array				**sort_divide_into_parts(t_array *a, U_INT n_of_parts);
t_array				**sort_divide_into_size(t_array *a, U_INT part_size);
t_array				*sort_dup_array(t_array *original);
void				sort_free_array(t_array **trash);
void				sort_move(int *array, U_INT size, U_INT now, U_INT new);

#endif
