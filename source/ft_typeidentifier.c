/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurad <smurad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:44:02 by smurad            #+#    #+#             */
/*   Updated: 2020/03/05 00:10:48 by smurad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*ft_type_identifier(char s, va_list param,
  FlagStruct *flags)
{
	char *res;

	res = NULL;
	if (s == 's')
	{
		res = ft_stype(param, flags);
	}
	else if (s == 'p')
		res = ft_ptype(param, flags);
  else if (s == 'd')
    res = ft_dtype(param, flags);
  else if (s == 'c')
    res = ft_ctype(param, flags);
  else if (s == 'i')
    res = ft_dtype(param, flags);
  else if (s == 'u')
    res = ft_utype(param, flags);
  else if (s == 'x')
    res = ft_xtype(param, flags);
  else if (s == 'X')
    res = ft_uppercase_xtype(param, flags);
	return (res);
}
