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

size_t		ftstrlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
			i++;
	}
	return (i);
}

static void	flag_init(t_flags *flags)
{
	flags->flag = 0;
	flags->zero_width = 0;
	flags->width = -1;
	flags->prec = -1;
	flags->type = -1;
	flags->czero = 0;
	flags->prec_dot = 0;
	flags->zero_width_disable = 0;
	flags->type_ret = NULL;
}

void		ft_parse(const char *s, va_list param, int *count)
{
	t_flags		flags;
	int			i;

	i = 0;
	flag_init(&flags);
	while (*s)
		if (*s != '%')
		{
			ft_putchar_fd(*s, 1);
			s++;
			*count = *count + 1;
		}
		else
		{
			i = ft_flag_identifier(s + 1, param, &flags);
			if (i != (-1))
			{
				s += i + 2;
				ft_join(&flags, count);
				flag_init(&flags);
			}
			else
				while (*s)
					s++;
		}
}
