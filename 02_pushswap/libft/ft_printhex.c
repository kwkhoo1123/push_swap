/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:05:53 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/20 20:44:33 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_ptr_hexlen(unsigned long n)
{
	size_t	size;

	if (n == 0)
		return (1);
	size = 0;
	while (n > 0)
	{
		n /= 16;
		size++;
	}
	return (size);
}

void	ft_print_ptr(unsigned long ptr, int cap)
{
	if (ptr >= 16)
	{
		ft_print_ptr(ptr / 16, cap);
		ft_print_ptr(ptr % 16, cap);
	}
	else
	{
		if (cap)
			ft_putchar_fd("0123456789ABCDEF"[ptr], 1);
		else
			ft_putchar_fd("0123456789abcdef"[ptr], 1);
	}
}

size_t	ft_printhex(unsigned long n, unsigned char cap)
{
	ft_print_ptr(n, cap);
	return (get_ptr_hexlen(n));
}
