/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utype.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurad <smurad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 04:38:44 by smurad            #+#    #+#             */
/*   Updated: 2021/02/28 04:39:02 by smurad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_utype(va_list param, t_flags *flags)
{
	unsigned int i;

	i = (unsigned int)va_arg(param, unsigned int);
	flags->type = 1;
	if (i == 0 && flags->prec_dot == 1)
		return (ft_strdup(""));
	else
		return (ft_itoa_base(i, 10, "0123456789"));
}
