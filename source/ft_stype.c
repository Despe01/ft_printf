/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stype.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurad <smurad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 00:05:15 by smurad            #+#    #+#             */
/*   Updated: 2020/03/05 00:09:18 by smurad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_stype(va_list param, int *count)
{
	char	*str;

	str = (char *)va_arg(param, const char *);
	*count = *count + ft_strlen(str);
	return (str);
}
