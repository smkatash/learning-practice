/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:31:44 by ktashbae          #+#    #+#             */
/*   Updated: 2022/09/02 17:58:28 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

/* 
gets current durectory for commandline and caal readline to get the 
input. Linee is copies into input structure for parsing.
Basic history handling is enabled.
*/

int main(void)
{
	t_microshell	shell;
	char			*line;

	printf("\n_____________________micro  shell__________________________\n\n");
	while (1)
	{
		parent_signal();
		if (getcwd(shell.directory, sizeof(shell.directory)) != NULL)
			printf("%s_", shell.directory);
		else
			perror("Input reader failed\n");
		line = readline("microshell_$ ");
		if (strlen(line) != 0)
		{
			memcpy(shell.input, line, 500);
			parse_input(shell.input, &shell);
			add_history(shell.input);
			free(line);
		}
	}
	clear_history();
	write(1, "Exit...\n", 8);
	return (EXIT_SUCCESS);
}
