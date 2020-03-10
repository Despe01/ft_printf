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

void	ft_ptype(va_list param)
{
	(void)param;
	//void *ptr;
	//ptr = (void *) va_arg(param, void * );
}

int		ft_type_identifier(const char *s, va_list param)
{
	if (s[1] == 's')
		return (ft_stype(param));
	else if (s[1] == 'p')
		ft_ptype(param);
	return (0);
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
