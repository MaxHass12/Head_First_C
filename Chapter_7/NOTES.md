# 1. Looking for Mr Right..

- We can make our function do more things, without writing too much code.

- Our `find()` function loops through the given strings and outputs the matching string. What about creating functions for different kind of searches?

- Since our test is hardwired into the function, we will have to make almost identical copy of the functions. Since test can be for both presence and absence of strings, we can not just pass them as arguments.

# 2. Pass code to a function

- We need someway to pass code to a function which would do the test.

# 3. You need to tell find() the name of a function

- We want to make function first-class entities and pass them.

- How do we say that a parameter stores a name of a function. And if you have a function, how to you use it to call the function.

# 4. Every Function name is a pointer to the function..

- Name of a function is actually a pointer to the function in memory - stored at constant memory location.
- The address the function points to is the same as where it is.

# 5. ..but there's no function data type

- Like we can define other data types by prepending the variable with a `*` like `int *x`. `function *f` is illegal.

- C does not have a `function` data type because there is not just 1 type of function. We can vary a lot of thing - return type or params.

- To create function pointers we need complex notation.

# 6. How to creates function pointer

- return_type (pointer_name) (data type of params);
- then we assign that pointer the address of the function

- This is pretty complex. Because we have to tell C the return type and params type the function will take.

- `char**` is normally used to point to an array of strings.

- This is same as callback functions in JS.

- Function names are just pointers. You can call them like `(*foo)()`. Since they point to themselves `(&foo)()` is also correct. Without `*` and `&`, the code becomes a lot easier to read.

# 7. Get it sorted with the C Standard Library

- How could a sort function sort any type of data.

# 8. Use function pointers to set the order

- C Standard Library provides a `qort` function that accepts a comparator function - which we use to decide if 1 piece of data is the same as, less than or greater than another piece.

`qsort(void *array, size_t length, size_t item_size, int (*compar) (const void *, const void *));`

- the first argument is the array
- the second argument is the length of the array
- the third argument is the size of an element of the array
- the fourth argument is a pointer to the comparator function

  - `int (*compar) (const void *, const void *)`

- Think that the function is defined as `int compar(const void *x, const void *y);`
- Returns for comparison according to `x - y` logic.

- You can think that under the hood `qsort` sends pointer to 2 data elements to the `comparator` function. The `comparator` function accepts those pointers as `void` pointers. We need to convert these `void` pointers to the pointer of the correct type inside the `comparator` function.

- `qsort()` mutates the original array.

# 9. Automating the Dear John Letters

- In the automating letters array, we need to match the `type` of each `response` manually and then call a different function based on the response.

- Thats a lot of repetitive code.

# 10. Create an array of function pointers

- Trick is to create an array of function pointers that match the different response types.

- We are trying to have an array which contains a while bund of function names - something like `replies[] = {dump, second_chance, marriage};`

- The below complicated expression defines an array of function pointers :
- `void (*replies[])(response)`

- The function names are in exactly the same order as the types in enum. This is important because each symbol in an enum is basically a number of the order.

- The syntax of an array of function pointers may be quite difficult to understand.

## Summary and Extra

- Function names are function pointers and they stores the addresses of functions. ie if you have a function `shoot()` then `shoot` and `&shoot` are both pointers to that function
- You declare a new function pointer with `return-type (*var-name) (param-types)`
- If `fp` is a function pointer, you can call it with `fp(params, ..)` or `(*fp)(params, ...)`
- The C Standard Library has a sorting function called `qsort()`. The `qsort()` accepts a pointer to a comparator function that can test for ineqiality. The comparator function will be passed pointer to 2 items in the array being scored.
- If you have an array of data, you can associate functions with each data item using function pointer arrays.

- Function pointer array syntax is so complex, we need to mention what the return and parameter types are. We can use functioin pointers to associate functions with pieces of data.

# 11. Make your functions streeeeeeetchy

- `printf()` function can take variable number of arguments. How to create our own functions to take a variable number of arguments.

- A function that takes a variable number of parameters is called variadic function. The C Standard Library contains a set of macros that can help you create your own variadic function.

- How?

- Include the `stdarg.h` header.
- Declare a function with the first argument as an `int` and then ellipses ie `...`
- Create a `va_list` - it will be used to store the extra arguments that are passed to your function.
- Tell C the name of the last fixed argument. `va_start(ap, args)`
- Then read off the variable arguments, one at a time. The arguments are all stored in the `va_list` and you can read them with `va_arg`. `va_arg` takes 2 arguments : the `va_list` and the type of the next argument.
- End the list using `va_end`

- Then call the functions

- A MACRO is used to rewrite your code before it is complied. The macros might look like functions, but the tell the pre-processor how to generate lots of extra smart code inside your program, just before compiling it.

- We can not have a function with just variable arguments. We need to have at least one fixed argument.

## Summary

- Functions that accept a variable number of arguments are called variadic functions.
- To create variadic functions, you need to include `stdarg.h` header file.
- The variable arguments will be stored in `va_list`
- You can control the `va_list` using `va_start()`, `va_arg()` and `va_end()`.
- You will need at least 1 fixed parameter.
- We cant read more parameters than given and we need to know the data type of every parameter you need.

# 12. C toolbox
