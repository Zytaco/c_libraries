/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_skipstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 14:56:07 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/18 14:56:08 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	in_skip(char c, char *skip)
{
	int i;

	if (!skip)
		return (1);
	i = 0;
	while (skip[i] && c != skip[i])
		i++;
	if (skip[i])
		return (1);
	return (0);
}

int			ft_skipstr(char *str, char *skip)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && in_skip(str[i], skip))
		i++;
	return (i);
}
