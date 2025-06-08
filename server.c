/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:50:11 by skoudad           #+#    #+#             */
/*   Updated: 2025/06/05 20:56:59 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"
#include <signal.h>

#define INIT_CAP 1024

char	*resize(char *msg, int *cap)
{
	char	*new;
	int		i;

	*cap *= 2;
	new = malloc(*cap);
	if (!new)
		return (NULL);
	i = 0;
	if (!msg)
	{
		new[0] = '\0';
		return (new);
	}
	while (msg[i])
	{
		new[i] = msg[i];
		i++;
	}
	new[i] = '\0';
	free(msg);
	return (new);
}

void	finalize_msg(char **msg, int *i, siginfo_t *info)
{
	(*msg)[*i] = '\0';
	ft_printf("%s\n", *msg);
	free(*msg);
	*msg = NULL;
	*i = 0;
	kill(info->si_pid, SIGUSR2);
}

void	store_char(unsigned char c, siginfo_t *info)
{
	static char	*msg = NULL;
	static int	i = 0;
	static int	cap = 0;

	if (!msg)
	{
		cap = INIT_CAP;
		msg = malloc(cap);
		if (msg)
			msg[0] = '\0';
	}
	if (!msg)
		return ;
	if (c == '\0')
		return (finalize_msg(&msg, &i, info));
	if (i >= cap - 1)
		msg = resize(msg, &cap);
	if (msg)
	{
		msg[i++] = c;
		msg[i] = '\0';
	}
}

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static int				bit_count;
	static unsigned char	current_char;

	(void)context;
	if (signum == SIGUSR2)
		current_char |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		store_char(current_char, info);
		bit_count = 0;
		current_char = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("server PID : %d\n", getpid());
	sa.sa_sigaction = &sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	signal(SIGINT, exit);
	while (1)
		pause();
}
