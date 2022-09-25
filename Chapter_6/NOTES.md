# 1. Do you need flexible storage

- Structs are still of fixed memory. Sometimes we need to link multiple struct.

- Suppose we define a struct template for islands. Now we create an array of islands. what if we want to create a new island and insert it somewhere in the list?

- But Arrays are fixed length. To store a flexible amount of data, we need something more extensible than an array. We need a linked list.

# 2. Linked List are like Chains of Data

- A linked list stores a piece of data, and a link to another piece of data.

- In a linked list, as long as you know where the list starts, you can travel along the list of links from 1 piece of data to the next, until you reach the end of the list.

# 3. Linked List allow inserts

- Inserting data into linked list is very quick. If we want to insert a value into the middle of an array, you would have to shuffle all pieces of data that follows it along by one.

- Linked Lists allow us to store a variable amount of data, and they make it simple to add more data.

- But, how do we create a linked list in C ?

# 4. Create a Recursive Structure

- Recursive structures contain pointers to other structures of the same type.

- Linked list contains a pointer to the next struct as one of the field.

- Remember that recursive structures need names. When we create a `struct` with `typedef` we usually skip providing a name and directly provide the alias. But, in a recursive structure we need a pointer to the same type, hence we need to give the `struct` a proper name.

# 5. Create islands in C

- We need to create islands and link them together

# 6. Inserting values into the list

- Inserting values into the linked list is easy. We just need to change a couple of links.

- But to read from a linked-list, we have to traverse through them. ie Linked-List are not appropriate for reading.

- a `struct` can not contain a whole recursive struct inside itself, it must contain a pointer. Why? C needs to know the exact amount of space a struct will occupy in memory. If we allow full recursive copies, then 1 piece of data will be a different size than other.

- So far we have created a separate variable for each item in the list. If we are reading from a file and we dont know how long the file is, how do we know how many variables we need.

- The local variables that we create are stored in the stack. Each `island` `struct` needed its own variable. That's fine if we know how much data we need to store at the compile time, but many times we dont know how much storage we need until runtime.

- C programs need some way to tell the OS that they need a little extra storage at the moment they need it - ie programs need dynamic storage.

# 7. Use the heap for dynamic storage

- Stack is the area of memory thats used for storing local variables. Each variable disappears when the function returns.

- Heap is the place where a program stores data that will need to be available longer term.

- First, we get our memory in the heap with `malloc()`. We pass how much memory we need and `malloc()` returns a pointer to the new heap space.

# 8. Give the memory back when you are done

- The good and bad news about heap memory is that we can keep hold of it for a really long time.

- For the local variables in the stack, we did not worry about returning memory as it happened automatically.

- The heap is different. Once we have asked for space on the heap, it will never be available for anything else untill you tell the C Standard Library that you are finished with it.

- Heap space is limited. If the program keeps on asking for more and more heap space, while not releasing it back, the program will start to develop memory leaks.

- A memory leak happends when a program asks for more and more memory without releasing the memory it no longer needs.

- To release the memory we call `free()` passing the pointer.

- When the program stops running, all the heap storage will be released automatically. But it is always good practise to explicitly call `free()` on every piece of dynamic memory you have created.

# 9. Ask for memory with malloc()..

- `malloc` takes 1 argument. The size of memory in bytes that we need. It returns a pointer to allocated memory. What kind of pointer it returns ? A general purpose `void*` pointer.

- Again - If we allocate memory with `malloc()` in 1 part of your program, you should always release it later with `free()` function.

# 10. Oh, no! It's the out-of-work actors

- The standard way of allocating memory from heap is a 2 step process :
  - declare a pointer variable of the relevant type
  - assign it to the return value of `malloc(sizeof())`

# 11. Let's fix code using strdup() function

- If we use a single array variable to take multiple strings as input, those strings are stored at same memory location.

- `strdup()` functionn take a pointer to the string as an argument, creates a copy of that string somewhere in the heap, and returns a pointer to the copy of the string in the heap.

- Under the hood `strdup()` function works out how long the string, then calls the `malloc()` function to allocate the correct number of characters on the heap. It then copies each of the characters to the new space of the heap.

- Since `strdup()` creates spaces on heap, we must always release that storage with `free()` function.

- String literals are stored in read-only memory for constants.

- If the `island struct` had a name array rather than character pointer, we would not use `strdup()`. `char` pointers wont limit the amount of space we need to set aside for strings. If we use `char` arrays, we will need to decide in advance exactly how long your strings might need to be.

- `fgets` returns `NULL` at the end of the file.

# 12. Free the memory when you are done

- Dynamic memory allocation lets you create memory you need at runtime. And the way to access dynamic heap memory is with `malloc()` and `free()`

## Summary and Extra

- Heap is called the heap because computer does not automatically organizes it. Some languagess do automatic GC when we no longer use the data. The OS always explicitly frees anything that we have created, but it is a good practise to use `free` and explicitly free daya.

- Other Data Structures can be Hash-Table, Doubly-Linked List, Binary Tree.

# 13. Exihibit A : the Source Code

# 14. An Overview of the SPIES system

# 15. Software forensics: using valgrind

- `valgrind` monitors the pieces of data that are allocated space on the heap by creating its own fake version of `malloc()`.

- When your program wants to allocate some heap memory, `valgrind` will intercept your calls to `malloc()` and `free()` and run its own versions of those functions. 

# 16. Using valgrind repeatedly

# 17. Look at the evidence

# 18. The fix on trial
