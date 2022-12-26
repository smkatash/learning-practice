/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 19:06:35 by ktashbae          #+#    #+#             */
/*   Updated: 2022/09/02 15:32:32 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

/*
Breaks string str into a series of tokens using the delimiter delim.
Returns a pointer to the first token found in the string.
Behaves like strtok()
*/
char	*ft_strtok(char *str, const char *delim)
{
	static char	*index;
	int			i;

	if (str != NULL)
		index = str;
	else
		str = index;
	if (*index == '\0')
		return (NULL);
	while (*index != '\0')
	{
		i = 0;
		while (delim[i] != '\0')
		{
			if (*index == delim[i])
			{
				if (index == str)
				{
					str++;
					index++;
				}
				else
				{
					*index = '\0';
					break ;
				}
			}
			i++;
		}
		if (*index == '\0')
		{
			index++;
			return (str);
		}
		index++;
	}
	return (str);
}

/*
removes space & newline from the end and start of the string
*/
void skip_whitespace(char *str)
{
	int	len;

	len = strlen(str);
	if (str[len - 1] == ' ' || str[len - 1] == '\n')
		str[len - 1] ='\0';
	if (str[0] == ' ' || str[0]=='\n')
		memmove(str, str + 1, len);
}

/*
tokenizes char* input using the delimiter c, and returns the array of strings in param
and the size of the array in pointer nr
*/
void tokenizer(char **buffer, int *ptr, char *input, const char *delim)
{
	char	*token;
	int		i;

	token = ft_strtok(input, delim);
	i = -1;
	while(token)
	{
		buffer[++i] = malloc(sizeof(token) + 1);
		strcpy(buffer[i],token);
		skip_whitespace(buffer[i]);
		token = ft_strtok(NULL, delim);
	}
	buffer[++i] = NULL;
	*ptr = i;
}

/*
checks for |, &, >>, <> operators and calls execution functions accordingly.
Executes [cd] and other commands in a separate function
*/

void	parse_input(char *input, t_microshell *shell)
{
	int	ptr;

	ptr = 0;
	if (strchr(input, '|'))
	{
		tokenizer(shell->buffer, &ptr, input, "|");
		execute_pipe(shell->buffer, ptr);
	}
	else if (strchr(input, '&'))
	{
		tokenizer(shell->buffer, &ptr, input,"&");
		execute_back(shell->buffer, ptr);
	}
	else if (strstr(input, ">>"))
	{
		tokenizer(shell->buffer, &ptr, input, ">>");
		if (ptr == 2)
			execute_redirect(shell->buffer, APPEND);
		else 
			perror("Wrong input in redirect: command >> file");
	}
	else if (strchr( input, '>'))
	{
			tokenizer(shell->buffer, &ptr, input, ">");
			if (ptr == 2)
				execute_redirect(shell->buffer, STD_OUT);
			else 
				perror("Wrong input in redirec: command > file");
	}
	else if (strchr(input,'<'))
	{
		tokenizer(shell->buffer, &ptr, input, "<");
		if (ptr == 2)
			execute_redirect(shell->buffer, STD_IN);
		else
			perror("Wrong input in redirec: command < file");
	}
	else
	{
		tokenizer(shell->args1, &ptr, input," ");
		if (strstr(shell->args1[0],"cd"))
			chdir(shell->args1[1]);
		else if (strstr(shell->args1[0],"exit"))
		{
			clear_history();
			write(1, "Exit...\n", 8);
			exit(EXIT_SUCCESS);
		}
		else 
			run_exec(shell->args1);
	}
}