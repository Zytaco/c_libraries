/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strins.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 16:34:20 by jheeresm      #+#    #+#                 */
/*   Updated: 2020/01/07 16:34:20 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strins(char **s, const char *ins, int i)
{
	char		*new;
	const int	ins_len = ft_strlen(ins);
	const int	s_len = ft_strlen(*s);

	if (!s)
		return (NULL);
	if (!ins || !*s)
		return (*s);
	new = ft_strnew(ins_len + s_len);
	ft_strncpy(new, *s, i);
	ft_strcpy(new + i, ins);
	ft_strcpy(new + i + ins_len, *s + i);
	new[ins_len + s_len] = '\0';
	free(*s);
	*s = NULL;
	return (*s);
}
