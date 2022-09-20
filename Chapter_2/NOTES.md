# 1. C code includes pointers

- A pointer is just address of a piece of data in memory.

- We use pointer because :

  - Instead of passing around whole copy of data, you can just pass a pointer.
  - We might want 2 pieces of code to work on the same piece of data.

- In short pointers help us avoid copies and share data. They are a form of indirection (aka dereferencing) ie the ability to reference something using name, container instead of the value itself.

# 2. Digging Into memory

- Every time we declare a variable, the computer creates a space for it somewhere in memory.

- A variable declared inside a function is usually stored in stack. A function declared outside a function is stored in globals.

- Why are local variables and global variables stored differently? Because they are used differently. We only have 1 copy of global variable.

- We can get the address using the `&` operator. In formatted string, we use `%p` to print addresses or pointers.

# 3. Set Sail with Pointers

# 4. Set sail sou'east, Cap'n

- C is pass-by-value. When we call a function, C makes a copy of the value associated with the variable and sends it as argument.

- How do we write a program which updates a variable? By passing pointer or memory address of the variable.

# 5. Try Passing a pointer to the variable

- Passing pointers or addresses makes it possible to update the value of the variable or simply makes it possible to update the variable.

- This is one of the reason of using pointers.

- Side : You can think that when we invoke a function, we declare the variables in the scope of the function which are present in the parameter list. Nothin unusual as compared to other programming language.

# 6. Using Memory pointers

- There are 3 things we need to know in order to use pointers to read and write data :

  1. Get the address of the variable.

  - Once we have an address we might want to save it somewhere.
  - For that we need a pointer variable. Only difference to regular non-pointer variables is that they start with `*`.

  2. Read the Contents of an address.

  - We read the values from the pointer using `*`.
  - `*` and `&` operators are kind-of opposite (this opposite terminology is confusing). `&` returns the memory address of the variable, `*` provides access to the value at a memory location.
  - `*` is the dereference operator as pointer is said to be a reference.

  3. Change the Content of an address.

  - Using the dereference operator, this time to the left of the assignment

- If we declare a function to take pointer arguments, it is then able to modify the variable.

- We can think of having a variable name and deferencing operator as 2 ways of accessing a value at a given memory location. (We can not use increment or decrement operator with deferencing operator though).

- The computer structures the physical memory in a more complex way. For most programs, you don't need to worry about the details of how the machine arranges its memory.

- Sometimes coders call the pointer as reference. And hence `*` is called the dereference operator.

# 7. How do you pass a string to a function

# 8. Array variables are like pointers

- We declare arrays by we define the data type, specify the name of the array followed by square brackets ie `char msg[]` or `int nums[]`

- In that case, the array variable is just the pointer to the start of the array in the memory. ie the array variable stores the address of the first element of an array. ([?] The book says that its the pointer to the string itself, not the pointer to the first character of string)

- `sizeof()` operator returns the size of the data-type or the variable. It looks like a function, but it is an operator.

# 9. What the computer thinks when it runs

- Key point is that array variable can be used as a pointer. The array variable points to the first element in the array. If we declare an array argument to a function, it will be treated as a pointer.

- An operator is compiled to a sequence of instructions by the compiler. If the code calls a function, it has to jump to a separate piece of code. Compiler can determine the size of storage at compile time.

- On 64-bit systems, a memory address is stored as 64-bit or 8-byte numbers. Hence, 8-bytes for a pointer.

- A pointer is just a variable living in memory whose address can be found by using the `&` operator.

## But array variables aren't quite pointers

- If we use `sizeof()` operator on an array variable, we get the actual size of an array back. Whereas, if we use `sizeof()` on any other pointer, we get the size of the pointer.

- The address of an array is .. just the array. Say `s` is an array variable ie address of the start of the array. `&s` means what the address of array - it is just `s`.

- Array variables are not assignable. When we create a variable, machine allocates a distinct memory location to store it. If we create an array, computer will allocate space to store the array, but it wont allocate any memory to store the array variable. As array variables dont have allocated space, you can't point them at anything else.

- An array variable contains the address of the array and the size of the array. If we assign an array to a pointer, the pointer does not know anything about the size of the array. Usually happens when pass array variables as arguments to a function. In this case, the loss of information is called decay.

# 10. Why arrays really start at 0

- We read the ith element of an array either through`arr[i]` or equivalently `*(arr + i)`.

- This is because array variable is just a number, we can do pointer arithmetic to add values to a pointer value and find the next address.

- `puts` take a pointer, and outputs the strings from there till the end of the string.

# 11. Why pointers have types

- Different types take different amount of memory. A `char` type takes 1 byte of memory. While an `int` type takes 4 bytes of memory.

- If we have an `int` pointer and add `1` to it, the compiler will add `4` to the memory address to get to the next memory location.

- Hence, pointer types exist so that compiler knows how much to adjust pointer arithmetic.

- Weirdly : `nums[3] == *(nums + 3) == *(3 + nums) == 3[nums]`, if `nums` is an array variable.

