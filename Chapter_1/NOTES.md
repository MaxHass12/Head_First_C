# 1. C is a language for small, fast programs

- C is a relatively low level language. Creates code a lot closer to what machines really understand.

- Most OS, computer languages and software is written in C.

- The process of compiling a new `.c` files creates an executable. Compiler checks for error - once no errors found then compiles the source code into an executable.

# 2. But what does a complete C Program Looks Like

- C programs are written in a source file with a `.c` extension.

- C programs normally begins with a comment. `/* */`

- Next comes the include section. C is a very, very small language and it can do almost nothing without the use of external libraries. Need to tell the compiler which libraries to use by including the headers for the relevant file.
- [] Where does the libraries live?

- All C code runs inside a function. Most important is the `main` function.

  - The return type is usually `int`. If the program ran successfully then it returns `0`. Any other return value means an error.
  - In the function declaration the return type precedes the function name and paranthesis `()`.
  - The function body is enclosed by curly braces `{}`

- `printf` is used to display formatted input. It replaces format characters (those starting with `%`) with the value of the variables.

- `echo $?` gives the exit-status of most recently executed command.

# 3. How do you run your program

- C is a compiled language, not an interpreted language. That means computer will not interpret the code directly. Instead, we need to compile the human-readable source code into machine-readable machine code.

- One of the most popular C Compiler is the 'GNU Compiler Collection' or 'gcc'.

- `puts` appends a `\n` at the end.

- In a Unix-style operating systems, programs are run only if we specify the directory where they live or if their directory is listen in the PATH environment variable.

- C does not support strings out of the box. There are a number of C extension libraries which give us strings. `card_name` is just a variable name we use to refer to the list of characters entered at the command prompt.

  - strings are stored as array of characters which can be accessed by square brackets.
  - In a lot of languages, the computer keeps track of the size of an array. C gets to know the end of the array by the sentinel character or the null character `\0`.
  - Hence, while declaring the length of the array holding the string, the length is 1 more than the number of characters.

- The index are an offset. It measures how far the character is from the first character.
- Arrays are stored in consecutive bytes of memory. It quickly gets to that memory location that way.
- Null or Sentinel Character denotes the end of the array. C has no way to track the length of array.
- Single quotes are for individual characters, but double quotes are used for strings - called string literals. Only difference is that string literals are constants. Trying to update throws a bus error - means that program can't update that piece of code [] Need to check.

# 4. Two Types of Command

- Most of the commands in C are statements [?]

  - Simple statements are actions, they tell the system to do something.

  - Sometimes we group statements together to create block statements within curlhy braces.

- `if`, `else` are control statements which checks a condition before running the code. Most C Programmers skip `{}` if the block has only 1 line of code.

- `&&` checks of both conditons are true. `||` checks if either one of 2 conditions is true. `!` flips the truth value of a condition.

- In C, booleans can be represented by numbers. `0` is falsey, every other number is truthy.

- `&` and `|` will always evaluate both conditions, while `&&` and `||` short-circuits in their evaluation.
- `&` and `|` also acts as bitwise operators.

# 5. Here is the code so far

# 6. Putting the ol' switcheroo

- C can perform several logical tests with `switch` statement. Used when we have to check the value of the same variable again and again.

- Once a matching `case` is found, C runs all the code that follows it until it reaches the `break` statement or the end of the `switch` statement. We need to ensure that we have included `break` in the right places.

- We cant use `switch` to check a string of characters or any kind of array. The `switch` statement will only check a single value.

# 7. Sometimes once is not enough

- Loops are a special type of control statement. A control statement decides if a section of code will be run, but a loop statement decides how many times a piece of code will be run.

- `while` loop runs over and over as long as some-condition remains true.

- `do ... while` loop executes at least 1 time.

# 8. Loops Often follow the same structure ...

- Generally a 3 step procedure. Do something before the loop like set a counter, have a simple test condition on the loop and do something at the end of a loop - like update a counter.

- `for` loop does all this in 1 line. And hence, used a lot more.

# 9. You use break to breakout ...

- We can skip out of the loop by using `break` statement. Simplest and best way to end a loop. A `break` statement is used to break out of loops and also switch statement.

- `break` does not skips from the `if` conditionals.

- `continue` skips the current iteration and goes to the start of the loop ie goes to the loop condition.

## Extra

- If a function takes arguments, then in the function declarations parameters have to be declared with the type.

- `void` functions or functions declared with `void` type do not return anything useful.

- Almost everything in C has a return value, and not just function calls. Assignment returns the assigned value. `y = x = 4;` will assign both `y` and `x` to `4` since `x = 4` returns `4`.

- C is compiled to make the code fast. JS and Python are interpreted language, but use some sort of hidden compilation to improve their speed.

- An Infinite Loop might sometimes be necessary in network servers that performs one thing repeatedly.

# 10. Your C Tool Box
