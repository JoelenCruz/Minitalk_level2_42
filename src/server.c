/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:46:09 by jcruz-da          #+#    #+#             */
/*   Updated: 2023/02/11 12:46:17 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	sig_handle(int sig)
{
	static int	i;
	static char	cont;

	if (sig == SIGUSR1)
		cont = cont | (1 << i);
	i++;
	if (i == 8)
	{
		i = 0;
		write(1, &cont, 1);
		cont = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_handler = &sig_handle;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	ft_printf("The process ID is (PID) --> %d\n", pid);
	while (1)
		pause();
	return (0);
}
