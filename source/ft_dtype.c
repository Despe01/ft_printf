/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtype.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurad <smurad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 00:05:15 by smurad            #+#    #+#             */
/*   Updated: 2020/03/05 00:09:18 by smurad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_dtype(va_list param, t_flags *flags)
{
	int i;

	i = (int)va_arg(param, int);
	flags->type = 1;
	if (i == 0 && flags->prec_dot == 1)
		return (ft_strdup(""));
	else
		return (ft_itoa_base(i, 10, "0123456789"));
}
