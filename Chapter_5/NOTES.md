# 1. Sometimes you need to hand around a lot of data

- What if we have the following 4 data about a fish which we want to pass to many functions
- `const char *name, const char *species, int teeth, int age`
- `const char *` means we are going to pass string literals

- Here, we only have 1 fish but we are passing 4 pieces of data.

# 2. Cubicle Conversation

- This is a problem. What if we add more piece of information to the fish ? We will have to change our code in every function call.

- Arrays are fixed length data structure of the same data-type.

# 3. Create Your Own Structured Data with a struct

- If we need to bundle together into a single thing, then we can use a struct. The word `struct` is short for structured data type.
- `struct fish { const char *name; const char *species; int teeth; int age; }`

- How do we create pieces of data from it? Quite similar to creating a new array. Just remember that individual pieces of data is in order.

- `struct fish snappy = {"Snappy", "Piranha", 69, 4}`;

- This struct stores the pointer to a string. We can make it store the `char` array by declaring `char name[20]`.

# 4. Just give them the fish

- Now we define the function which takes in a `struct` like `void catalog(struct fish f)` and invoke it like `catalog(snappy)`.

- One of the great things about passing data inside `struct` is that we can change the contents of our `struct` without having to change the functions that use it.

Now, how do functions be able to read the individual pieces of data stored inside the `struct`.

# 5. Read a Struct's field with the "." operator

- If we try to read a struct field like its an array, we will get an array.

- Although `struct` stores fields like an array, only way to access the fields is by their name using the `.` operator.

- The code becomes more readable and if we have to record some extra data in the `struct`, we wont have to change anything in the functions that use it.

## Extra

- `struct` is not an array but like an array it groups a number of pieces of data together.
- A `struct` variable is a name for the `struct` itself.
- We can access the fields only by name.
- `struct` are similar to classes in other language, but not easy to add methods.

## Struct Memory Up Close

- When we define a `struct`, computer does not create anything new in the memory. We just provide a template for the new kind of data. (Presumably, it remains in the source code part of the memory)

- When we create a new instance of a `struct`, computer needs to create space in memory for that instance - ie the space in memory should be big enough to contain all of the fields.

- When we assign a `struct` to another variable, computer creates a brand new copy. (Presumably, because it had to create the space according to `struct` definition)

- When we are assigning struct variables, we are telling the computer to copy data. If that data includes pointers, the assignment will copy the pointer values.

# 6. Can you put 1 struct inside another ?

- `struct` lets us combine existing types together so that we can describe more complex objects to the computer. That means we can create structs from other structs.

- Struct has to be defined before using.

- All these struct commands are wordy - whenever we define a struct-template and also when we define an struct-instance.

- `typedef` allows us to create an alias for `struct`. If we add `typedef` before the struct keyword and 'type name' after the closing brace. Usually we dont need 2 different names for struct and its alias. We can simply skip the struct name.

- `typedef` shortens our code and make it easier to read.

## Summary and Extra

- A `struct` is a data type made from a sequence of other data types.
- `structs` are fixed length.
- `struct` fields are accessed by name using dot notation.
- `struct` fields are stored in the memory in the same order they appear in the code.
- we can nest `struct`s
- `typedef` creates an alias for a data type.
- If we use `typedef` with a `struct`, then you can skip giving the `struct` a name.

- Sometime there are small gaps between `struct` fields in memory.

- In C, all assigments are pass-by-value, ie all assignments copy data. Need to assign a pointer if we want to reference a piece of data.

- The `struct` name is the word that follows the `struct` keyword.
- `typedef` allows us to create aliases. Alias follows the closing braces.
- Anonymous struct is a struct without a name.

# 7. How do you update a Struct?

# 8. The code is cloning the turtle

- When we pass a struct as argument, C sends a copy of that struct as argument. Hence, updates to the struct from within the function has no effect from within the calling function.

