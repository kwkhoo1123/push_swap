/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:36:32 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/20 20:44:45 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_ptf_char(va_list args, t_flagdata *data)
{
	char	c;
	size_t	size;

	size = 0;
	if (data->minus < 1)
		size += ft_printpad(' ', data->min - 1);
	c = va_arg(args, int);
	ft_putchar_fd(c, 1);
	size++;
	if (data->minus)
		size += ft_printpad(' ', data->min - 1);
	return (size);
}
