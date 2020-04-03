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

char		*ft_type_identifier(char s, va_list param, int *count,
  FlagStruct *flags)
{
	char *res;

	res = NULL;
  printf("%d\n", *count);
	if (s == 's')
	{
		res = ft_stype(param, flags);
	}
	else if (s == 'p')
		ft_ptype(param);
	return (res);
}
