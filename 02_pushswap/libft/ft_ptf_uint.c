/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:44:59 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/20 20:44:58 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_unumsize(unsigned int n)
{
	size_t	size;

	if (n == 0)
		return (1);
	size = 0;
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

void	ft_putunbr_fd(unsigned int n, int fd)
{
	if (n > 9)
		ft_putunbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

void	uint_left_format(size_t *size, t_flagdata *data, int len)
{
	int	tmp;

	tmp = len;
	if (data->preci > len)
		tmp = data->preci;
	if (data->min > tmp && data->minus == 0)
	{
		if (data->zero && data->preci == 0)
			*size += ft_printpad('0', data->min - tmp);
		else
			*size += ft_printpad(' ', data->min - tmp);
	}
	if (data->preci > 0 && data->preci > len)
		*size += ft_printpad('0', tmp - len);
}

void	uint_right_format(size_t *size, t_flagdata *data, int len)
{
	int	tmp;

	tmp = len;
	if (data->preci > len)
		tmp = data->preci;
	if (data->min > 0 && data->min > tmp)
		*size += ft_printpad(' ', data->min - tmp);
}

size_t	ft_ptf_uint(va_list args, t_flagdata *data)
{
	unsigned int	val;
	size_t			size;
	int				len;

	size = 0;
	val = va_arg(args, unsigned int);
	len = get_unumsize(val);
	if (data->preci == -1 && val == 0)
		len = 0;
	uint_left_format(&size, data, len);
	if ((data->preci >= 0 && val >= 0) || (data->preci == -1 && val > 0))
		ft_putunbr_fd(val, 1);
	size += len;
	if (data->minus)
		uint_right_format(&size, data, len);
	return (size);
}
