/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:30:26 by jcruz-da          #+#    #+#             */
/*   Updated: 2022/11/02 15:30:06 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** SINOPSE: localizar caractere na string (Ultima ocorrencia!)
**
** DESCRIÇÃO:
** A função strrchr() localiza a ÚLTIMA ocorrência de c (convertida em
** char) na string apontada por s. O caractere nulo final é
** considerado como parte da string; portanto, se c é `\0', a função
** ções localizam a terminação `\0'.
*/
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	if (c == '\0')
		return ((char *)str + i);
	while (i >= 0)
	{
		if (str[i] == c)
			return ((char *)str + i);
		i--;
	}
	return (NULL);
}
/*
// C code to demonstrate the working of
// strrchr()

#include <stdio.h>
#include <string.h>

// Driver function
int main()
{

	// initializing variables
	char st[] = "GeeksforGeeks";
	char ch = '\0';
	char* val;

	// Use of strrchr()
	// returns "ks"
	val = strrchr(st, ch);

	printf("String after last %c is : %s \n", ch, val);

	char ch2 = 'm';

	// Use of strrchr()
	// returns null
	// test for null
	val = strrchr(st, ch2);

	printf("String after last %c is : %s ", ch2, val);

	return (0);
}
*/
