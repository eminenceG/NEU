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




**size_t**: size_t is an unsigned integer type of at least 16 bit, this type is used to represent the size of an object. Library functions that take or return sizes expect them to be of type or have the return type of size_t.


The following C program has some very tricky parts and has been confusing me for a long time. After today's class about memory management, it becomes clear.	 

	#include <stdio.h>

	int *getPoint(int x) {
		int *p = &x;
		return p;
	}

	int main(void) {
		int x = 10;
		int *p = getPoint(x);
		printf("%d\n", *p);
		printf("%d\n", *p);
	}

	//output
	10
	0

As we see, two printf() give different results for \*p. The problem happens in function getPoint(). In this function, we created a local variable x and initialized pointer p with x's address. However, x is a local variable, which should be freed after returning of the function. Thus p will then point to an uninitialized part of memory. The tricky part is that first printf() gives "right" value of x and next ptintf() gives 0, which means "uinitialized".

This is because in the function getPoint(), we stored x on the stack memory. When we leave the function, it becomes assigned as something like "clear for using"(not deleted yet). The first printf() comes directly after the getPoint() function, the local variable x is still there, because it's not overwritten yet. So that works. Actually printf has int as a return value. So that has to be written to somewhere, and our PC writes it to the first free address of the dynamic memory, that is the address of previous local variable x. And since it has been overwritten, the next printf gives 0 for \*p.

There is another tricky thing that the second printf outputs 0 on my mac but outputs 10 on my Ubuntu OS. I guess this is because how C programs deal with dynamic memory that should be freed is environment dependent. So for situation like this, even if the results seem right, the program can bre problematic. 	
