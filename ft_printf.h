/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurad <smurad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:44:09 by smurad            #+#    #+#             */
/*   Updated: 2020/03/05 00:09:03 by smurad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ft_printf_h
# define FT_PRINTF_H

# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"
#include <stdio.h>


typedef struct s_flags
{
  int flag;
  int zero_width;
  //int star_width;
  int width;
  int prec;
  int type;
  char *type_ret;
  int czero;
  int prec_dot;
  int zero_width_disable;
}     t_flags;

size_t	ftstrlen(const char *s);
char	*ft_dtype(va_list param, t_flags *flags);
int ft_prec(const char *s, va_list param, t_flags *flags, int i);
char	*ft_ctype(va_list param, t_flags *flags);
int ft_width(const char *s, va_list param, t_flags *flags, int i);
void printstruct(t_flags *flags);
size_t	ftstrlen(const char *s);
char	*ft_append_char(char *str, char chr);
int		ft_printf(const char *s, ...);
void	ft_parse(const char *s, va_list param, int *count);
char		*ft_type_identifier(char s, va_list param,
  t_flags *flags);
char *ft_ptype(va_list param, t_flags *flags);
char *ft_stype(va_list param, t_flags *flags);
char	*ft_itoa_base(long n, int base, char *digits);
int		ft_flag_identifier(const char *s, va_list param, t_flags *flags);
void ft_join(t_flags *flags, int *count);
char *ft_joinprec(t_flags *flags);
char	*ft_utype(va_list param, t_flags *flags);
char *ft_xtype(va_list param, t_flags *flags);
char *ft_uppercase_xtype(va_list param, t_flags *flags);



#endif