## Brief Summary and Extra

- Array variables can be used as pointers, but array variable are not exactly the pointers. `sizeof` is different for array variables and pointers, array variables can not point to anything else and assigning an array variable to a pointer decays it.

- Array variables start at zero because of the pointer arithmetic.

- Pointer variables have types so that C can adjust pointer arithmetic.

# 12. Using pointers for data entry

- How does `scanf()` work ? Takes 2 argument, type of the variable and address of the variable. It expects the user to input and updates the variable according to the input.

- Any function which updates a variable, wants the address of the variable as argument.

- We can update the contents of multiple variable with `scanf()`

# 13. Be careful with scanf()

- `scanf` uses the same kind of formatting as `printf`. In case of strings, we can just use `%s` with `scanf`, but we should mention the length of the string as well.

- Why? If we forget to limit the length of the string that we read with `scanf()`, then user can enter far more data than the program has space to store. The extra data then gets written into memory that has not been properly allocated. We might get lucky and program runs but most likely we will get 'segmentation fault' ot the 'abort trap'.

# 14. fgets() is an alternative to scanf()

- Like `scanf()`, `fgets()` takes a `char *` or `char` pointer. Additionally, `fgets()` must be provided a maximum length (and `stdin`).

- Means that we can not accidentally forget to set a length when we call `fgets()` because the maximum size argument is required. Note that the `fgets()` buffer size includes the final `\0` character so we dont have to substract 1 from the array length.

- We can set the max length using `sizeof` operator. However, if we are passing array as argument then we need to manually set whatever size we want.

- The predecessor of `fgets()` is `gets()` which has no limits at all. We should not use it.

## scanf() versus fgets()

- `fgets()` has a mandatory limit, for `scanf()` the limit is optional.
- `scanf()` allows us to enter more than 1 data (or field), different kind of data and ability to specify what characters appear between fields. `fgets()` allows us to enter just 1 string.
- `scanf()` can not read string with spaces. As soon as it reaches empty space `scanf()` stops reading. `fgets()` can read the whole string everytime.

# 15. Anyone for three-card monte?

# 16. Oops..there's a memory problem

# 16. String literals can never be updated

- String literals are declared as `char *`. String literals can never be updated. They are immutable. Trying to mutate them would throw an error - different error in different system. `bus error` in my macbook.

- Rather, if we create an array from a string literal then we can modify them.

# 17. In memory: char cards[]="JQK";

- It all comes down to how C uses memory :

  - When the computer loads the program into memory, it puts all the constant value - like the string literals - into the constant memory block. This section of memory is read only.

  - It creates the variable (say 'cards') on the stack. The stack is the section of memory for local variables - ie variables inside functions.

  - The `cards` variable will contain the address of the string literal `"JQK"`.

  - When we attempt to change the string literal, the computer throws an error.

  - If we want to change the contents of a string, we would want to work on a copy of it in section of memory which is not read-only.

  - We can do it simply by initializing an array with a string literal. Now the variable is no longer a pointer to read-only string, but its an array.

  - In memory, computer still loads the string literal to constant section. It creates a new array in the stack and initializes it by copying the contents of the string.

  - Stack > Heap > Globals > Constants > Code in memory in order of the address. The last 2 are read only and are the lowest address.

  - As a best practise, never write code that sets a simple `char` pointer to a string literal value. Make sure to use the `const` keyword. This will throw a compile error, if we try to mutate the string.

  - When 2 pointers are alias for same memory address, change in the underlying value will be reflected by both the pointers.

  ## Brief Summary and Extra Stuff

  - If we see a `*` in a variable declaration, it means the variable will be a pointer.
  - String literals are stored in read-only memory.
  - If you need to modify a string, you need to make a copy of it in a new array.
  - You can declare a `char *` as `const char *` to throw a compile time error if modifying a string.

  - If we declare a variable as `char *` - we can assign it both to array or string literal.
  - String literals are stored in read-only memory because they are supposed to be constant.
  - String literals are read-only anyways. `const` just ensures compile time error if we want to modify string literal.
  - Different memory segments appear in the same order in all systems.
  - Array variable is not stored in memory. Array variable won't exist in the final executable. That's OK because array variable will never point anywhere else.
  - Declaration is a piece of code that declares that something exists ie a variable, function, etc exists.

# 18. Memory Memorizer

## Stack

- That section of memory is used for local variable storage. Variables gets added to the stack when the function is invoked, gets removed when you leave. It starts at the top of the memory and grows downwards.

## Heap

- This place is for dynamic memory. Pieces of data that gets created when the program is running and then hang along a long time.

## Globals

- Global variables lives outside all functions and is visible to all of them. We can update them freely.

## Constants

- Constants are also created when the program first runs, but they are stored in the read-only memory. For example - string literals. We never want to change them.

## Code

- This is the lowest memory address. This is the part of the memory where the actual assembled code gets loaded.

# 19. Your C ToolBox
