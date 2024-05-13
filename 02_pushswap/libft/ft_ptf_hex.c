/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:43:07 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/20 20:44:50 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_x_hexlen(unsigned long n, t_flagdata *data)
{
	size_t	size;

	if (n == 0 && data->preci == -1)
		return (0);
	else if (n == 0 && data->preci >= 0)
		return (1);
	size = 0;
	while (n > 0)
	{
		n /= 16;
		size++;
	}
	return (size);
}

void	hex_left(size_t *size, t_flagdata *data, unsigned int val, char *flag)
{
	int		tmp;
	int		hash;

	tmp = get_x_hexlen(val, data);
	hash = 0;
	if (data->preci > (int)get_x_hexlen(val, data))
		tmp = data->preci;
	if (data->hash && val > 0)
		hash = 2;
	if (data->min > (tmp + hash) && data->minus == 0)
	{
		if (data->zero && data->preci == 0)
			*size += ft_printpad('0', data->min - tmp - hash);
		else
			*size += ft_printpad(' ', data->min - tmp - hash);
	}
	if (data->hash && val)
	{
		if (*flag == 'x')
			*size += ft_printstr("0x");
		else
			*size += ft_printstr("0X");
	}
	if (data->preci > 0 && data->preci > (int)get_x_hexlen(val, data))
		*size += ft_printpad('0', tmp - get_x_hexlen(val, data));
}

void	hex_right(size_t *size, t_flagdata *data, size_t len, unsigned int val)
{
	int	tmp;
	int	hash;

	tmp = len;
	hash = 0;
	if (data->preci > (int)len)
		tmp = data->preci;
	if (data->hash && val > 0)
		hash = 2;
	if (data->min > 0 && data->min > (tmp + hash))
		*size += ft_printpad(' ', data->min - tmp - hash);
}

size_t	ft_ptf_hex(va_list args, t_flagdata *data, char *flag)
{
	unsigned int	val;
	size_t			size;
	size_t			len;

	size = 0;
	val = va_arg(args, unsigned int);
	len = get_ptr_hexlen(val);
	if (data->preci == -1 && val == 0)
		len = 0;
	hex_left(&size, data, val, flag);
	if ((data->preci >= 0 && val >= 0) || (data->preci == -1 && val > 0))
	{
		if (*flag == 'x')
			size += ft_printhex((unsigned long)val, 0);
		else if (*flag == 'X')
			size += ft_printhex((unsigned long)val, 1);
	}
	if (data->minus)
		hex_right(&size, data, len, val);
	return (size);
}
