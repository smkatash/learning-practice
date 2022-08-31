/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:25:02 by ktashbae          #+#    #+#             */
/*   Updated: 2022/08/31 19:00:54 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "micro_shell.h"

int	get_cmd(char *buf, int nbuf)
{
	ft_printf(2, "microshell_$ ");
	memset(buf, 0, nbuf);
	fgets(buf, nbuf, stdin);
	if (buf[0] == 0)
		return (-1);
	return (0);
}

int	main(void)
{
	static char	buf[100];
	int			fd;

	while ((fd = open("console", O_RDWR)) >= 0)
	{
		if (fd >= 3)
		{
			close(fd);
			break ;
		}
	}
	while (get_cmd(buf, sizeof(buf)) >= 0)
	{
		if (buf[0] == 'c' && buf[1] == 'd' && buf[2] == ' ')
		{
			buf[strlen(buf) - 1] = 0;
			if (chdir(buf + 3) < 0)
				ft_printf(2, "cannot cd %s\n", buf + 3);
			continue ;
		}
		if (forker() == 0)
			run_cmd(parse_cmd(buf));
		wait(0);
	}
	exit(0);
}

void	panic(char	*s)
{
	ft_printf(2, "%s\n", s);
	exit(1);
}

int	forker(void)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		panic("forker");
	return (pid);
}

void	run_cmd(t_cmd *cmd)
{
	int			fd[2];
	t_sub_cmd	*s_cmd;
	t_exec_cmd	*e_cmd;
	t_list_cmd	*l_cmd;
	t_pipe_cmd	*p_cmd;
	t_redir_cmd	*r_cmd;

	if (cmd == 0)
		exit(1);
	switch(cmd->type)
	{
		default :
			panic("runcmd");
		case EXEC :
			e_cmd = (t_exec_cmd *)cmd;
			if (e_cmd->argv[0] == 0)
				exit(1);
			execve(e_cmd->argv[0], e_cmd->argv, environ);
			write(2, "exec\n", 6);
			break ;
		case REDIR :
			r_cmd = (t_redir_cmd *)cmd;
			close(r_cmd->fd);
			if (open(r_cmd->file, r_cmd->mode) < 0)
			{
				write(2, "redir\n", 7);
				exit(1);
			}
			run_cmd(r_cmd->cmd);
			break ;
		case LIST:
			l_cmd = (t_list_cmd*)cmd;
			if (forker() == 0)
				run_cmd(l_cmd->left);
			wait(0);
			run_cmd(l_cmd->right);
			break ;
		case PIPE :
			p_cmd = (t_pipe_cmd *)cmd;
			if (pipe(fd) < 0)
				panic("pipe failure");
			if (forker() == 0)
			{
				close(1);
				dup(fd[1]);
				close(fd[0]);
				close(fd[1]);
				run_cmd(p_cmd->left);
			}
			if (forker() == 0)
			{
				close(0);
				dup(fd[0]);
				close(fd[0]);
				close(fd[1]);
				run_cmd(p_cmd->right);
			}
			close(fd[0]);
			close(fd[1]);
			wait(0);
			wait(0);
			break;
		case SUB:
			s_cmd = (t_sub_cmd *)cmd;
			if (forker() == 0)
				run_cmd(s_cmd->cmd);
			break ;
	}
	exit(0);
}
