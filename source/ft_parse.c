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
	flags->star_width = -1;
	flags->width = NULL;
	flags->prec = NULL;
	flags->type = NULL;
}

void printstruct(struct FlagStruct *flags)
{
	printf("\n--------------------------------------\n");
	printf("flags->flag : %d\n", flags->flag);
	printf("flags->zero_width : %d\n", flags->zero_width);
	printf("flags->star_width : %d\n", flags->star_width);
	printf("flags->width : %s\n", flags->width);
	printf("flags->prec : %s\n", flags->prec);
	printf("flags->type : %s\n", flags->type);
	printf("--------------------------------------\n");
}

void	ft_parse(const char *s, va_list param, int *count)
{
	FlagStruct flags;

	flag_init(&flags);
	while (*s)
	{
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
			s++;
		}
	}
}

int	ft_star_width(va_list param)
{
	int i;

	i = (int)va_arg(param, int);
	return i;
}

int		ft_flag_identifier(const char *s, va_list param, FlagStruct *flags,
int *count)
{
	int i;

	i = 0;
	if (s[i] == '-')
	{
		flags->flag = 1;
		i++;
	}
	if (s[i] == '0' && flags->flag == 0)
	{
		flags->zero_width = 1;
		i++;
	}
	if (s[i] == '*')
	{
		flags->star_width = ft_star_width(param);
		i++;
	}
	while((s[i] >= '0' && s[i] <= '9') && flags->star_width == -1)
	{
		flags->width = ft_append_char(flags->width, s[i]);
		i++;
	}
	if (s[i] == '.')
	{
		i++;
		while(s[i] >= '0' && s[i] <= '9')
		{
			flags->prec = ft_append_char(flags->prec, s[i]);
			i++;
		}
	}
	if ((flags->type = ft_type_identifier(s[i], param, count)) == NULL)
	{
		ft_putstr_fd("ERROR RETURN HERE!!!\n", 1);
		return (-1);
	}
	//printstruct(flags);
	else
	{
		printstruct(flags);
		return (i);
	}
	//printf("flags width : %s ", flags->width);
}
