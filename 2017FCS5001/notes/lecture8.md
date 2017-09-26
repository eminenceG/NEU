# Defining New Types
**A data type** is how a programming language classifies a set of values into a common category, defines how values can be manipulated, and how they interact with other data types.

- **References** provide indirect access to values of another data type
- **Sequences** are indexable homogeneous collections of another data type
- **Aliases** provide an alternate name for another data type
- **Enumerations** explicitly identify collections of discrete values that comprise data types.
- **Aggregations** are heterogeneous combinations of other data types

## Typedef
**DEF** A *typedef* is an alias for an existing data type.

a typedef declaration does not create a new type in any sense; it merely adds a new name for some existing type

### Syntax

	typedef existing-type new-type;
	
Examples:
	
	typedef int Length;
	Length len, maxlen;
	Length *lengths[];


	typedef char *String;
	String p, lineptr[MAXLINES], alloc(int)
	int strcmp(String, String);
	p = (String) malloc(100);
	
### Advantages
1. Parameterize a program against portability problems.
2. Provide better documentation for a program

### Typedef a Pointer
The general practice is not for several reasons:

- A typedef of a pointer to a type is no clearer than simply adding the pointer modifier to the type specification
- A typedef of a pointer obscures the pointer nature, so when a typedef pointer is derefe- renced the code is often less clear

### Typedef and 

## Enum
**DEF** An *enum* is an enumerated type that specifies a fixed set of choices.

Strongly recommend using typedef with enum to also define it as a type

### Synthax

	enum identifier(opt) {enumerator-list};
	
Examples:
	
	enum boolean { No, Yes };
	typedef enum { Sun, Mon, Tue, Wed, Thu, Fri, Sat } DayOfWeek;
	
## Struct
**DEF** *Struct* is an aggregation of heterogeneous types that represent a record. 

Strongly recommend using typedef with struct to also define it as a type
