/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:04:16 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/20 20:44:37 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_printstr(char *s)
{
	size_t	size;

	size = 0;
	if (!s)
		return (0);
	while (*s)
	{
		write(1, (s++), 1);
		size++;
	}
	return (size);
}
