# Activity 6: Binary Arithmetic and Overflow
## Put your name(s) here

In this activity, you are will experiment with ways to detect when overflow has happened with signed integers.
- You will examine how to check for two unsigned integers overflowing when added
- You will examine how to check for two signed integers overflowing when added (see disclaimer below)
- You will modify the test functions for the previous functions to use `assert` to check for the correct outcome
- You will modify two functions to check whether signed and unsigned integer subtraction results in overflow
- You will write a set of tests using `assert` to check whether the subtraction overflow functions works correctly

## Disclaimer!

__What we do here is not the approved method for checking for overflow!!__

- The C programming language does not specify what happens when an arithmetic expression involving signed integers overflows 
- Thus the specific behavior (crashing, returning a nonsense value, etc.) can vary from system to system; programs are officially "illegal" after an overflow 
- The "correct" approach when writing code that might overflow is to check __before__ performing the arithmetic operation (see References below)
- We are doing it anyway for demonstration purposes, because we know how the server's system and gcc will handle the overflow!


## Provided Code

There is just one code file and a Makefile for this activity:

- `check_overflow.c`
    - the main source file with two tasks defined in it
- `Makefile`
    - a short makefile to automate the compilation process

You will only need to edit `check_overflow.c`.

## Your Tasks

### First Steps
- As always, add your name in a comment at the top of each file you edit!
- Read through all the files, including the header and Makefile to be sure you
understand the context of what you are doing. 

### Task 1: Checking the unsigned addition overflow detector

- Examine the code that checks for unsigned integer addition overflow (`check_unsigned_add`
and `uadd_ok`); make sense of what both are doing and how they work
- Modify the `check_unsigned_add` function so that it uses assert to check whether 
the result returned by `uadd_ok` is correct or not: 1 for true, 0 for false
- Do the test calls adequately test the detector function?

### Task 2: Checking the signed addition overflow detector

- Examine the code that checks for signed integer addition overflow (`check_signed_add`
and `sadd_ok`); make sense of what both are doing and how they work
- Modify the `check_signed_add` function so that it uses `assert` to check whether 
the result returned by `sadd_ok` is correct or not: 1 for true, 0 for false
- Do the test calls adequately test the detector function?

### Task 3: Creating and testing an unsigned subtraction overflow detector

The code file contains a stub definition of `usub_ok` and its testing function,
`check_unsigned_subtr`. Your task will be to complete the definition of `usub_ok`
and then to write tests using `assert` that adequately test it
- Think through the logic for unsigned integers: when can overflow take place 
with subtraction of unsigned (non-negative) integer?
- Implement `usub_ok` to return 1 if there is no overflow, and 0 if there is
- Write at least 5 tests in the test function!

### Task 4: Creating/debugging and testing a signed subtraction overflow detector

The code file contains a stub definition of `ssub_ok` and its testing function,
`check_signed_subtr`. The definition uses the trick of negating the second number and
then treating it as an addition. This seems sensible, but _doesn't work!_

- Create test cases (with `assert`) in `check_signed_subtr` to check the behavior
of `ssub_ok`. Find cases where the starting definition returns the wrong value 
(hint: try 0 - INTMIN, for one).
- Modify `ssub_ok` so that it works correctly all of the time



## References

- Detecting overflow in C (methods and pitfalls)
  -  [Detecting signed overflow in C/C++](https://stackoverflow.com/questions/3944505/detecting-signed-overflow-in-c-c)
  - [How do I detect unsigned integer overflow?](https://stackoverflow.com/questions/199333/how-do-i-detect-unsigned-integer-overflow)
- General C syntax help
  - [Chapter 1 of _Dive into Systems_](https://diveintosystems.org/book/C1-C_intro/index.html)
  - _The C Programming Language_, often just known as K&R for Kernighan and Ritchie
  - _C: A Reference Manual_, by Harbitson and Steele

