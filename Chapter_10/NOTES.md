# 1. Redirecting input and output

- When you run programs from the command line, you can redirect the Standard Output to a file using `>` operator.

- Standard Output is 1 of 3 default data streams.

- When you redirect the output of a process, you change where the data is sent.

- How to make a process redirect to itself ?

# 2. A look inside a typical process

- Every process contains the program it is running, space for stack and heap data and also contains the descriptor table.
- The descriptor table contains account of where data stream are connect.
- The table has 1 column for each of the file descriptor numbers which is associated to a data stream. That data stream might be connected to the keyboard, screen, file pointer or a connection to the network.
- The first 3 slots are always the same. 0 for the Standard Input, 1 for the Standard Output and 2 is the Standard Error.
- For example, if your code opens a file for reading or writing another slot is filled in the descriptor table.
- When the process is created, the Standard Input is connected to the keyboard, the Standard Output and Error are connected to the screen.

# 3. Redirection just replaces data stream

- The Standard Input, Output and Error are always fixed in the same places in the descriptor table. But the data sreams they point to can change.

- Functions like `printf` looks at the descriptor table to see where descriptor 1 is pointing and then write the data to that stream.

- Till now we have done redirection from the command line using `<` and `>` operators. But the processes can do their own redirection by rewiring the descriptor table.

# 4. fileno() tells you the descriptor

- `FILE *my_file = fopen("file.txt", ""r)`

- The OS will open the `guitar.mp3` file and return a pointer to it. It will also skim through the descriptor table untill it finds an empty slot and register the new file there.

- `fileno()` is 1 of few system functions that does not return -1 if it fails.

- `dup2(a, b)` duplicates a data stream from one slot to another ie points descriptor b to descriptor a.

- `exit()` terminates the program immediately.

# 5. Sometimes you need to wait..

- Once the child process gets started, it is independent of its parent. If the execution of the child process takes time, then the effects are not visible.

- What if we want to first - complete the child process and then second - complete the parent process.

- `waitpid()` function will not return until the child process dies.

- Invoked as `waitpid(pid, pid_status, options)`
- `waitpid()` makes the process more reliable. It ensures that the subprocess had finished writing.

- Redirecting input and output, and making processes wait for each other are all simple form of interprocess communication.

## Summary and Extra

- `exit()` is a quick way of ending a program.
- All open files are recorded in the descriptor table.
- You can redirect input and output by changing the descriptor table.
- `fileno()` will find a descriptor in the table.
- `dup2()` can be used to change the descriptor table.
- `waitpid()` will wait for processes to finish.

- With `exit()` we dont need to structure your code to get back to `main()`. As soon as you call `exit()`, your program is daed.

- `exit()` does not return a value and guaranteed to never fail. The number we pass to `exit()` becomes its exit status.

- The standard input, output and error are always at 0, 1, 2 of the descriptor table.

- If we open a new file it is always added to the descriptor taible.

- `waitpid()` can be used to wait for any table.

# 6. Stay in rouch with your child

- Rather than waiting for a child process to send all of its data into a file and then reading the file afterwards, how to start a process running and read the data it generates in real time.

# 7. Connect your processes with pipes

- Pipes are used to make live connections

- Whenever we pipe commands together on the command line, you are actually connecting them together as parent and child.

- The command on the right becomes the parent process and forks the process mentioned on the left.

- What if we want to do it in C code.

# 8. Case study: Opening stories in a browser

- child sends data to the parent. We need a pipe that connect Standard Output of the child and the Standard Input of the parent.

- `pipe()` creates such a pipe - it creates 2 connected streams and adds them to the table.

- `int fd[2]` is that array which stores the file descriptors
- `pipe(fd)` is how we create the piper.
- `fd[0]` is the read-end (output-end) of the pipe.
- `fd[1]` is the write-end (input- end)of the pipe.

- After we have created the pipe, we need to connect it to the proper place.

# 9. In the child

- Since we write from the child, we need to connect the Standard Output of the Child to the input-end of the pipe.

- Before that, we need to close the output-end of the pipe by `close(fd[0])`

- Then `dup2(fd[1], 1)`

- This means that everything the child sends to the Standard Output will be written to the pipe.

# 10. In the parent

- Similarly, we read from the parent. Here we close the output end by `close(fd[0])`

- Then standard-input of the parent is connected the output end of the pipe. `dup2(fd[0], 0)`

# 11. Opening a web page in a browser

- Pipes are a great way of connecting processes together. Now we can not only run processes, execute their environment but also capture their output. ie now we can use and control any program from the command line.

- When the child process dies, the pipe is closed and the `fgets()` command receives an end-of-file which means the `fgets()` function returns 0. Pipes always work in 1 direction.

- Parent and child processes can communicate using pipes.
- The `pipe()` function creates a pipe and 2 descriptors.
- The descriptors are for the read and write end of the pipe.
- You can redirect Standard Input and Output to the pipe.

# 12. The death of a process

- `Ctrl-C` quits the program. What happens? The whole program stops. How?

- `fgets()` reads the data from keyboard, when the OS sees `ctrl-C` it sends an interrup signal to the program.

- A signal arrives, the process has to stop whatever its doing and go deal with the signal.

- A signal is just a single integer value. When the signal arrives, the process had to stop whatever its doing and deal with the signal.

- The process looks at a table of signal-mappings which maps each signal with a function called the signal-handler. The default signal-handler for the interrup signal calls the `exit()` function.

# 13. Catching signals and running the code

- Sometimes we want to run our own code if someone interrupts the program. For example : we might want to close things down and tidy up before exiting.

- `sigaction` tells the computer to run your own code when it sends a signal. `sigaction` is a struct that contains a pointer to the function.

- `sigaction` is a `struct` that contains a pointer to a function - acts as a wrapper for the signal-handler.

- All signal-handlers take signal arguments. You can reuse the same handler for several signals.

# 14. sigactions are registered with sigaction()

# 15. Rewriting the code

# 16. Use kill to send signals

- `kill` is normally used to kill signals, but infact `kill` just sends a signal to a process. By default, `kill` just sends a `SIGTERM` signal.

- `kill process_id` sends a `SIGTERM` signal to the program.
- `kill -INT process_id` sends a `SIGINT` signal to the program.
- `kill -KILL process_id` sends `SIGKILL`. This will always kill the program.

- `raise()` is used by program to send a signal to itself. Generally used inside signal-handlers which receives a signal for something minor and then choose to raise a more serious signal. Called signal escalation.

# 17. Sending your code a wake-up call

- The OS sends signals to process when something has happened which the process needs to know about. Might be that user tried to interrupt the process, ot process has tried to do something it should not have.

- Sometimes a process might actually want to generate its own signals. 1 example is the `SIGALARM` or the alarm signal which is created by process's interval timer. `alarm()` sends thr signal after the passed number of seconds.

- Gives the ability to do something after sometime.

- When a process receives a signal, it stops doing everything else. We do not want the timer to kill the program, hence we set the handler to do something else.

## Summary and Extra

- The OS talks to processes using signals.
- Programs are normally stopped using signals.
- When a process receives a signal, it runs a handler. For most error signals, the default handler stops the program.
- Handler can be replaced with the `signal()` function.
- We can send signals to yourself with `raise()`
- The interval timer sends the `SIGALARM` signals.
- The `alarm()` function sets the interval timer.
- There is 1 timer per process.
- `kill` sends signals to a process.
- `kill -KILL` will always kill a process.
