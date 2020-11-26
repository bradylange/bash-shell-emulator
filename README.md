# bash-shell-emulator
Bash shell emulator.

Brady Lange

05/04/18

Op Sys Programming

Assignment 5

## `src/my_shell.c`
Program that emulates the shell. When the user enters bash commands they will
execute due to be forked. This is possible using the execvp function. The wait function
allows the process thats being forked to finish and then will prompt the user
for another command.

### Input:

`a.out my_shell$ ls`

### Output:

`a.out my_shell.c`

## Issues:
- `my_shell.c`: Doesn't compile on Windows, should run commands from any path in PATH. i.e. do not hardcode /bin directory. A process has environment variables.