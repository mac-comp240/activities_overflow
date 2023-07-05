# Activity 5: Getting deep into integers

In this activity, you are provided working source code. You will modify the code
to illustrate the representation principles of signed vs. unsigned integers,
widening and narrowing during casting, and the limits/boundaries of different
integer data types.

## Provided Code

There are two code files, one header file, and a Makefile for this activity:

- `test_c.c`
    - the main source file with three tasks defined in it
- `binary_convert.c`
    - a library file containing functions to convert integers to binary strings
- `binary_convert.h`
    - a header file for the library
- `Makefile`
    - a short makefile to automate the compilation process

You will only need to edit `test_c.c`. Note that we are reusing the library
of conversion functions `binary_convert.c` from the previous activity.

## Your Tasks

### Task 1: Differences between signed and unsigned

Recall from Activity 2 each integer type has max and min values determined
by how many bytes it has, and that these values can be referenced from named
constants in `limits.h`. We will now examine the differences between the
limits of unsigned and signed numbers.

Note that for this activity, the Makefile has an example of building a program whose name is different than the .c file used to build it.

- Read the code in `test_tc.c,` refamiliariz yourself with the functions in
`binary_convert.c`, and look at the `Makefile`.

- Build and run the demo code in `test_tc.c`. We are going to first consider the C
data type `short`, whose size in bytes and max and min limits are printed with the
code at the beginning of `task1`. You may wish to revisit the [printf format
reference](http://www.cplusplus.com/reference/cstdio/printf/).

- Add other example values. Print their binary strings and verify that you
understand the bit patterns.

- Now, try it with an unsigned short. Using `limits.h`, print the binary
representation of the largest value for this data type, as well as other values.

### Task 2: Casting between types

Your reading discussed "sign extension," where we might cast a number from a smaller type
to a larger one. Casting from a larger type to a smaller one can lead to errors, as
higher-order bits are simply truncated.

The code for `task2` gives an example of each conversion.
- Try the current code.
- Modify the code to print the binary representations of both `a` and `b`
- Try some other values: negative values, `int` values small enough to fit in a `short`, etc.
- What do you see and why does it happen that way?

The third example in `task2` converts a signed short to an unsigned short. 
- Try this code
- Modify the code to print out the underlying binary representations of uv and v
- What do you observe? Why is this so?

When we convert a signed integer to an unsigned one the same size, negative values
become large positive values, but positive values remain the same.
- Try additional values for `v` to illustrate this 


### Task 3: Integral values have limits

The last task, `task3`, prints a table of representations of signed char values from -64 to +63.  
- Uncomment the call to `task3`
- Run the program to see what happens

#### What happens if we increase the range?

Values declared to be signed char type are 1 byte long, or 8 bits. What
happens when you change the range in the for loop to go through all values in
the range of signed chars (-128 to 127)? 
- Modify `task3` to do this and run it

**Stopping Runaway Code:** CTRL-C will quit any running program on the command
line. You may need to wait quite a bit for the command prompt to come back, but
it will eventually.

Read through the output prouced. Work through in your mind what is happening when you try using the full range of values in the for loop. Discuss this with your teammates and neighbors. Improve the code and try again. 

**Saving Output:** Now switch the code to values that will not create an
infinite loop, such as -64 to +63. After building with make, you can run the
program this way to save what is printed:

	./twos_comp > tc_out

This puts the output into a file called `tc_out`. You can view that file using a
program called less:

	less tc_out

Hitting the Q key will quit out of less. Space bar scrolls down, control-b or
control-u goes back up.

#### Avoiding overflow in a loop

There are a few ways to avoid having this loop run infinitely. Here is one that
works fairly well. Add this to the bottom of the loop just before it goes back
around:

```
    if (i == 127) break;
```

You can also change the loop to do one fewer value, then print the last one outside of the loop.


## References

- Makefile guides
  - [An Introduction to Makefiles](https://www.gnu.org/software/make/manual/html_node/Introduction.html), by GNU
  - [Makefile Tutorials and Examples to Build From](https://earthly.dev/blog/make-tutorial/), by Aniket Bhattacharyea
  - [makefile basics - anthony explains](https://www.youtube.com/watch?v=20GC9mYoFGs)
- Printf formatting codes
  - [printf format specifier reference from cplusplus.com](http://www.cplusplus.com/reference/cstdio/printf/).
  [_Format Specifiers in C_](https://www.thecrazyprogrammer.com/2016/10/format-specifiers-c.html) by The Crazy Programmer
- General C syntax help
  - [Chapter 1 of _Dive into Systems_](https://diveintosystems.org/book/C1-C_intro/index.html)
  - _The C Programming Language_, often just known as K&R for Kernighan and Ritchie
  - _C: A Reference Manual_, by Harbitson and Steele
