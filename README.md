# My micro shell

```bash
## Supported: cd, cat, pwd, echo, exit. Not all commands are supported.
# | [pipe] - Commands can be piped together(up to 10 ipes are supported)." 
$ ls -a | wc -c
$ ls | grep "value"

## & [background] - Asyncronous commands are handled.
$ ls -a & cat file && cat file2

## < > >> [redirections] - Basic redirection pairs are supported.
$ ls -la > fileOutput
$ ls >> file 
$ echo hi < file
```
