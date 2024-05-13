/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:30:09 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/20 20:44:48 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_ptf_ptr(va_list args, t_flagdata *data)
{
	void	*ptr;
	size_t	size;
	size_t	len;

	size = 0;
	ptr = va_arg(args, void *);
	len = get_ptr_hexlen((unsigned long)ptr) + 2;
	if (data->minus < 1)
		size += ft_printpad(' ', data->min - len);
	size += ft_printstr("0x");
	size += ft_printhex((unsigned long)ptr, 0);
	if (data->minus)
		size += ft_printpad(' ', data->min - len);
	return (size);
}
