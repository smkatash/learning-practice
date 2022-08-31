/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:24:22 by ktashbae          #+#    #+#             */
/*   Updated: 2022/08/31 19:00:48 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "micro_shell.h"

t_cmd	*exec_cmd(void)
{
	t_exec_cmd	*cmd;

	cmd = malloc(sizeof(t_exec_cmd));
	memset(cmd, 0, sizeof(t_exec_cmd));
	cmd->type = EXEC;
	return ((t_cmd *)cmd);
}

t_cmd	*pipe_cmd(t_cmd *left, t_cmd *right)
{
	t_pipe_cmd	*cmd;

	cmd = malloc(sizeof(t_pipe_cmd));
	memset(cmd, 0, sizeof(t_pipe_cmd));
	cmd->type = PIPE;
	cmd->left = left;
	cmd->right = right;
	return ((t_cmd *)cmd);
}

t_cmd	*redir_cmd(t_cmd *sub_cmd, char *file, char *end_file, int mode, int fd)
{
	t_redir_cmd	*cmd;

	cmd = malloc(sizeof(t_redir_cmd));
	memset(cmd, 0, sizeof(t_redir_cmd));
	cmd->type = REDIR;
	cmd->cmd = sub_cmd;
	cmd->file = file;
	cmd->end_file = end_file;
	cmd->mode = mode;
	cmd->fd = fd;
	return ((t_cmd *)cmd);
}

t_cmd	*list_cmd(t_cmd *left, t_cmd *right)
{
	t_list_cmd	*cmd;

	cmd = malloc(sizeof(t_list_cmd));
	memset(cmd, 0, sizeof(t_list_cmd));
	cmd->type = LIST;
	cmd->left = left;
	cmd->right = right;
	return ((t_cmd *)cmd);
}

t_cmd	*sub_cmd(t_cmd *subcmd)
{
	t_sub_cmd	*cmd;

	cmd = malloc(sizeof(t_sub_cmd));
	memset(cmd, 0, sizeof(t_sub_cmd));
	cmd->type = SUB;
	cmd->cmd = subcmd;
	return ((t_cmd *)cmd);
}
