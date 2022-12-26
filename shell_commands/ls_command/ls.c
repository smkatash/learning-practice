/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:48:31 by ktashbae          #+#    #+#             */
/*   Updated: 2022/09/24 16:48:12 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

#define BUFFER_SIZE 20

// Helper functions
char	**get_string(char **arr, char *str, int ptr);
char	**command_ls(const char *folder, int ls_la, int ls_l);
void	print_arr(char **arr);
void	free_arr(char **arr);
void	find_star_matches(char **arr, char *argv);
void	get_input(char *argv, int *ls_la, int *ls_l);


// Main function
int	main(int argc, char **argv)
{
	int		ls_la = 0;
	int		ls_l = 0;
	char	**arr_dir;
	char	*input;

	if (argc == 2)
	{
		// gets a copy of string on the argument line and sets flags
		input = malloc(sizeof(char) * (strlen(argv[1]) + 1));
		input = strcpy(input, argv[1]);
		get_input(input, &ls_la, &ls_l);
	}
	// saves filenames in current directory according to flags
	arr_dir = command_ls(".", ls_la, ls_l);
	if (argc == 2 && !ls_la && !ls_l)
	{
		//if no flags, but wildcard '*' is detected, scans for matches and prints out filenames
		find_star_matches(arr_dir, input);
		free(input);
	}
	else
		// prints whole array without wildcard
		print_arr(arr_dir);
	// frees allocated array
	free_arr(arr_dir);
	//checks allocated memory leaks
	//system("leaks ls");
	return (0);
}

// scans the input for syntax of -l and -a and flags them
// if no flag found, prints an error message
void	get_input(char *argv, int *ls_la, int *ls_l)
{
	char	*ptr;

	if (argv[0] == '-')
	{
		ptr = (char *)(argv + 1);
		while (*ptr)
		{
			if (*ptr == 'a')
				*ls_la = 1;
			else if (*ptr == 'l')
				*ls_l = 1;
			else
			{
				perror("Not recognized command");
				exit(EXIT_FAILURE);
			}
			ptr++;
		}
	}
}

// allocates memory and copies tring into array of strings
// fienames are stored in the array of strings
char	**get_string(char **arr, char *str, int ptr)
{
	arr[ptr] = malloc(sizeof(char) * (strlen(str) + 1));
	arr[ptr] = strcpy(arr[ptr], str);
	return (arr);
}

// prints whole array
void	print_arr(char **arr)
{
	int	i = 0;

	while (arr[i])
		printf("%s ",arr[i++]);
}

// frees allocated memory
void	free_arr(char **arr)
{
	int	i = 0;

	while (arr[i])
		free(arr[i++]);
}

// searches the matching filenames in the directory and input argument with wildcard '*'
// prints out matching filenames from input before or after '*'
// if given '*' with no strings, prints a whole array of existing filenames
void	find_star_matches(char **arr, char *argv)
{
	char	*find;
	char	*match;
	int		matched;
	int		i = 0;
	int		len = 0;

	if (!argv || strcmp(argv,"*") == 0)
		return (print_arr(arr));
	find = strstr(argv, "*");
	// search matches through string after * and print matching filenames
	if (strlen(find) > 1)
	{
		find++;
		while (arr[i])
		{
			match = strstr(arr[i], find);
			if (match)
				printf("%s ", arr[i]);
			i++;
		}
	}
	// search matches through string before * and print matching filenames
	else
	{
		len = strlen(argv) - strlen(find);
		while (arr[i])
		{
			matched = strncmp(arr[i], argv, len);
			if (matched == 0)
				printf("%s ", arr[i]);
			i++;
		}
	}
}


// opens current directory, handles errors of directory,
// reads current directory into struct dirent, 
// in case -a is False ignores hidden files, else saves into the array of filenames
// in case -l is True, saves into the array of filenames including a new line.
// RETURN VALUE: array of filenames in the current directory
char **command_ls(const char *folder, int ls_la, int ls_l)
{
	struct dirent *curr_dir;
	char	**arr_files;
	int		i = 0;
	
	DIR *open_d = opendir(folder);
	arr_files = malloc(sizeof(char*) * BUFFER_SIZE);
	if (!open_d)
	{
		if (errno == ENOENT)
			perror("Directory doesn't exist.");
		else
			perror("Directory can not be opened.");
		exit(EXIT_FAILURE);
	}
	while ((curr_dir = readdir(open_d)) != NULL)
	{
		if (!ls_la && curr_dir->d_name[0] == '.')
			continue;
		arr_files = get_string(arr_files, curr_dir->d_name, i);
		if(ls_l)
			arr_files = get_string(arr_files, "\n", ++i);
		i++;
	}
	closedir(open_d);
	return (arr_files);
}