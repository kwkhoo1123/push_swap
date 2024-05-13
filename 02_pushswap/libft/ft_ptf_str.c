/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:15:32 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/20 20:45:09 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	putstr_l(char *str, size_t len)
{
	size_t	size;

	size = 0;
	while (str[size] && size < len)
		ft_putchar_fd(str[size++], 1);
	return (size);
}

size_t	ft_ptf_str(va_list args, t_flagdata *data)
{
	char	*str;
	size_t	size;
	size_t	len;

	size = 0;
	len = 6;
	str = va_arg(args, char *);
	if (str)
		len = ft_strlen(str);
	if (data->preci > 0 && data->preci < (int)len)
		len = data->preci;
	else if (data->preci == -1)
		len = 0;
	if (data->minus < 1)
		size += ft_printpad(' ', data->min - len);
	if (str && len > 0)
		size += putstr_l(str, len);
	else if (!str && len > 0)
		size += putstr_l("(null)", len);
	if (data->minus && (data->min - len) > 0)
		size += ft_printpad(' ', data->min - len);
	return (size);
}
