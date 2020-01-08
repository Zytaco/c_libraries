/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 12:47:06 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/12/17 12:47:06 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../includes/libft.h"
# include <stdarg.h>

typedef enum	e_argcode
{
	arg_char = 0,
	arg_str = 1,
	arg_pointer = 2,
	arg_int = 3,
	arg_oct = 4,
	arg_uint = 5,
	arg_hexl = 6,
	arg_hexu = 7,
}				t_argcode;

typedef struct	s_flags
{
	char		hash;
	char		zero;
	char		minus;
	char		plus;
	char		space;
	char		smallest;
	char		small;
	char		big;
	char		biggest;
	char		float_biggest;
	char		width_f;
	char		prec_f;
	int			width;
	int			prec;
	int			*count;
	char		type;
}				t_flags;

/*
** get arg type
*/
char			*ft_printf_int(t_flags *flags, int base, char upper,
																va_list list);
char			*ft_printf_uint(t_flags *flags, int base, char upper,
																va_list list);
char			*ft_printf_exp(t_flags *flags, va_list list);
char			*ft_printf_float(t_flags *flags, va_list list);
char			*ft_printf_autoexp(t_flags *flags, va_list list);
char			*ft_printf_exactfloat(t_flags *flags, va_list list);
char			*ft_printf_char(t_flags *flags, va_list list);
char			*ft_printf_str(t_flags *flags, va_list list);
char			*ft_printf_pointer(t_flags *flags, va_list list);
char			*ft_printf_num(t_flags *flags, va_list list);
char			*ft_printf_perc(t_flags *flags, va_list list);

/*
** flags
*/
char			*ft_printf_hash(char *arg, t_flags flags);
char			*ft_printf_plus(char *arg, t_flags flags);
char			*ft_printf_space(char *arg, t_flags flags);
char			*ft_printf_prec(char *arg, t_flags flags);
char			*ft_printf_width(char *arg, int len, t_flags flags);

#endif