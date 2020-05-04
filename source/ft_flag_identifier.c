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

int	ft_star_width(va_list param)
{
	int i;

	i = (int)va_arg(param, int);
	return i;
}

int ft_width(const char *s, va_list param, FlagStruct *flags)
{
  int i;
  int j;
  char *res;

  i = flags->flag + flags->zero_width;
  j = 0;
  res = NULL;
  if (s[i] == '*')
	{
		flags->width = ft_star_width(param);
		if (flags->width < 0)
		{
			flags->width = flags->width * -1;
			flags->flag = 1;
			//if (flags->zero_width == 0)
				flags->zero_width_disable = 1; // A CHECK !
		}
		return (1);
	}
  while(s[i + j] >= '0' && s[i + j] <= '9')
  {
    res = ft_append_char(res, s[i + j]);
    j++;
  }
  flags->width = ft_atoi(res);
  return (j);
}

static int	ft_star_prec(va_list param)
{
	int i;

	i = (int)va_arg(param, int);
	return i;
}

int ft_prec(const char *s, va_list param, FlagStruct *flags, int i)
{
  int j;
  char *res;

  j = 1;
  res = NULL;
	if (s[i + 1] == '*')
	{
		flags->prec = ft_star_prec(param);
		return (2);
	}
	else if (s[i + 1] == 'c' || s[i + 1] == 's' ||s[i + 1] == 'p' ||
	s[i + 1] == 'd' || s[i + 1] == 'i' || s[i + 1] == 'u' || s[i + 1] == 'x' ||
	s[i + 1] == 'X' || s[i + 1] == '%')
	{
		flags->prec_dot = 1;
		return (1);
	}
  while(s[i + j] >= '0' && s[i + j] <= '9')
  {
    res = ft_append_char(res, s[i + j]);
    j++;
  }
  flags->prec = ft_atoi(res);
  return (j);
}

int		ft_flag_identifier(const char *s, va_list param, FlagStruct *flags)
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
	if (s[i] == '*' || (s[i] >= '0' && s[i] <= '9'))
	{
		i += ft_width(s, param, flags);
	}
	if (s[i] == '.')
	{
		i += ft_prec(s, param, flags, i);
	}
	if ((flags->type_ret = ft_type_identifier(s[i], param, flags)) != NULL)
	{
		//printstruct(flags);
		return (i);
	}
	else
	{
		ft_putstr_fd("ERROR RETURN HERE!!!\n", 1);
		return (-1);
	}
}
