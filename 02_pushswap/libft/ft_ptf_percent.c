/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:18:16 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/20 20:44:55 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_ptf_percent(t_flagdata *data)
{
	char	c;
	size_t	size;

	size = 0;
	if (data->minus < 1)
		size += ft_printpad(' ', data->min - 1);
	c = '%';
	ft_putchar_fd(c, 1);
	size++;
	if (data->minus)
		size += ft_printpad(' ', data->min - 1);
	return (size);
}
