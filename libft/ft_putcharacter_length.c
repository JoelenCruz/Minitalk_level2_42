/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharacter_length.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:04:12 by jcruz-da          #+#    #+#             */
/*   Updated: 2023/02/11 16:19:50 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//character
void	ft_putcharacter_length(char character, int *length)
{
	write(1, &character, 1);
	(*length)++;
}
