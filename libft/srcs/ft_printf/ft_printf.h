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

# define FL_SIGN		((u_float.exp >> 1 & (short)1 == 1) ? 1 : 0)
# define EXP_ALL_ONE	(u_float.exp & ~(short)0)
# define EXP_ALL_ZERO	(u_float.exp & (short)0)
# define BIT_63			(u_float.mant_1 >> 31 & 1ULL)
# define BIT_62			(u_float.mant_1 >> 30 & 1ULL)
# define MANT_ALL_ZERO	(u_float.mant_1 >> 2 & 0ULL && u_float.mant_2 & 0UL)
# define MANT_ALL_ONE	(u_float.mant_1 >> 2 & ~0ULL && u_float.mant_2 & ~0UL)
union			u_float
{
	double		f;
	U short		exp : 2;
	ULL			mant_1 : 8;
	U long		mant_2 : 6;
};

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
	size_t		width;
	size_t		prec;
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
char			*ft_printf_float(t_flags *flags, va_list list);
char			*ft_printf_char(t_flags *flags, va_list list);
char			*ft_printf_str(t_flags *flags, va_list list);
char			*ft_printf_pointer(t_flags *flags, va_list list);
char			*ft_printf_num(t_flags *flags, va_list list);
char			*ft_printf_perc(t_flags *flags);

/*
** flags
*/
char			*ft_printf_hash(char *arg, t_flags flags);
char			*ft_printf_plus(char *arg, t_flags flags);
char			*ft_printf_space(char *arg, t_flags flags);
char			*ft_printf_prec(char *arg, t_flags flags);
char			*ft_printf_width(char *arg, size_t len, t_flags flags);

#endif
