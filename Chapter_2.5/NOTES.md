# 1. Desperately seeking

# 2. Create an array of arrays

- What if we want to create an array of strings? Because each string is itself an array.

- We do it by double square brackets. eg `char tracks[][80]`. This creates an array of array.

- We access the individual string by `tracks[i]`. We access the character within the string by `tracks[i][j]`

# 3. Find string containing search text

- The C Standard Library is a bunch of useful code that we get with the C compiler. That Library is broken up into several sections and each when has a header `.h` file.

- `stdio.h` lets us use standard input/output functions like `printf` and `scanf`.

- We include the string processing library through `string.h`.
  - `strchr()` : find the location of character inside a string
  - `strcmp()` : compares 2 strings.
  - `strstr()` : find the location of string inside string.
  - `strcpy()` : copy 1 string to another.
  - `strlen()` : find the length of the string
  - `strcat()` : concatenate 2 string

# 4. Using the strstr()

- `strstr(s1, s2)` return the memory location of `s2` if `s1` contains `s2`, returns `0` otherwise.

# 5. It's time for a code review

- `fgets()` appends `\n` to the input.

- We could have defined the list of tracks as `tracks[5][80]`, but the compiler could tell from the initialization that there are 5 items in the list.
- Why not `tracks[][]` ? The track names are all different length, so we need to tell the compiler to allocate enough space for even the largest. [?] What if they were same.
- The program always run the `main()` function first. We could put the function in different order.

- We can create an array of arrays with `char strings[...][...]`
- The first set of brackets is used to access the outer array, the second set is used to access the intter arrays.

- While declaring a function, a parameter of `char *` can accept both string literals and array pointer as argument.

# 6. Array of arrays versus array of pointers

- We have seen how to use an array of arrays to store a list of strings.

- Another option is to use an array of pointers.

# 7. Your C Toolbox
