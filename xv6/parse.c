/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:25:50 by ktashbae          #+#    #+#             */
/*   Updated: 2022/08/31 19:00:57 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "micro_shell.h"

char	whitespace[] = " \t\r\n\v";
char	operators[] = "<>|&;()";

int	get_token(char **start, char *end_line, char **tok, char **end_tok)
{
	char	*ptr;
	int		ret;

	ptr = *start;
	while (ptr < end_line && strchr(whitespace, *ptr))
		ptr++;
	if (tok)
		*tok = ptr;
	ret = *ptr;
	switch(*ptr)
	{
		case 0:
			break ;
		case '|':
		case ')':
		case '(':
		case ';':
		case '&':
		case '<':
			ptr++;
			break ;
		case '>':
			ptr++;
			if (*ptr == '>')
			{
				ret = '+';
				ptr++;
			}
			break ;
		default:
			ret = 'a';
			while (ptr < end_line && !strchr(whitespace, *ptr) && !strchr(operators, *ptr))
				ptr++;
			break ;
	}
	if (end_tok)
		*end_tok = ptr;
	while (ptr < end_line && strchr(whitespace, *ptr))
		ptr++;
	*start = ptr;
	return (ret);
}

/* Return True/False */
int	peek(char **start, char *end_line, char *tokens)
{
	char *ptr;

	ptr = *start;
	while (ptr < end_line && strchr(whitespace, *ptr))
		ptr++;
	*start = ptr;
	return (*ptr && strchr(tokens, *ptr));
}

t_cmd	*parse_cmd(char *ptr)
{
	t_cmd	*cmd;
	char	*end_line;

	end_line = ptr + strlen(ptr);
	cmd = parse_line(&ptr, end_line);
	peek(&ptr, end_line, "");
	if (ptr != end_line)
	{
		printf("leftover: %s\n", ptr);
		panic("syntax error");
	}
	null_terminate(cmd);
	return (cmd);
}

t_cmd	*parse_pipe(char **start, char *end_line)
{
	t_cmd	*cmd;

	cmd = parse_exec(start, end_line);
	if (peek(start, end_line, "|"))
	{
		get_token(start, end_line, 0, 0);
		cmd = pipe_cmd(cmd, parse_pipe(start, end_line));
	}
	return (cmd);
}

t_cmd	*parse_line(char **start, char *end_line)
{
	t_cmd	*cmd;

	cmd = parse_pipe(start, end_line);
	while (peek(start, end_line, "&"))
	{
		get_token(start, end_line, 0, 0);
		cmd = sub_cmd(cmd);
	}
	if (peek(start, end_line, ";"))
	{
		get_token(start, end_line, 0, 0);
		cmd = list_cmd(cmd, parse_line(start, end_line));
	}
	return (cmd);
}

t_cmd	*parse_block(char **start, char *end_line)
{
	t_cmd	*cmd;

	if (!peek(start, end_line, "("))
		panic("parse block failure");
	get_token(start, end_line, 0, 0);
	cmd = parse_line(start, end_line);
	if (!peek(start, end_line, ")"))
		panic("parenthesis not closed");
	get_token(start, end_line, 0, 0);
	cmd = parse_redirect(cmd, start, end_line);
	return (cmd);
}

t_cmd	*parse_redirect(t_cmd *cmd, char **start, char *end_line)
{
	int		token;
	char	*tok_start;
	char	*tok_end;

	while (peek(start, end_line, "<>"))
	{
		token = get_token(start, end_line, 0, 0);
		if (get_token(start, end_line, &tok_start, &tok_end) != 'a')
			panic("file missing");
		switch(token)
		{
			case '<':
				cmd = redir_cmd(cmd, tok_start, tok_end, O_RDONLY, 0);
				break ;
			case '>':
				cmd = redir_cmd(cmd, tok_start, tok_end, O_WRONLY | O_CREAT | O_TRUNC, 1);
				break ;
			case '+':
				cmd = redir_cmd(cmd, tok_start, tok_end, O_WRONLY | O_CREAT, 1);
				break ;
		}
	}
	return (cmd);
}

t_cmd	*parse_exec(char **start, char *end_line)
{
	char		*tok_start;
	char		*tok_end;
	int			token;
	int			num;
	t_exec_cmd	*cmd;
	t_cmd		*temp;

	if (peek(start, end_line, "("))
		return (parse_block(start, end_line));
	temp = exec_cmd();
	cmd = (t_exec_cmd *)temp;
	num = 0;
	temp = parse_redirect(temp, start, end_line);
	while (!peek(start, end_line, "&);|"))
	{
		if ((token = get_token(start, end_line, &tok_start, &tok_end)) == 0)
			break ;
		if (token != 'a')
			panic("execution syntax");
		cmd->argv[num] = tok_start;
		cmd->eargv[num] = tok_end;
		num++;
		if (num >= MAXARGS)
			panic("too many arguments");
		temp = parse_redirect(temp, start, end_line);
	}
	cmd->argv[num] = 0;
	cmd->eargv[num] = 0;
	return (temp);
}

t_cmd	*null_terminate(t_cmd *cmd)
{
	int			i;
	t_sub_cmd	*s_cmd;
	t_exec_cmd	*e_cmd;
	t_list_cmd	*l_cmd;
	t_pipe_cmd	*p_cmd;
	t_redir_cmd	*r_cmd;

	i = 0;
	if (cmd == 0)
		return (0);
	switch (cmd->type)
	{
		case EXEC:
		e_cmd = (t_exec_cmd *)cmd;
		while (*e_cmd->argv[i])
		{
			*e_cmd->argv[i] = 0;
			i++;
		}
			break ;
		case REDIR:
		r_cmd = (t_redir_cmd *)cmd;
		null_terminate(r_cmd->cmd);
		*r_cmd->end_file = 0;
		break ;
		case PIPE:
			p_cmd = (t_pipe_cmd *)cmd;
			null_terminate(p_cmd->left);
			null_terminate(p_cmd->right);
			break;
		case LIST:
			l_cmd = (t_list_cmd *)cmd;
			null_terminate(l_cmd->left);
			null_terminate(l_cmd->right);
		case SUB:
			s_cmd = (t_sub_cmd *)cmd;
			null_terminate(s_cmd->cmd);
			break;
	}
	return (cmd);
}
