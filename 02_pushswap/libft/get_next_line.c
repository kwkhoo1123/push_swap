/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:07:03 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/21 16:16:46 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

char	*ft_get_line(char *txt)
{
	int		i;
	char	*str;

	i = 0;
	if (!txt[i])
		return (NULL);
	while (txt[i] && txt[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (txt[i] && txt[i] != '\n')
	{
		str[i] = txt[i];
		i++;
	}
	if (txt[i] == '\n')
	{
		str[i] = txt[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_txt_moveon(char *txt)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (txt[i] && txt[i] != '\n')
		i++;
	if (!txt[i])
	{
		free(txt);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(txt) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (txt[i])
		str[j++] = txt[i++];
	str[j] = '\0';
	free(txt);
	return (str);
}

char	*ft_read_txt(int fd, char *txt)
{
	char	*buff;
	int		rd;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd = 1;
	while (!ft_strchr(txt, '\n') && rd != 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd] = '\0';
		txt = ft_strjoin(txt, buff);
	}
	free(buff);
	return (txt);
}

char	*get_next_line(int fd)
{
	static char	*txt;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	txt = ft_read_txt(fd, txt);
	if (!txt)
		return (NULL);
	line = ft_get_line(txt);
	txt = ft_txt_moveon(txt);
	if (!txt || *txt == '\0')
	{
		free(txt);
		txt = NULL;
	}
	return (line);
}
/* 
int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

	if (argc != 2)
	{
		printf("No files to read \n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("file not readable\n");
		return (0);
	}
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	close(fd);
	return (0);
}
 */