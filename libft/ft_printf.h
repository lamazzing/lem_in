/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:30:44 by lmazzi            #+#    #+#             */
/*   Updated: 2017/05/05 00:07:30 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <locale.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

typedef struct	s_beast
{
	char			*sent;
	char			*flag;
	char			*wid;
	char			*prec;
	char			*len;
	char			conv;
	int				pos;
	char			*out;
	int				ret;
	int				cret;
	int				zero;
	int				zeroc;
	int				null;
	unsigned char	c;
	wchar_t			wc;
	wchar_t			*wout;
}				t_beast;

typedef struct	s_flag
{
	int		pr;
	int		pl;
	int		min;
	int		sp;
	int		ze;
	int		ha;
}				t_flag;

int				ft_printf(char *format, ...);
char			*ft_itoa_base_unsigned(uintmax_t n, int base, t_beast *cr);
char			*ft_itoa_base_signed(intmax_t n, int base, t_beast *cr);
int				ft_cast_length_unsigned(uintmax_t *n, t_beast *cr);
int				ft_cast_length_signed(intmax_t *n, t_beast *cr);
char			*ft_wide(t_beast *cr);
void			ft_wides(t_beast *cr);
char			*flag(t_beast *cr);
void			ft_width(t_beast *cr, t_flag *fl);
void			ft_set_and_free(t_flag *fl, int a);
void			ft_crop(char *def, t_beast *cr);
#endif
