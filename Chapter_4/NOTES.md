# 1. Your Quick Guide to Data Types

- Floating Points : `float`, `double`
- Integers : `short`, `long`, `int`, `char` (`char` are stored using their character codes. They are just numbers)

- sizeof(char) : 1 bytes
- sizeof(short) : 2 bytes
- sizeof(int) : 4 bytes
- sizeof(long) : 8 bytes

- sizeof(float) : 4 bytes
- sizeof(double) : 8 bytes

# 2. Don't put something big to small

- If you assign the value in a bigger variable (say `int`), to a smaller variable (say `short`) - the compiler is not able to catch that.

- (Signed values in binary beginning with a 1 in the highest bit are treated as negative numbers)

# 3. Use casting to put floats into whole

- If we divide 2 `int` then we get a `int` with decimal part discarded.

- In that case, we do explicit type casting by using `(float)` before the division.

- We can put other keywords before data types.
  - `unsigned` : These will always be positive. Hence, an `unsigned int` will be able to solve twice values than `int`.
  - `long` : You can prefix a data type with the word `long` and make it longer.

## Extra

- Different OS have different sizes for data type to make the most of the hardware.
- If a computer is optimized best to work with 32-bit numbers, it makes sens that the basic data type ie the `int` is set at 32 bits.
- How are `floats` and `doubles` stored. Its complicated.

# 4. Oh no..it's the out-of-work actors..

# 5. Let's see what's happened to the code

# 6. Compiler's don't like surprises

- If the compiler sees a call to an undeclared function, the compiler assumes that the function will return an `int` type.

- Changing the order of functions can solve this problem.

- But

- Fixing the order of function is a pain. Most developers want to focus on real challenges than shuffling the functions around.

- In some cases, there is no correct order. If we have functions which are mutually recursive, one of them will always be called before it is defined.

# 7. Split the declaration from the definition

- We can avoid the compiler making assumptions by explicitly declaring all the functions before `main`.

- A function declaration is just a function signature - it records the name of the function, what kind of parameter it will accept and what type of data it will return.

- We put a while bunch of function declarations at the start of our code.

- Event beter, C allows us to take a whole set of declarations out of our code and put them in header file.

# 8. Creating your first header file

- We can create a `.h` file and move their our function declarations.

- Then we include `.h` file. We use `" "` instead of `< >` to wrap our header files as the file exists in the local directory.

- Separating function declaration to a header has huge advantage apart from making our code shorted. We will learn about it later.

- ( `#include` is a preprocessor instruction )

- since, `int` is what C assumes the functions to return, we need not necessarily have to declare `int` functions.
- Preprocessing is the first stage in converting the raw C code into a working execitable. Processing step reads the content of header into the mail file.
- `gcc` compiler knows where the standard headers are.

## Summary

- If the compiler finds a call to a hitherto undeclared function, it will assume that the function returns `nil`.
- Function declaration tell the compiler what your function will look like before you define them. The function declaration appear at the top of the source code.
- Function declaration are often put into header files.
- The compiler treas the 'included' code the same as code that is typed into the source file.

# 9. If you have common features ... it is good to share code

- What if we want to reuse common pieces of code between programs ? ie we have a set of functions which we want to share between programs.

# 10. You can split the code into separate files

- We can put the shared code into a separate source code `.c` file. If the compiler can somehow include the shared code when it is compiling the program, we can use multiple applications at once.

- Now, how does compiler create a single executable program from several source files.

# 11. Compilation behind the scenes

- 1. Preprocessing or fixing the source code. It needs to add in any extra header from the `#include` and exapnd or skip some sections of programs. Once done, the source code will be ready for actual compilation.

- 2. Compilation or translate into assembly. The code is created to assembly language symbols.

- 3. Assembly or generating the object code. Translate assembly language to object code (in binary).

- 4. Linking - put it all together. Once we have all separate pieces of object code, compiler will connect the code in 1 piece of object code that calls a function in another piece of object code. Linking will also make sure that program is able to call library code properly. Finally, the program will be written out into executable program file suing a format that is supported by OS.

Now, how to make executable from several separate source files.

# 12. The shared code need its own header

- You include the same header file, which contains the function declaration, in both the source codes.
- At the linking stage, the compiler will be able to connect functions.

- What if we want to share variable? We need to declare them in your header file and prefix them with keyword `extern`.

- To share code :
  - Put the common code into a separate source `.c` file.
  - Need to put the function declaration in a separate header `.h` file.
  - Include the header file in every C file that needs to use the shared code.
  - List all the C files needed in the compiler command.

# 13. It's not rocket science..or is it?

- By breaking program into separate source files means we can break down programs into smaller self-contained pieces of code. For big projects, this means that rather than having 1 huge source file we can have a lot of simpler files which are easier to understand, maintain and test.

- But, if we create programs which use more than a few files - the time it takes to compile the code starts to become iimportant. If we try out a single change, it is not possibel to see the result of that change quickly. It breaks the chain of thought.

# 14. Don't recompile every file

- If we have just made a change to 1 or 2 of source code files, its a waste to recompile every source. If the source code for a file has not changed, then the object code thats generated for that file will not change either.

- We need to save the object code crated. Now, if a single file does change we can recreate the object code for that 1 file and then pass the whole set of object files to the compiler so that they can be linked.

- Now, how do you tell gcc to save the object code in a file? And then, how do you get the compiler to link the object files together.

# 15. First, compile the source into object files

- `gcc -c *.c`. This will create object file for every source file, but wont link them together to create a full executable problem.

- `gcc *.o -o launch`. Instead of 1 or more `.c` files, we pass all the `.o` files. This links every thing together. This linking takes less time.

- The process takes 2 commands.

- Now if we change 1 files then we just make `.o` file from the modified `.c` file.

# 16. It's hard to keep track of the files

- If we are working on many files, its easy to forget to recompile some of them and then easy to forget link them to create the final program. Thus, we need to automate the process.

# 17. Automate your builds with the make tool

- `make` compares the timestamp of object file and source file. If object file is older than the source file, then the object file needs to be recreated.

- `make` tool checks the timestamps of the source file and the object file, and then only recompiles the file which needs to be recompiled.

- Every file that `make` compiles is called a target. A target is any file that is generated from some other file. For every target, make needs to be told 2 things :

  - The dependencies : which files the target is going to be generatd from.
  - The recipe : The set of instructions it needs to run to generate the file.

- The dependencies and the recipe form a rule. A rule tells `make` all it needs to know to create the target file.

# 18. How make works

- Say we want to compile `thruster.c` -> `thruster.o`

- `thruster.o` is called the targer file - one we want to generate.
- `thruster.c` is the dependency - one that would be required
- `gcc -c thruster.c` is the reciper.

- Ultimately we want to create our own `launch` program of which `thruster.c` is just 1 source file. `launch` executable is also a target file. The dependency files for `launch` are all `.o` object files. For this, the recipe is `gcc *.o -o launch`

- Once we tell `make` the details of all the dependencies and rules, `make` will work out the details.

# 19. Tell make about your code

- Then you put your target, dependencies separated by a colon on 1 line.
- Recipe on the next line. (Must begin by a TAB character - VSC takes care of it)


- Build tools like `ant` and `rake` are like `make`.
- Once you have more than an handful of files, `make` become really important.
- `make` can be used for almost any task that we perform on command line.

# 20. Liftoff!
