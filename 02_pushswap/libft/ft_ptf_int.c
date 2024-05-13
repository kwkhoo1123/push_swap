/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:59:15 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/20 20:44:42 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_numsize(int n)
{
	int	size;

	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (10);
	size = 0;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = n * -1;
		}
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		ft_putchar_fd((n % 10) + '0', fd);
	}
}

void	int_left_format(size_t *size, t_flagdata *data, int len, int val)
{
	int	tmp;
	int	sign;

	tmp = len;
	sign = 0;
	if (data->preci > len)
		tmp = data->preci;
	if (data->space || data->plus || val < 0)
		sign = 1;
	if (data->min > (tmp + sign) && !data->minus && !data->zero)
		*size += ft_printpad(' ', data->min - (tmp + sign));
	else if (data->min > (tmp + sign) && (data->zero && data->preci != 0))
		*size += ft_printpad(' ', data->min - (tmp + sign));
	if (data->space && !data->plus && val >= 0)
		*size += putstr_l(" ", 1);
	else if (data->plus && val >= 0)
		*size += putstr_l("+", 1);
	else if (val < 0)
		*size += putstr_l("-", 1);
	if (data->preci > 0 && data->preci > len)
		*size += ft_printpad('0', tmp - len);
	else if (data->min > len + sign && data->zero && data->preci == 0)
		*size += ft_printpad('0', data->min - (tmp + sign));
}

void	int_right_format(size_t *size, t_flagdata *data, int len, int val)
{
	int	tmp;
	int	sign;

	tmp = len;
	sign = 0;
	if (data->preci > len)
		tmp = data->preci;
	if (data->space || data->plus || val < 0)
		sign += 1;
	if (data->min > 0 && data->min > (tmp + sign))
		*size += ft_printpad(' ', data->min - tmp - sign);
}

size_t	ft_ptf_int(va_list args, t_flagdata *data)
{
	int		val;
	size_t	size;
	int		len;

	size = 0;
	val = va_arg(args, int);
	len = get_numsize(val);
	if (data->preci == -1 && val == 0)
		len = 0;
	int_left_format(&size, data, len, val);
	if (len > 0)
	{
		if (val < 0)
			ft_putunbr_fd(-val, 1);
		else
			ft_putunbr_fd(val, 1);
	}
	size += len;
	if (data->minus)
		int_right_format(&size, data, len, val);
	return (size);
}
