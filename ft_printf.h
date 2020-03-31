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

typedef struct FlagStruct FlagStruct;
struct FlagStruct
{
  int flag;
  int zero_width;
  int star_width;
  char *width;
  char *prec;
  char *type;
};

size_t	ftstrlen(const char *s);
char	*ft_append_char(char *str, char chr);
int		ft_printf(const char *s, ...);
void	ft_parse(const char *s, va_list param, int *count);
char		*ft_type_identifier(char s, va_list param, int *count);
int	ft_ptype(va_list param);
char *ft_stype(va_list param, int *count);
char	*ft_itoa_base(long n, int base, char *digits);
int		ft_flag_identifier(const char *s, va_list param, FlagStruct *flags,
int *count);



#endif
