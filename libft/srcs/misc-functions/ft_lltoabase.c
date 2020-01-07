/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lltoabase.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 09:47:22 by jheeresm      #+#    #+#                 */
/*   Updated: 2020/01/07 09:47:22 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_lltoabase(LL n, int base)
{
	if (n < 0)
		return (ft_strjoin("-", ft_ulltoabase((ULL)-n, base)));
	else
		return (ft_ulltoabase((ULL)n, base));
}