- The called function gets the clone of the original turtle.

- What do you do if we want to update a struct (or any other variable) from a function.

# 9. You need a pointer to the struct

- Instead of passing a copy of the value, we need to pass a pointer to the memory location.

# 10. (*t).age versus *t.age

- `*t.age` <=> `*(t.age)` ie the content of memory location given by `t.age` - but `t.age` is not a memory location.
- Because `.` operator has precedence over `*`
- Need to be careful about the paranthesis.

- `(*t).age` <=> `t->age`

## summary

- When you call a function, the values are copied to the parameter variables.
- You can create pointers to structs, just like any other type
- `pointer->field` is same as `(*pointer).field`
- `->` notation cuts down on paranthesis and makes the code more readable

# 11. Sometimes the same type of thing needs different types of data

- Structs allows us to combine data types to make a new data type. What about individual pieces of data that does not have a single data type ?

- For example : What about recording a quantity of something - depending on the nature of the thing, that quantity could be count, weight or volume.

- We can create a `struct` with all these fields. But it will take up more space in memory, someone might set more than 1 value and there is nothing called 'quantity'.

- We want to have a `quantity` data-type and then decide for each particular piece of data whether we want to record a count, weight or volume against it. In C, we do it by using a union.

# 12. A union lets you reuse memory space

- Every time we create an instance of `struct`, the computer lays out the field in memory 1 after another.

- A `union` uses the space for just 1 of the fields in its definition. The computer will give the `union` enough space for its largest field, and then leave it up to you which value you will store. The data will go to the same place in memory.

- We define the template of `union` exactly the same way as we define the template of the `struct`, just that we replace the keyword `struct` by `union`.

# 13. How do you use a union?

- There are different ways in which we can declare set the values in a union. Say `quantity` is a union, then :

  - `quantity q = {4}` - this sets the first field only
  - `quantity q = {.weight = 1.5};` - designated initializer to set other value
  - `quantity q; q.volume = 3.7` - declaring a variable on 1 line and setting a field value on another line.

- Whichever way we set up the union's value, only 1 piece of data gets stored.

- (Designated initializers can be used to set the initial values of fields in structs as well. There is no need to use them but without them, we need to maintain the order of fields)

- Once we have created a `union`, we have create a new data type which can be used anywhere like `int` or `struct`. Typically we combine them with structs. See example 12.

- We can store a lots of possible values in a union, but we have no way to knowing what type it was once it is stored.

- `enum` is used to solve this

# 14. An enum variable stores a symbol

- Sometimes instead of a number or a piece of text, we want to store something from a list of symbol. Say we want to have day of week from MONDAY, TUESDAY, WEDNESDAY, etc,

- `enum` lets you create a list of symbols. Syntax : `enum colors {RED, GREEN, PUCE};`

- We define as `enum colors favorite = PUCE;`

- Under the hood, computer will assign numbers to each of the symbols in the list - and the `enum` will just store a number.

- `struct` and `union` separate items with semicolon `;`, but enum use commans `,`.

- Since we create a new data type with `enums`, we can store them inside `structs` and `union`. Then we can use that `enum` to track the kinds of quantities being stored.

# 15. Sometimes you want control at the bit level

- Say we need a `struct` which contains a lot of yes / no value. We can do that with a `struct` made of series of `short` or `int`.

- Other in-built types will take a lot more space than required.

- C does not support binary literals, but it does support hexadecimal literals. Every time C sees a number begining with `0x`, C treats it as base 16.

- We can convert hex to binary 1 digit at a time. Each hex digit matches a binary digit of length 4.

# 16. Bitfields store a custom number

- We can use a struct as a bitfield by :
  - having each field as an `unsigned int`
  - appending `:1` to every field name.

- If we have a sequence of bitfields, the computer can squash them together to save space.

- Bitfields are also important if we try to read or write some sort of custom binary files.

# 17. Your C Toolbox
