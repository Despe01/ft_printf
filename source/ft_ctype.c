/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurad <smurad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 04:37:45 by smurad            #+#    #+#             */
/*   Updated: 2021/02/28 04:38:58 by smurad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_ctype(va_list param, t_flags *flags)
{
	char	*str;
	int		c;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	c = (int)va_arg(param, int);
	if (c == 0)
		flags->czero = 1;
	str[0] = c;
	str[1] = '\0';
	flags->type = 0;
	return (str);
}
