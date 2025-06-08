/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:50:01 by skoudad           #+#    #+#             */
/*   Updated: 2025/06/05 20:58:00 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

volatile sig_atomic_t	g_received_signal = 0;

void	send_char(pid_t pid, unsigned char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!g_received_signal)
			pause();
		g_received_signal = 0;
		bit--;
	}
}

void	handle_ack(int code)
{
	if (code == SIGUSR1)
		g_received_signal = 1;
	else if (code == SIGUSR2)
	{
		ft_printf("Message successfully received by the server, exiting...\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	int					i;
	struct sigaction	sa;

	i = 0;
	if (argc != 3)
		return (write(2, "Usage : ./client <PID> <message>\n", 34), 1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (write(2, "Invalid PID\n", 13), 1);
	sa.sa_handler = handle_ack;
	if (sigemptyset(&sa.sa_mask) == -1)
		return (1);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (1);
	while (argv[2][i])
		send_char(pid, argv[2][i++]);
	send_char(pid, '\0');
	return (0);
}
