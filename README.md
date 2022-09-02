# My simple (micro)shell

In this repository, i re-implemented the simple version of a shell, the interactive user interface with an operating system. I tried to learn the layer of programming that understands and executes the commands from user inputs.

ft_strtok function is re-created that behaves similarly to the tokenizer of "cstring" header. And included basic handling of signals CTRL-C & CTRL\.

The basic structure of the implementation is following:

-------> readline (gets user input with history management)
-------> parser (tokenizes input into sequences of commands and operators and calls according execution path)
-------> execution (executes commands according to operators).


## Supported: cd, cat, pwd, echo, exit. Not all commands are supported. ##
## | [pipe] - Commands can be piped together(up to 10 pipes are supported)." ##
```bash
$ ls -a | wc -c
$ ls | grep "value"
```
## & [background] - Asyncronous commands are handled. ##
```bash
$ ls -a & cat file && cat file2
```

## < > >> [redirections] - Basic redirection pairs are supported. ##
```bash
$ ls -la > file
$ ls >> file 
$ echo hi < file
```
         
## Running microshell ##
```bash
# Clone this project
$ git clone https://github.com/smkatash/my_microshell
         
# Compile the program
$ make

# Run the project
$ ./microshell

```
