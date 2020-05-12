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

char	*ft_stype(va_list param, t_flags *flags)
{
	char	*str;

	flags->type = 0;
	str = va_arg(param, char *);
	if (flags->prec_dot == 1)
		return (ft_strdup(""));
	if (str == NULL)
		return (ft_strdup("(null)"));
	else
		return (ft_strdup(str));
}
