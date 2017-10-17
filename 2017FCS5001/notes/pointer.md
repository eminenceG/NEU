## Pointer

**DEF** A _pointer_ is a variable that contains the address of a variable.

The **unary operator &** gives the address of an object:

```
p = &c;
```

The **unary operator &** is the *indirection* or *dereferencing*
operator, it accesses the object the pointer points to:

```    
int x = 1;    
int *p; // declaration
p = &x;
printf("%d\n", *p); // should print 1;
```

### Multi-dimensional Array

In C, a two-dimensional array is really a one-dimensional array, each of whose elements is an array.

If a two-dimensional array is to be passed to a function, the parameter declaration in the function must include the number of columns; the number of rows is irrelevant, since what is passed is, as before, a pointer to an array of rows.

Example:
```
f(int daytab[2][13]) { ... }

// could also be:
f(int daytab[][13]) { ... }

// could also be:
f(int (*daytab)[13]) { ... }
```

These declarations say that the parameter is a pointer to an array of 13 integers.

More generally, only the first dimension(subscript) of an array is free; all the others have to be specified.M

### Pointers vs. Multi-dimensional Arrays

Given the definitions

```
int a[10][20];
int *b[10];
```

a\[3\]\[4\] and b\[3\]\[4\] are both syntactically legal references to a single **int**.

- a is a true two-dimensional array: 200 int-sized locations have been set aside, and the conventional rectangular subscript calculation 20 * *row* + *col* is used to find the element a\[row\]\[col\].
- For b, the definition only allocates 10 pointers and does not initialize them; initialization must be done explicitly, either statically or with code.

The important advantage of the pointer array is that the rows of the array may be of different lengths.

### Pointers to Functions

In C, a function itself is not a variable, but it is possible to define pointers to functions, which can be assigned, placed in arrays, passed to functions, returned by functions, and so on.

A function can take pointers to
functions as parameters, for example:

```
void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
```
The fourth parameter of **qsort** is:
```
int (*comp)(void *, void *)
```
which says that comp is a pointer to a function that has two **void \*** arguments and returns an **int**. Use **\*comp** to call the function:
```
(*comp)(v[i], v[left])
```
To pass function:
```
int numcmp(char *, char*);
```
to **qsort**, just use **numcmp** rather than **&numcmp** because numcmp is the address of function.
