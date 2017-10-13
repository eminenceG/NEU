## Basic Concepts

### Variable
**Variables** store values used during the computation. For example:

	int x = 10;

x is a variable that stores an integer value 1

### Data Types
The **type** of an object determines the set of values it can have and what operations can be performed on it.
#### Basic data types in C and their size:
Data Type | Usage | Size
--------- | ----- | ----
char | one charactet | 1 Byte
int | one integer | dependent on environment 
float | single-precision floating point | dependent on environment 
double | double-precision floating point | dependent on environment 

There are a number of **qualifiers** that can be applied to these basic types.
* short
* long
* unsigned 
* signed

### Constants

Data Type | Example
--------- | -------
int | 1234, 037(Octal), 0x1f(Hexadecimal)
long | 123456789L, 123456789l
unsigned int | 1234u, 1234U
unsigned long | 123456789UL, 123456789ul
double | 123.4, 1e-2
float | 123.4f, 123.4F
long double | 123.4l, 123.4L
char | 10, 'x', '\n'(escape sequences), '\ooo'(Octal), '\xhhh'(Hexadecimal)

### Declaration

All variables __must be declared before use__, although certain declarations can be made implicitly by content.
    
    int lower, upper, step;

A variable may also be initialized in its declaration.

    int i = 0;
    
If the variable is not automatic, the initialization is done once only, and the initializer mush be a constant expression.

**External** and **static** variables are initialized to zero by default. **Automatic** variables for which is no explicit initializer have undefined.

The qualifier **const** can be applied to the declaration of any variables to specify that its value will not be changed. For an array, the const qualifier says that the elements will not be altered.



                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    