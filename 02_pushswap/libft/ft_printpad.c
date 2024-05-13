/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpad.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:06:07 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/20 20:44:40 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_printpad(char c, int size)
{
	int	i;

	if (size <= 0)
		return (0);
	i = 0;
	while (i++ < size)
		ft_putchar_fd(c, 1);
	return (size);
}
