/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptype.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurad <smurad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 00:05:15 by smurad            #+#    #+#             */
/*   Updated: 2020/03/05 00:09:18 by smurad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_ptype(va_list param, t_flags *flags)
{
	long ptr;
	char *str;
	char *tmp;

	str = NULL;
	tmp = NULL;
	ptr = (long)va_arg(param, long);
	flags->type = 0;
	if (ptr == 0 && flags->prec_dot == 1)
	{
		return (ft_strdup("0x"));
	}
	else
	{
		tmp = ft_itoa_base(ptr, 16, "0123456789abcdef");
		str = ft_strjoin("0x", tmp);
		free(tmp);
		return (str);
	}
}
