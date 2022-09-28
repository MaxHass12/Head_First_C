# 1. System Calls and your hotline to the OS

- C program relies on OS for pretty much everything. They make system calls if they want to talk to the hardware. System calls are function that live in the OS's kernel. For eg : when we use `printf()` to display something, C makes a system to call to make that happen.

- `system()` executed the command-line command passed as argument.

# 2. Then someone busted into the system

- By injecting some command-line code into the text, you can make the program run whatever code you like. Major security issue because code could be called from a web server.

# 3. Security's not the only problem

- What if the comments contain apostrophes ? That might break the quotes in the command.
- What if the PATH variable causes `system()` function to call the wrong program?
- What if the program we are calling needs to have a specific set of environment variables set up first?

- `system()` function is easy to use, but most of the time, you need something more structured ie calling a specific program with a set of commane-line arguments and maybe even some environment variables.

- System calls are functions that live inside the kernel of the OS. System calls are the functions that your program uses to talk to the Kernel. Kernel is the most important program on your computer and its in charge of 3 things.
  - Processes - No program can run on the system without the Kernel loading it into memory. Kernel creates processes and makes sure they get the resource that they need.
  - Memory - Kernel carefully rations the amount of memory each process can take.
  - Hardware - Kernel uses devide drivers to talk to the equipment that is plugged into the computer. Kernal talks to the hardware on our behalf.

# 4. The exec() function gives you more control

- When we call `system()` function, the OS has to interpret the command and decide which programs to run. Easy to get that wrong. Thus we want to remove ambiguity and tell the OS precisely which programs you want to run.

- The `exec()` function replaces the current process. We can say which command-line arguments or environment variables to use, and when the new program starts it will have exactly the same PID as the old one. Like a relay race.

# 5. There are many exec() functions

- There are 2 groups of `exec` function - the list function and array functions.

## The List Functions :

- The list function accepts command-line arguments as a list of params. The first param tells what program to run.
- Neeed to list the command-line arguments. The first argument is always the name of the program. Means, the first 2 params to a list version of `exec()` should always be the same string.
- `NULL` after the last command-line arg, we need it to denote there are no more arguments.
- Environment variables. After an exec function whose name ends with `e`, you can also pass an array of environment variables.

- `execl` : a list of arguments, ends with `NULL`
- `execlp` : a list of arguments + search on path, ends with `NULL`
- `execle` : a list of arguments + env variables, env variables follow the list of arguments

# 6. The array function :

- `execv` : an array or vector of arguments
- `execvp` : an array or vector of arguments + search for the program using the PATH variable

# 7. Passing Environment variables :

- Every process has a set of environment variables - we get them when we type `set` or `env` on the command line.

- If there is a problem calling the program, the existing process will continue running. Its useful because if we cant start the second process, we will be able to recover from the error.

# 8. Most System calls go wrong in the same way

- The program stops after the `exec()` call. Means, if anything runs after the `exec()` call then there must have been a problem.

- `errno` is a global variable that is defined in `errno.h`. Check that with `strerror` provided by `string.h`

- `system()` is easier than `exec()`. But because OS needs to interprent `system()` commands, they are a bit buggy.

- If the `exec` function is successful, we can not do anything afterwards in the program. Usually they return `-1` if there is problem.

## Summary and Extra

# 9. Read the news

# 10. exec() is the end of the line for your program

- The `exec()` functions replace the current function by running a new program. What happens to the original program ? Terminates immediately.

- What if you want to start another process and keep your process running.

- `fork()` makes a complete copy of the new current process. The brand-new copy will be running the same program on the same line number, only that it will have a different process identifier.

- The original process is called the parent process and the newly created copy is called the child process.

# 11. Running a child process with fork() + exec()

- The trick is to only call `exec()` function on the child process. That way the original parent process is free to continue doing something else.

- We use fork like this `pid_t pid = fork()`.

- `fork()` actually returns an integer value that is 0 for the child process and positive for the parent process. The code starts running in the child process.

- The great thing is that both processes will run at same time.

## Summary and Extra

- `system()` run programs in a separate process but gives less control over how exactly the program runs.

- OS actually uses same data for both the parent and child process. Employs 'copy-on-write' ie modifies creates copy of just about enough data for parent and child process.

- It is best to always use `pid_t` to store the result of `fork()`.

- System calls are functions that live in the kernel.
- The `exec()` functions give you more control than `system()`.
- The `exec()` functions replace the current process.
- The `fork()` function duplicates the current process.
- System calls usually return -1 if they fail.
- Failed system calls set the `errno` variable to the error number.

# 12. Your C Toolbox
