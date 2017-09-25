## Pointer
**DEF** A *pointer* is a variable that contains the address of a variable. 

The **unary operator &** gives the address of an object:
	
	p = &c;

The **unary operator \*** is the *indirection* of *dereferencing* operator, it accesses the object the pointer points to:

	int x = 1;
	int *p; // declaration
	p = &x;
	prinf("%d\n", *p); // should print 1;


