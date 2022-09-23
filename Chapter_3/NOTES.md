# 1. Small tools can solve big problems

- A small tool is a C program that does one task and does it well. Operating systems like Linux are mostly made up of hundreds and hundreds of small tools.

- If 1 part of program needs to convert data from one format to another, thats the perfect task for a small tool.

- The return value of `scanf` is the number of values it was able to read.

- Generally we want to read a lot of data, which usually comes from a file. Also we dont want to get the output on the system. That also needs to go in a file.

# 2. Here's how the program should work

- 1. Need to read the data from the file `gpsdata.csv`
- 2. Convert it to `output.json`
- 3. The mapping application reads the data from `output.json` and displays it on a map inside a web page.

# 3. But you're not using files

- But we are not reading and writing data from and to files.
- Instead, we are currently reading data from keyboard and writing it to display.

- Tools that read data line by line, process it, and write it out again are called filters.
- head displays first few lines of a file.
- tail displays line at the end of a file.
- sed (stream editor) let you do things ie search and replace text.

# 4. You can use redirection

- We use `scanf()` and `printf()` to read from the keyboard and write to the display. They dont interact directly, rather they use 'Standard Input' and 'Standard Output'.

- OS decides what the 'Standard Input' and 'Standard Output' is. The default is keyboard and display screen.
  `scanf()` and `printf()` just reads from Standard Input and writes to Standard Output.

- We can redirect Standard Input and Standard Output so that program can read and write data somewhere else, such as to and from files

# 5. You can redirect the Standard Input with <

- `<` tells the OS that the Standard Input of the program should be connected to some other file, not the keyboard.

# 6. ..and redirect the Standard Output with >

-

# 7. But there's a problem with some of the data...

- What if there is some bad data in the GPS data file ? We need to validate the data.

- In our gps program, our program saw that there was a problem with some of our data and it exited right away. Since we were redirecting the Standard Output to `output.json`, that meant we were also redirecting the error message.

- We can check the exit status of the last program by `echo $?`

# 8. Introducing the Standard Error

- Standard Output is the default way of outputting data from a program. But what if there is an error?

- Standatd Error is a second output which was created for sending error messages.

- Just like human beings have 2 ears and 1 mouth, Every process has 1 ear (the Standard Input) and 2 mouths (the Standard Output and the Standard Error)

# 9. By default, the Standard Error is sent to the display

- The `printf()` function sends data to the Standard Output.

- By default, the Standard Output goes to the display.

- We can redirect Standard Output to a file by using `>` on command line.

- `scanf()` reads data from the Standard Input

- Standard Input reads data from the keyboard by default.

- You can refirect the Standard Input to read from a file by using `<` on the command line.

- The Standard Error is reserved for outputting error messages. You can redirect Standard Error using `2>`. By default, it prints to the screen.

- If we redirect the Standard Output then the Standard Output will continue to send data to display.

# 10. fprintf() prints to a data stream

- `printf()` calls `fprintf()` internally.

- `fprinft()` allows to choose where we want to send text to. We call tell `fprintf()` to send text to `stdout` or `stderr` by passing the destination as the first argument.

- `stdin` is the Standard Input.
- We can't print to `stdin`
- We can read from the Standard Input using `fscanf()`
- `scanf(..)` is equivalent to `fscanf(stdin, ...)`
- `2>` redirects the standard error.

# 11. Let's update the code to use fprintf()

- The Standard Error was created with exactly this in mind, to separate error messages from usual output.
- `stdout` and `stderr` are just output streams.

## Extra

- For simple C programs, OS does not matter.
- OS loads programs into memories, ie turn them into processes. (A program being executed is a process). This involves allocating memory for the programs, connect them to their standard data streams.
- OS connects many small tools together.

# 12. Small tools are flexible

- If you write a program that does 1 thing really well, we will be able to use it in lot of contexts.

- Say, we want to display only data that falls between a given latitude and longitude.

# 13. Don't change the geo2json tool

- We dont want to change `geo2json` tool. We want small tools to do 1 job and do them well.

# 14. A different task needs a different tool

- We need to create a new tool that filters out data that is outside the bermuda tool.

