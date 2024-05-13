/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:43:09 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/07/18 19:13:14 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_flagdata
{
	int		hash;
	int		space;
	int		plus;
	int		minus;
	int		min;
	int		zero;
	int		preci;
}					t_flagdata;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *str, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t d_size);
size_t	ft_strlcat(char *dst, const char *src, size_t len);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
long	ft_atoi_long(const char *str);
int		ft_abs(float num);
char	*ft_strstr(char *str, char *to_find);
size_t	ft_power(int n, int p);

void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

char	*get_next_line(int fd);

int		ft_printf(const char *s, ...);

int		ft_ft_strchr(char const *s, char c);

void	ft_initflagdata(t_flagdata *data);
char	*ft_formating(char *s, va_list args, int *size);

size_t	ft_ptf_char(va_list args, t_flagdata *data);
size_t	ft_ptf_str(va_list args, t_flagdata *data);
size_t	ft_ptf_ptr(va_list args, t_flagdata *data);
size_t	ft_ptf_int(va_list args, t_flagdata *data);
size_t	ft_ptf_uint(va_list args, t_flagdata *data);
size_t	ft_ptf_hex(va_list args, t_flagdata *data, char *flag);
size_t	ft_ptf_percent(t_flagdata *data);

size_t	get_ptr_hexlen(unsigned long n);
size_t	putstr_l(char *str, size_t len);
size_t	ft_printpad(char c, int size);
size_t	ft_printstr(char *s);
size_t	ft_printhex(unsigned long n, unsigned char cap);
void	ft_putunbr_fd(unsigned int n, int fd);
char	*ft_replace(const char *s, const char *oldW, const char *newW);

#endif