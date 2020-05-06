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
	if (s == 's')
		return ft_stype(param, flags);
	else if (s == 'p')
		return ft_ptype(param, flags);
  else if (s == 'd')
    return ft_dtype(param, flags);
  else if (s == 'c')
    return ft_ctype(param, flags);
  else if (s == 'i')
    return ft_dtype(param, flags);
  else if (s == 'u')
    return ft_utype(param, flags);
  else if (s == 'x')
    return ft_xtype(param, flags);
  else if (s == 'X')
    return ft_uppercase_xtype(param, flags);
  else if (s == '%')
    return ft_strdup("%");
  /*if (res[0] == '0' && res[1] == '\0')
  {
    res[0] = '\0';
  }*/
  return (NULL);
}