- First, we will feed the data into bermuda tool. This will filter out data which is outside the given latitude and longitude.
- Second, we will feed the filtered data to `geo2json` to provide a json.

- How do we connect 2 tools together ?

  - The pipe symbol (`|`) connects Standard Output of one process to the Standard Input of another process.

  - `bermuda | geo2json` command will make the OS run both programs at same time. The output of `bermuda` will become them input of `geo2json`.

# 15. The bermuda tool

- When we connect 2 programs using the pipe operator, we can treat them as a single program.

## Extra

- Use of Standard Input or Standard Output is important as small tools use Standard Input and Standard Output because it becomes easier to connect tools using pipes.
- When 2 programs are connected using pipe, they both can run simultaneously.
- We can connect several programs together.
- `<` will send a file's content to the first process in the pipeline. `>` caputres the Standard Output from the last process in the pipeline. The paranthesis makes sure that data file is read by the first program in the pipeline.

# 16. But What if you want to output more than 1 file

- What if we want to read a set of data from a file and then split it into other files. With redirection, we can write to only 2 files at most ie 1 from the Standard Output and 1 for the Standard Error.

# 17. Roll your own data streams

- We can create our own data streams as the program runs. Each data stream is represented by a pointer to a file. We can create a new data stream using the `fopen()` function.

- `FILE *` creates a data stream to read and write from a file.

- `fopen()` takes 2 arguments : a filename and a mode. The mode can be `w` (to write), `r` (to read) and `a` (to append). Returns a pointer to the file.

- Once we have created a data stream, we can print to it or read from it using `fprintf()` or `fscanf()`.

- Once we have finished with a datastream, we need to close it. They are closed automatically, but its a good idea to close it.

## Extra

- One process can have 256 streams. Since they are limited, we must close them.
- FILE used to be defined using a macro. Hence, they are in uppercase.

But, what if user wanted to search for different words instead of "ufos", etc ?

# 18. There's more to main()

- If you want the user to give the ability to change the way program works. Since we have command-line program, we want to pass command-line arguments.

- Untill now we have defined the function `main` with no arguments.

- But we can pass command-line arguments to the program as array of strings if we define `main` with parameters like this `main(int argc, char *argv[])`. (Array of strings in C is array of character pointers to strings)

- We need some way to knowing how long the array is, hence `argc` ([?] Why not `sizeof(argv)`. Because `argv` is a pointer and passing it as argument leads to pointer decay)

- `argc` is the number of arguments passed. This includes the name of the program.

- `argv[0]` is the pointer to the name of the program, pointers to the proper arguments start at `argv[1]`

- If there is a problem opening a data stream, the `fopen()` function will return `0`. Ie we have to modify the code to open a file by :

```c
FILE *in;
if (!(in = fopen("dont_exist.txt", "r")))
{
  fprintf(stderr, "Cant open file\n");
  return 1;
}
```

# 19. Overheard at Head First Pizzeria

- Command-line options are little switches we add to commands with `-` before arguments.

# 20. Let the library do the work for you

- Many programs use command-line options, so there is a special library function we can use to make dealing with them a little easier.

- Each invocation of `getopt` function returns the next option it finds on the command line.

- To use it, we need to include `unistd.h` header.

- We use `getopt` inside a `while` conditional.
- Use as `getopt(argc, argv, option_string)`
  - Within option string, use `:` to refer to option which takes arguments
  - If the option passed is not present in the option string, C throws an error and also activates the `default` case.
- returns `EOF` if all the options are over
- within `getopt` we dispatch the return value of `getopt` to `switch` cases
- within `getopt`, `optarg` points to the option argument
- `optind` stores the number of strings read from the command line to get past the options.
  - If no options passed, then `optind` is 1 ie just the name of the program.
- After processing the arguments, `argv[0]` points to the first command-line argument instead of the program name.

- `puts` need a pointer to the string as argument.

## extra

- The order of the options does not matter. `getopt()` function handles all that. `-td` an `-dt` is same.
- If the program sees a value begining with `-` before it gets to main command line arguments, program will treat it as an option.
- To stop reading option use `--` in command line.

# 21. Your C Toolbox
