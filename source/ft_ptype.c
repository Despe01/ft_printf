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

int ft_ptype(va_list param)
{
	//(void)param;
	void *ptr;
	long test;
	char *res;

	ptr = (void *) va_arg(param, void * );
	//printf("printf : %ld\n", (long)ptr);
	test = (long) ptr;
	//printf("testptype : %ld", test);
	res = ft_itoa_base(test, 16, "0123456789abcdef");
  ft_putstr_fd("0x", 1);
  ft_putstr_fd(res, 1);
  return (ft_strlen(res) + 2);
	//printf("res : 0x%s", res);
}
