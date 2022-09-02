/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:19:44 by ktashbae          #+#    #+#             */
/*   Updated: 2022/09/02 12:11:45 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

/*
executes single command
*/
void run_exec(char **argv)
{
	if(fork() == 0)
	{
		child_signal();
		execvp(argv[0], argv);
		perror("S_execution: invalid input");
		exit(1);
	}
	else
	{
		parent_signal();
		wait(NULL);
	}
}

/*
executes a series of commands with max of 10 pipes
!!! modifiable amount of file descriptors!!!
*/
void execute_pipe(char **buffer, int ptr)
{
	int	i;
	int	ptr_update;
	char *argv[100];
	int	fd[10][2];

	if (ptr > 10) 
		return;
	i = 0;
	ptr_update = 0;
	while(i < ptr)
	{
		tokenizer(argv, &ptr_update, buffer[i], " ");
		if (i != ptr - 1)
		{
			if(pipe(fd[i]) < 0)
			{
				perror("pipe failure\n");
				return ;
			}
		}
		if (fork() == 0)
		{
			if (i != ptr - 1)
			{
				dup2(fd[i][1], 1);
				close(fd[i][0]);
				close(fd[i][1]);
			}
			if (i != 0)
			{
				dup2(fd[i - 1][0],0);
				close(fd[i - 1][1]);
				close(fd[i - 1][0]);
			}
			execvp(argv[0], argv);
			perror("P_execution: invalid input");
			exit(1);
		}
		if (i != 0)
		{
			close(fd[i - 1][0]);
			close(fd[i - 1][1]);
		}
		i++;
		wait(NULL);
	}
}

/*
loads and executes a an external command that needs file redirection(input, output or append)
*/
void execute_redirect(char **buffer, int mode)
{
	int		ptr_update;
	char	*argv[100];
	int		fd;

	skip_whitespace(buffer[1]);
	tokenizer(argv, &ptr_update, buffer[0], " ");
	if (fork()==0)
	{
		if (mode == STD_IN)
			fd = open(buffer[1],O_RDONLY);
		else if (mode == STD_OUT)
			fd = open(buffer[1],O_WRONLY);
		else if (mode == APPEND)
			fd = open(buffer[1],O_WRONLY | O_APPEND);
		else
			return;
		if (fd < 0)
		{
			perror("Microshell: cannot open file\n");
			free(argv);
			return;
		}
		if (mode == STD_IN)
			dup2(fd,0);
		else if (mode == STD_OUT)
			dup2(fd,1);
		else if (mode == APPEND)
			dup2(fd,1);
		else
			return ;
		execvp(argv[0], argv);
		perror("R_execution: invalid input");
		free(argv);
		exit(1);
	}
	wait(NULL);
}

/*
executes a series of commands in the background
*/
void execute_back(char **buffer, int ptr)
{
	int		i;
	int		ptr_update;
	char	*argv[100];

	i = 0;
	while (i < ptr)
	{
		tokenizer(argv, &ptr_update, buffer[i], " ");
		if (fork() == 0)
		{
			execvp(argv[0], argv);
			perror("B_execution: invalid input.");
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < ptr)
	{
		wait(NULL);
		i++;
	}
}

