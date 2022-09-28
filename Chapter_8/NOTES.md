# 1. Code you can take to the bank

- Suppose you have 2 source files having a function each and 2 headers corresponding to the source files.

# 2. Angle bracket are for standard headers

- Where are standard header directories
- `/usr/local/include` (used for header files for third-party libraries)
- `/usr/include` (used for operating system header files)

# 3. But what if you want to share code?

- Sometimes we want to write code that will be available to lots of programs, in different folders all over the computer
- We might want to share 2 sets of files
  - `.h` header files
  - `.o` object files

# 4. Sharing .h header files stored at different places

- Few ways
  - Store them in the standard directory.
  - Put the full pathname in your include statement.
  - You can tell the compiler where to find them.
    - You can do this by the `-I` option on gcc.

# 5. Share .o object

- You can put all the `.o` object files into some sort of shared directory and then use the full pathname to the object files.

- But in this case we will have to explicitly mention whole set of `.o` files.

- If we create an archive of object files, you can tell the compiler about a whole set of object files all at once.

# 6. An Archive contains .o files

- An archive `.a` is a file containing other files.

- `nm` command lists the names that are stored inside the archive.

- `nm` command will tell you the name of each `.o` file and then list the names that are available within the object file. If you see a T next to a name, means its the name of a function within object file.

- We can take a whole set of object files and turn them into a single archive file which we can use with `gcc`.

# 7. Create an archive with the `ar` command

- Make sure you always name your archives `lib<something>.a`

- Then you can put the `.a` file in standard directory or ins ome other directory

# 8. Finally, compile your program

- `gcc test_code.c -lhfsecurity -o test_code`

- Its important to name the library file `lib<something>.a`.

- If you archive somewhere else, in that case you will need to use the -L option to say which directories to search.

## Summary and Extra

- Headers in angle brackets (< >) are read from the standard directories.
- A library archive contains several object files
- We can create archive with `ar -rcs ..`
- Library archive names should begin `lib.` and end `.a`
- static linking - because once linked it cant be undone.

# 9. The Head First

# 10. Calculating calories

# 11. But things are a bit more complex...

# 12. Programs are made out of lots of pieces

- You can build programs using different pieces of object code. You have created `.o` files and `.a` archives, and you have linked them together into single executables.

- But once they are linked, you cant change them. They are static.

# 13. Dynamic linking happens at runtime

- The reason we can not change the different pieces of object code into executable is because they are all contained in a single file. They were statically linked together when the program was compiled.

- If program was not a single file, but rather a lot of separate files that only joined together when the program was run - you would avoid the problem.

# 14. Can you link at runtime

- Simple object files and archives do not have enough information in them to be linked together at runtime. For that, we will need dynamic library files.

- A dynamic library contains extra information that the OS will need to link the library to other things.

# 15. First, create

# 16. What you call

# 17. Your C Toolbox
