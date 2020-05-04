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

char *ft_ptype(va_list param, FlagStruct *flags)
{
	//(void)param;
	long ptr;
	//long test;
	//char *res;

	ptr = (long ) va_arg(param, long  );
	flags->type = 0;
	//printf("printf : %ld\n", (long)ptr);
	//test = (long) ptr;
	//printf("testptype : %ld", test);
	if (ptr == 0 && flags->prec_dot == 1)
	{
		return (ft_strdup("0x"));
	}
	else
		return (ft_strjoin("0x", ft_itoa_base(ptr, 16, "0123456789abcdef")));
	//res = ft_strjoin("0x", res);
  //return (res);
	//printf("res : 0x%s", res);
}
