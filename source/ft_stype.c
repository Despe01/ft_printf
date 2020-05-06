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

char	*ft_stype(va_list param, FlagStruct *flags)
{
	char	*str;
	//int *test = count;

	//printf("%d\n", *test);
	flags->type = 0;
	if (flags->prec_dot == 1)
		return (ft_strdup(""));
	str = va_arg(param, char *);
	if (str == NULL)
		return (ft_strdup("(null)"));
	else
		return (ft_strdup(str));
	//free(str);
	//*count = *count + ftstrlen(str);

	//return (str);
}
