## Pointer

**DEF** A _pointer_ is a variable that contains the address of a variable.

The **unary operator &** gives the address of an object:
    
    p = &c;

The **unary operator &** is the *indirection* or *dereferencing* operator, it accesses the object the pointer points to:
    
    int x = 1;
    
    int *p; // declaration
    
    p = &x;
    
    printf("%d\n", *p); // should print 1;



