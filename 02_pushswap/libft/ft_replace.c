/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:17:40 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/07/12 19:46:36 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_rindex(const char *s, const char *oldW, int *cnt)
{
	int	i;
	int	old_len;

	i = 0;
	old_len = ft_strlen(oldW);
	while (s[i])
	{
		if (ft_strnstr(&s[i], oldW, ft_strlen(s)) == &s[i])
		{
			cnt++;
			i += old_len - 1;
		}
		i++;
	}
	return (i);
}

char	*ft_replace(const char *s, const char *oldW,
						const char *newW)
{
	char	*result;
	int		i;
	int		cnt;
	int		old_len;

	cnt = 0;
	old_len = ft_strlen(oldW);
	i = get_rindex(s, oldW, &cnt);
	result = (char *)malloc(i + cnt * (ft_strlen(newW) - old_len) + 1);
	i = 0;
	while (*s)
	{
		if (ft_strnstr(s, oldW, ft_strlen(s)) == s)
		{
			ft_strlcpy(&result[i], newW, ft_strlen(result));
			strcpy(&result[i], newW);
			i += ft_strlen(newW);
			s += old_len;
		}
		else
			result[i++] = *s++;
	}
	result[i] = '\0';
	return (result);
}
/* 
int main()
{
	char str[] = "sa\nsb\nsa\nsb\nsa\nsb\n";
	char c[] = "sa\nsb";
	char d[] = "ss";

	char* result = NULL;

	// oldW string
	printf("Old string: \n%s\n", str);

	result = ft_replace(str, c, d);
	printf("New String: \n%s\n", result);

	free(result);
	return (0);
} */