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

#include "ft_printf.h"
#include <stdio.h>

char		*ft_type_identifier(char s, va_list param, int *count)
{
	char *res;

	res = NULL;
	if (s == 's')
	{
		res = ft_stype(param, count);
		ft_putstr_fd(res, 1);
	}
	else if (s == 'p')
		ft_ptype(param);
	return (res);
}

int		ft_printf(const char *s, ...)
{
	int		count;
	va_list	param;

	count = 0;
	va_start(param, s);
	ft_parse(s, param, &count);
	va_end(param);
	return (count);
}
