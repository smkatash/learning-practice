/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:59:56 by ktashbae          #+#    #+#             */
/*   Updated: 2022/09/02 15:30:18 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <stdio.h>
# include <string.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

# define STD_IN 0
# define STD_OUT 1
# define APPEND 2

typedef struct s_microshell
{
	char	*token;
	char	input[500];
	char	*buffer[1024];
	char	*args1[500];
	char	directory[1024];
}	t_microshell;

char	*ft_strtok(char *str, const char *delim);
void	skip_whitespace(char* str);
void	tokenizer(char** param,int *nr,char *buf,const char *c);
void	parse_input(char *input, t_microshell *shell);
void	tokenizer(char **buffer, int *ptr, char *input, const char *c);
void	execute_redirect(char **buffer, int mode);
void	run_exec(char **argv);
void	execute_pipe(char **buffer, int ptr);
void	execute_back(char **buffer, int ptr);
void	child_signal(void);
void	parent_signal(void);

#endif