/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:48:59 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/20 20:44:12 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	format_conditions(char **s, t_flagdata *data)
{
	while (**s && ft_ft_strchr("# +-0", **s))
	{
		if (**s == '#')
			data->hash = 1;
		if (**s == ' ')
			data->space = 1;
		if (**s == '+')
			data->plus = 1;
		if (**s == '-')
			data->minus = 1;
		if (**s == '0')
			data->zero = 1;
		(*s)++;
	}
}

void	format_paddings(char **s, t_flagdata *data)
{
	while ((**s && ft_ft_strchr(" .", **s)) || ft_isdigit(**s))
	{
		while (**s == ' ')
			(*s)++;
		if (**s == '0')
			data->zero = 1;
		if (ft_isdigit(**s))
			data->min = ft_atoi(*s);
		if (**s == '.')
		{
			data->preci = ft_atoi(*s + 1);
			if (ft_atoi(*s + 1) == 0)
				data->preci = -1;
		}
		(*s)++;
		while (ft_isdigit(**s))
			(*s)++;
	}
}

char	*format_flags(char *s, t_flagdata *data)
{
	ft_initflagdata(data);
	format_conditions(&s, data);
	format_paddings(&s, data);
	return (s);
}

char	*ft_formating(char *s, va_list args, int *size)
{
	t_flagdata	data;
	char		*str;

	str = format_flags(++s, &data);
	if (*str == 'c')
		*size += ft_ptf_char(args, &data);
	else if (*str == 's')
		*size += ft_ptf_str(args, &data);
	else if (*str == 'p')
		*size += ft_ptf_ptr(args, &data);
	else if (*str == 'd' || *str == 'i')
		*size += ft_ptf_int(args, &data);
	else if (*str == 'u')
		*size += ft_ptf_uint(args, &data);
	else if (*str == 'x' || *str == 'X')
		*size += ft_ptf_hex(args, &data, str);
	else if (*str == '%')
		*size += ft_ptf_percent(&data);
	return (++str);
}
