/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell2.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:25:28 by ktashbae          #+#    #+#             */
/*   Updated: 2022/08/31 19:00:33 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICRO_SHELL_H
# define MICRO_SHELL_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

# define MAXARGS 10
# define EXEC 1
# define REDIR 2
# define PIPE 3
# define LIST 4
# define SUB 5

extern char **environ;

typedef struct s_cmd
{
	int				type;
}					t_cmd;

typedef struct s_exec_cmd
{
	int				type;
	char			*argv[MAXARGS];
	char			*eargv[MAXARGS];
}					t_exec_cmd;

typedef struct s_redir_cmd
{
	int				type;
	struct s_cmd	*cmd;
	char			*file;
	char			*end_file;
	int				mode;
	int				fd;
}					t_redir_cmd;

typedef struct s_pipe_cmd
{
	int				type;
	struct s_cmd	*left;
	struct s_cmd	*right;
}					t_pipe_cmd;

typedef struct s_list_cmd
{
	int				type;
	struct s_cmd	*left;
	struct s_cmd	*right;
}					t_list_cmd;

typedef struct s_sub_cmd
{
	int				type;
	struct s_cmd	*cmd;
}					t_sub_cmd;

void				ft_printf(int fd, char *fmt, ...);
t_cmd				*null_terminate(t_cmd *cmd);
t_cmd				*parse_exec(char **start, char *end_line);
t_cmd				*parse_redirect(t_cmd *cmd, \
						char **start, char *end_line);
t_cmd				*parse_block(char **start, char *end_line);
t_cmd				*parse_line(char **start, char *end_line);
t_cmd				*parse_pipe(char **start, char *end_line);
t_cmd				*parse_cmd(char *ptr);

int					peek(char **start, char *end_line, char *tokens);
int					get_token(char **start, char *end_line, \
						char **tok, char **end_tok);

t_cmd				*exec_cmd(void);
t_cmd				*pipe_cmd(t_cmd *left, t_cmd *right);
t_cmd				*redir_cmd(t_cmd *sub_cmd, char *file, char *end_file, int mode, int fd);
t_cmd				*sub_cmd(t_cmd *subcmd);
t_cmd				*list_cmd(t_cmd *left, t_cmd *right);
void				run_cmd(t_cmd *cmd);
pid_t				forker(void);
int					get_cmd(char *buf, int nbuf);
void				panic(char	*s);

#endif 