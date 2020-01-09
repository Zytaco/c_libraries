/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strprepp.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 15:22:46 by jheeresm      #+#    #+#                 */
/*   Updated: 2020/01/07 15:22:46 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strprepp(const char *pre, char **s)
{
	char		*new;
	const int	pre_len = ft_strlen(pre);
	const int	s_len = ft_strlen(*s);

	if (!s)
		return (NULL);
	if (!pre || !*s)
		return (*s);
	new = ft_strnew(pre_len + s_len);
	ft_strcpy(new, pre);
	ft_strcpy(new + pre_len, *s);
	new[pre_len + s_len] = '\0';
	free(*s);
	*s = new;
	return (new);
}
