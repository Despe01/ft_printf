/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurad <smurad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:44:19 by smurad            #+#    #+#             */
/*   Updated: 2020/03/05 00:06:54 by smurad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*width_init(int i, char c)
{
	char *res;

	res = NULL;
	if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	res[i] = '\0';
	while (i > 0)
	{
		i--;
		res[i] = c;
	}
	return (res);
}

char		*ft_joinwidth(t_flags *flags, char *s)
{
	int len;

	len = ftstrlen(s) + flags->czero;
	if (flags->width > len)
	{
		len = flags->width - len;
		if (flags->zero_width == 0 || flags->zero_width_disable == 1)
		{
			return (width_init(len, ' '));
		}
		else if (flags->zero_width == 1)
			return (width_init(len, '0'));
	}
	return (ft_strdup(""));
}

static void	flagzero(t_flags *flags, int *count, char *prec, char *width)
{
	char	*res;
	char	*tmp;

	res = NULL;
	tmp = NULL;
	if (width[0] == '0' && flags->type_ret[0] == '-')
	{
		tmp = ft_strjoin(width, prec + 1);
		res = ft_strjoin("-", tmp);
	}
	else
		res = ft_strjoin(width, prec);
	*count = *count + (int)ftstrlen(res) + flags->czero;
	if (flags->czero == 1)
	{
		ft_putstr_fd(width, 1);
		ft_putchar_fd(0, 1);
	}
	else
		ft_putstr_fd(res, 1);
	free(tmp);
	free(res);
}

void		ft_join(t_flags *flags, int *count)
{
	char *prec;
	char *width;
	char *res;

	prec = ft_joinprec(flags);
	width = ft_joinwidth(flags, prec);
	res = NULL;
	if (flags->flag == 1)
	{
		res = ft_strjoin(prec, width);
		*count = *count + (int)ftstrlen(res) + flags->czero;
		if (flags->czero == 1)
		{
			ft_putchar_fd(0, 1);
			ft_putstr_fd(width, 1);
		}
		else
			ft_putstr_fd(res, 1);
	}
	else
		flagzero(flags, count, prec, width);
	free(prec);
	free(width);
	free(res);
	free(flags->type_ret);
}
