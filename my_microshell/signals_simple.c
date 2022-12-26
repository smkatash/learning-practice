/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 12:11:47 by ktashbae          #+#    #+#             */
/*   Updated: 2022/09/02 15:40:36 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

void	call_process_exit(int signal)
{
	exit(128 + signal);
}

void	send_exit_status(int signal)
{
	if (signal == SIGQUIT)
	{
		write(1, "\nExit", 5);
		exit(signal);
	}
	write(1, "\n", 1);
}

/* handles Ctrl -C and Ctrl-\ in parent process */
void	parent_sigint(void)
{
	struct sigaction	sn;

	sn.sa_handler = &send_exit_status;
	sn.sa_flags = SA_RESTART;
	sigemptyset(&sn.sa_mask);
	sigaction(SIGINT, &sn, NULL);
}

void	parent_sigquit(void)
{
	struct sigaction	sn;

	sn.sa_handler = &send_exit_status;
	sn.sa_flags = SA_RESTART;
	sigemptyset(&sn.sa_mask);
	sigaction(SIGQUIT, &sn, NULL);
}

void	parent_signal(void)
{
	parent_sigint();
	parent_sigquit();
}

void	child_sigint(void)
{
	struct sigaction	sn;

	sn.sa_handler = &call_process_exit;
	sn.sa_flags = SA_RESTART;
	sigemptyset(&sn.sa_mask);
	sigaction(SIGINT, &sn, NULL);
}

void	child_sigquit(void)
{
	struct sigaction	sn;

	sn.sa_handler = SIG_DFL;
	sn.sa_flags = SA_RESTART;
	sigemptyset(&sn.sa_mask);
	sigaction(SIGQUIT, &sn, NULL);
}

/* handles Ctrl -C and Ctrl-\ in child process and quits
only child process returning to parent*/
void	child_signal(void)
{
	child_sigint();
	child_sigquit();
}