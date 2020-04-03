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

static void flag_init(struct FlagStruct *flags)
{
	flags->flag = 0;
	flags->zero_width = 0;
	flags->width = -1;
	flags->prec = -1;
	flags->type = -1;
	flags->type_ret = NULL;
}

void printstruct(struct FlagStruct *flags)
{
	printf("\n--------------------------------------\n");
	printf("flags->flag : %d\n", flags->flag);
	printf("flags->zero_width : %d\n", flags->zero_width);
	printf("flags->width : %d\n", flags->width);
	printf("flags->prec : %d\n", flags->prec);
	printf("flags->type : %d\n", flags->type);
	printf("flags->type_ret : %s\n", flags->type_ret);
	printf("--------------------------------------\n");
}

void	ft_parse(const char *s, va_list param, int *count)
{
	FlagStruct flags;

	while (*s)
	{
		flag_init(&flags);
		if (*s != '%')
		{
			ft_putchar_fd(*s, 1);
			s++;
			*count = *count + 1;
		}
		else
		{
			s++;
			s += ft_flag_identifier(s, param, &flags, count);
			//ft_type_identifier(s, param, count);
			ft_join(&flags, count);
			s++;
		}
	}
	printstruct(&flags);
}
