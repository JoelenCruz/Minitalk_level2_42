/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:47:09 by jcruz-da          #+#    #+#             */
/*   Updated: 2023/02/11 13:02:48 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sendstring(int pid, char *str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (str[j] != '\0')
	{
		c = str[j];
		while (i < 8)
		{
			if ((c & 1) == 1)
				kill(pid, SIGUSR1);
			else if ((c & 1) == 0)
				kill(pid, SIGUSR2);
			usleep(200);
			c = c >> 1;
			i++;
		}
		j++;
		i = 0;
	}
}

void	send_null(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR2);
		usleep(200);
		i++;
	}
}

int	check_param(int argc)
{
	int	check;

	check = 0;
	if (argc != 3)
		ft_printf("Please check input: './client pid 'string''");
	else
		check = 1;
	return (check);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (check_param(argc) == 1)
	{
		pid = ft_atoi(argv[1]);
		sendstring(pid, argv[2]);
		sendstring(pid, "\n");
		send_null(pid);
	}
	return (0);
}
