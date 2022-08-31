/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:31:44 by ktashbae          #+#    #+#             */
/*   Updated: 2022/08/31 22:12:59 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

void print_params(char ** param)
{
	while(*param)
	{
		printf("param=%s..\n",*param++);
	}
}

int main(int argc, char **argv)
{
	t_microshell	shell;
	char			*line;

	printf("\n_____________________micro shell__________________________\n\n");
	while(1)
	{
		if (getcwd(shell.directory, sizeof(shell.directory)) != NULL)
			printf("%s_", shell.directory);
		else
			perror("Input reader failed\n");
		line = readline("microshell_$ ");
		memcpy(shell.input, line, 500);
		parse_input(shell.input, &shell);
		add_history(shell.input);
		free(line);
	}
	clear_history();
	write(1, "Exit...\n", 8);
	return (0);
}
