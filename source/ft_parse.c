/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurad <smurad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:44:19 by smurad            #+#    #+#             */
/*   Updated: 2020/03/05 00:06:54 by smurad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_parse(const char *s, va_list param, int *count)
{
	int i;

	i = 0;
	while (*s)
	{
		if (*s != '%')
		{
			ft_putchar_fd(*s, 1);
			s++;
			i++;
			*count = *count + 1;
		}
		else
		{
			*count = *count + ft_type_identifier(s, param);
			s += 2;
		}
	}
}
