/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:01:03 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/23 17:34:26 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	ft_printf(const char *s, ...)
{
	va_list	args;
	char	*tmp;
	int		size;

	tmp = (char *)s;
	size = 0;
	va_start(args, s);
	while (*tmp)
	{
		while (*tmp && *tmp != '%')
		{
			ft_putchar_fd(*(tmp++), 1);
			size++;
		}
		if (*tmp == '%')
			tmp = ft_formating(tmp, args, &size);
	}
	va_end(args);
	return (size);
}
/* 
#include <stdio.h>

int	main(void){
	
	const char * y = NULL;
	char c = 'Q';

    int x = 123456;
	int *ptr = &x;
	unsigned int ui = 34567;
	
	printf ("<%c> is not justified.\n", c);
	ft_printf ("<%c> is not justified.\n", c);
	printf ("<%5c> is right-justified.\n", c);
	ft_printf ("<%5c> is right-justified.\n", c);
	printf ("<%-5c> The minus sign makes it left-justified.\n", c);
	ft_printf ("<%-5c> The minus sign makes it left-justified.\n", c);
	printf ("%d\n", printf ("<%c> is not justified.", c));
	ft_printf ("%d\n\n", ft_printf ("<%c> is not justified.", c));

    printf("The address is: %p, the value is %d\n", ptr, *ptr);
    ft_printf("The address is: %p, the value is %d\n", ptr, *ptr);
    printf("The address is: %18p, the value is %d\n", ptr, *ptr);
    ft_printf("The address is: %18p, the value is %d\n", ptr, *ptr);
    printf("The address is: %-18p, the value is %d\n", ptr, *ptr);
    ft_printf("The address is: %-18p, the value is %d\n\n", ptr, *ptr);

    printf ("'%s' is not justified.\n", y);
    ft_printf ("'%s' is not justified.\n", y);
    printf ("'%10s' is right-justified.\n", y);
    ft_printf ("'%10s' is right-justified.\n", y);
    printf ("'%-10s' is left-justified using a minus sign.\n", y);
    ft_printf ("'%-10s' is left-justified using a minus sign.\n", y);
    printf ("'%5s' - 5s\n", y);
    ft_printf ("'%5s' - 5s\n", y);
    printf ("'%9s' - 9s\n", y);
    ft_printf ("'%9s' - 9s\n", y);
    printf ("'%9.3s' - 9.3s \n", y);
    ft_printf ("'%9.3s' - 9.3s \n", y);
    printf ("'%5.9s' - 5.9s\n", y);
    ft_printf ("'%5.9s' - 5.9s\n", y);
    printf ("'%9.s' - 9.s \n", y);
    ft_printf ("'%9.s' - 9.s \n", y);
    printf ("'%5.s' - 5.s\n", y);
    ft_printf ("'%5.s' - 5.s\n", y);
    printf ("'%.s' - .\n", y);
    ft_printf ("'%.s' - .\n", y);
    printf ("<%8.15s> - 9.12s \n", y);
    ft_printf ("<%8.15s> - 9.12s \n\n", y);

    printf("%d\n",printf ("<% 9.13s> ", y));
    ft_printf("%d\n\n",ft_printf ("<% 9.13s> ", y));
    
    printf ("<%d> is not justified.\n", x);
    printf ("<%d> is not justified.\n", x);
    printf ("<%7i> is right-justified.\n", x);
    printf ("<%7i> is right-justified.\n", x);
    printf ("<%-7i> The minus sign makes it left-justified.\n", x);
    printf ("<%-7i> The minus sign makes it left-justified.\n", x);
	
    printf ("<% +9.3d> \n", x);
    ft_printf ("<% +9.3d> \n", x);
    printf ("<% 09.3d> \n", x);
    ft_printf ("<% 09.3d> \n", x);
    printf ("<% +9.7d> \n", x);
    ft_printf ("<% +9.7d> \n", x);
    printf ("<% +09.7d> \n", x);
    ft_printf ("<% +09.7d> \n", x);
    printf ("<% 09.5d> \n", x);
    ft_printf ("<% 09.5d> \n", x);
    printf ("<% 9.5d> \n", x);
    ft_printf ("<% 9.5d> \n", x);
    printf ("<%3.9d> \n", x);
    ft_printf ("<%3.9d> \n", x);
    printf ("<%03.9d> \n", x);
    ft_printf ("<%03.9d> \n", x);
    printf ("<% 03.9d> \n", x);
    ft_printf ("<% 03.9d> \n", x);
    printf ("<%9.10d> \n", x);
    ft_printf ("<%9.10d> \n", x);
    printf ("<% 9.10d> \n", x);
    ft_printf ("<% 9.10d> \n", x);
    printf ("<% -4.10d> \n", x);
    ft_printf ("<% -4.10d> \n", x);
    printf("%d\n",printf ("<% 9.10d> \n", x));
    ft_printf("%d\n\n",ft_printf ("<% 9.10d> \n", x));

    printf ("<%d> is not justified.\n", ui);
    ft_printf ("<%d> is not justified.\n", ui);
    printf ("<%9u> is right-justified.\n", ui);
    ft_printf ("<%9u> is right-justified.\n", ui);
    printf ("<%09u> is right-justified.\n", ui);
    ft_printf ("<%09u> is right-justified.\n", ui);
    printf ("<%-09u> The minus sign makes it left-justified.\n", ui); 
    ft_printf ("<%-09u> The minus sign makes it left-justified.\n", ui); 
    printf ("<% 09.3u> \n", ui);
    ft_printf ("<% 09.3u> \n", ui);
    printf ("<% 09.7u> \n", ui);
    ft_printf ("<% 09.7u> \n", ui);
    printf ("<%3.9u> \n", ui);
    ft_printf ("<%3.9u> \n", ui);
    printf ("<%03.9u> \n", ui);
    ft_printf ("<%03.9u> \n", ui);
    printf ("<% 03.9u> \n", ui);
    ft_printf ("<% 03.9u> \n", ui);
    printf ("<%9.10u> \n", ui);
    ft_printf ("<%9.10u> \n", ui);
    printf ("<% 9.10u> \n", ui);
    ft_printf ("<% 9.10u> \n", ui);
    printf ("<% -4.10u> \n", ui);
    ft_printf ("<% -4.10u> \n", ui);
    printf ("<% 4u> \n", ui);
    ft_printf ("<% 4u> \n", ui);
    printf ("<% 5u> \n", ui);
    ft_printf ("<% 5u> \n", ui);

    printf("%d\n",printf ("<% 9.10u> \n", ui));
    ft_printf("%d\n\n",ft_printf ("<% 9.10u> \n", ui));

    printf ("<%X> is not justified.\n", ui);
    ft_printf ("<%X> is not justified.\n", ui);
    printf ("<%09X> is right-justified.\n", ui);
    ft_printf ("<%09X> is right-justified.\n", ui);
    printf ("<%-09X> The minus sign makes it left-justified.\n", ui); 
    ft_printf ("<%-09X> The minus sign makes it left-justified.\n", ui); 
	
    printf ("<% 09.3X> \n", ui);
    ft_printf ("<% 09.3X> \n", ui);
    printf ("<% 09.7X> \n", ui);
    ft_printf ("<% 09.7X> \n", ui);
    printf ("<%3.9X> \n", ui);
    ft_printf ("<%3.9X> \n", ui);
    printf ("<%03.9X> \n", ui);
    ft_printf ("<%03.9X> \n", ui);
    printf ("<% 03.9X> \n", ui);
    ft_printf ("<% 03.9X> \n", ui);
    printf ("<%9.10X> \n", ui);
    ft_printf ("<%9.10X> \n", ui);
    printf ("<% 9.10X> \n", ui);
    ft_printf ("<% 9.10X> \n", ui);
    printf ("<% -4.10X> \n", ui);
    ft_printf ("<% -4.10X> \n", ui);
    printf ("<% 4X> \n", ui);
    ft_printf ("<% 4X> \n", ui);
    printf ("<% 5X> \n", ui);
    ft_printf ("<% 5X> \n", ui);
    printf ("<% 6X> \n", ui);
    ft_printf ("<% 6X> \n\n", ui);

    printf ("<%#X> is not justified.\n", ui);
    ft_printf ("<%#X> is not justified.\n", ui);
    printf ("<%#09X> is right-justified.\n", ui);
    printf ("<%#09X> is right-justified.\n", ui);
    printf ("<%#-09X> The minus sign makes it left-justified.\n", ui); 
    printf ("<%#-09X> The minus sign makes it left-justified.\n", ui); 
	
    printf ("<%# 09.3X> \n", ui);
    ft_printf ("<%# 09.3X> \n", ui);
    printf ("<%# 09.7X> \n", ui);
    ft_printf ("<%# 09.7X> \n", ui);
    printf ("<%#3.9X> \n", ui);
    ft_printf ("<%#3.9X> \n", ui);
    printf ("<%#03.9X> \n", ui);
    ft_printf ("<%#03.9X> \n", ui);
    printf ("<%# 03.9X> \n", ui);
    ft_printf ("<%# 03.9X> \n", ui);
    printf ("<%#9.10X> \n", ui);
    ft_printf ("<%#9.10X> \n", ui);
    printf ("<%# 9.10X> \n", ui);
    ft_printf ("<%# 9.10X> \n", ui);
    printf ("<%# -4.10X> \n", ui);
    ft_printf ("<%# -4.10X> \n", ui);
    printf ("<%# 4X> \n", ui);
    ft_printf ("<%# 4X> \n", ui);
    printf ("<%# 5X> \n", ui);
    ft_printf ("<%# 5X> \n", ui);
    printf ("<%# 6X> \n", ui);
    ft_printf ("<%# 6X> \n\n", ui);

    printf("%d\n",printf ("<%# 9.10X> \n", ui));
    ft_printf("%d\n",ft_printf ("<%# 9.10x> \n", ui));

	return (0);
} */
/* 
#include <stdio.h>

int	main(void){

    printf("<%0#32x>\n" ,938090424);
    ft_printf("<%0#32x>\n" ,938090424);
    return(0);
} */