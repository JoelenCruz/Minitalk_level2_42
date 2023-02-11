/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:17:25 by jcruz-da          #+#    #+#             */
/*   Updated: 2022/12/07 20:55:59 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_printf_checker(char s, va_list *args, int *len, int *i)
{
	if (s == 's')
		ft_string(va_arg(*args, char *), len);
	else if (s == 'd' || s == 'i')
		ft_number(va_arg(*args, int), len);
	else if (s == 'u')
		ft_unsigned_int(va_arg(*args, unsigned int), len);
	else if (s == 'x')
		ft_hexadecimal(va_arg(*args, unsigned int), len, 'x');
	else if (s == 'X')
		ft_hexadecimal(va_arg(*args, unsigned int), len, 'X');
	else if (s == 'p')
		ft_pointer(va_arg(*args, size_t), len);
	else if (s == 'c')
		ft_putcharacter_length(va_arg(*args, int), len);
	else if (s == '%')
		ft_putcharacter_length('%', len);
	else
		(*i)--;
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			ft_printf_checker(string[i], &args, &length, &i);
			i++;
		}
		else
		{
			ft_putcharacter_length((char)string[i], &length);
			i++;
		}
	}
	va_end(args);
	return (length);
}
/*
#include <stdio.h>
int	main(void)
{
	char	string[] = "New String";
	int		returnlen;
	void *j = NULL
	
	returnlen = ft_printf("Simple Print\n");
	printf("Len Simple Print: %d\n", returnlen);
	returnlen = printf("Simple Print\n");
	printf("Len Simple Print: %d\n", returnlen);
	
	printf("------------------------\n");
	
	returnlen = ft_printf("Char: %c%c%c\n", 'A', 'B', 'C');
	printf("Len Char: %d\n", returnlen);
	returnlen = printf("Char: %c%c%c\n", 'A', 'B', 'C');
	printf("Len Char: %d\n", returnlen);
	
	printf("------------------------\n");
	
	returnlen = ft_printf("String: %s\n", string);
	printf("Len String: %d\n", returnlen);
	returnlen = printf("String: %s\n", string);
	printf("Len String: %d\n", returnlen);
	
	printf("------------------------\n");
	
	returnlen = ft_printf("Pointer: %p\n", j);
	printf("Len Pointer: %d\n", returnlen);
	returnlen = printf("Pointer: %p\n", j);
	printf("Len Pointer: %d\n", returnlen);
	
	printf("------------------------\n");	
	
	returnlen = ft_printf("Decimal: %d\n", 100);
	printf("Len Decimal: %d\n", returnlen);
	returnlen = printf("Decimal: %d\n", 100);
	printf("Len Decimal: %d\n", returnlen);
		
	printf("------------------------\n");	
	
	returnlen = ft_printf("Integer: %i\n", 3000);
	printf("Len Integer: %d\n", returnlen);
	returnlen = printf("Integer: %i\n", 3000);
	printf("Len Integer: %d\n", returnlen);
	
	printf("------------------------\n");	
	
	returnlen = ft_printf("Unsigned Int: %u\n", 4294967295);
	printf("Len Unsigned Int: %d\n", returnlen);
	returnlen = printf("Unsigned Int: %lu\n", 4294967295);
	printf("Len Unsigned Int: %d\n", returnlen);
	
	printf("------------------------\n");	
	
	returnlen = ft_printf("Hexadecimal X: %X\n", 0);
	printf("Len Hexadecimal: %d\n", returnlen);
	returnlen = printf("Hexadecimal X: %X\n", 0);
	printf("Len Hexadecimal: %d\n", returnlen);
	
	printf("------------------------\n");	
	
	returnlen = ft_printf("Hexadecimal x: %x\n", 2022);
	printf("Len hexadecimal: %d\n", returnlen);
	returnlen = printf("Hexadecimal x: %x\n", 2022);
	printf("Len hexadecimal: %d\n", returnlen);
	
	printf("------------------------\n");	
	returnlen = ft_printf("%%%%%%%%%%\n");
	printf("Len Percent: %d\n", returnlen);
	returnlen = printf("%%%%%%%%%%\n");
	printf("Len Percent: %d\n", returnlen);
	
	printf("------------------------\n");	
	returnlen = ft_printf("%s", "oi");
	printf("Len Percent: %d\n", returnlen);
	returnlen = printf("%s", "oi");
	printf("Len Percent: %d\n", returnlen);
}
*/
