## Input and Output
### Standard Input and Output
The simplest input mechanism is to read one character at a time from the standard input, normally the keyboard, with **getchar:**

    int getchar(void)

**getchar** returns the next input character each time it is called, or EOF when it encounters end of file.

The function

    int putchar(int)

is used for output: **putchar\(c\)** puts the character c on the standard output, which is by default the screen. **putchar** returns the character written, or EOF is an error occurs.

###Formatted Output - printf
The output function **printf** translates internal values to characters.

    int printf(char *format, arg1, arg2, ...)

**printf** converts, formats, and prints its arguments on the standard output under control of the **format**. It returns the number of characters printed.

Each conversion specification begins with a % and ends with a conversion character. Between the % and the conversion character there may be, in order:
- A minus sign, which specifies left adjustment of the converted argument.
- A number that specifies the minimum field width.
- A period, which separates the field width from the precision.
- A number, the precision, that specifies the maximum number of characters to be printed from a string, or the number of digits after the decimal point of a floating-point value, or the minimum number of digits for an integer.
- An **h** if the integer is to be printed as a short, or **l** (letter ell) if as a long.

The function **sprintf** does the same conversions as **printf** does, but stores the output in a string:

    int sprintf(char *string, char *format, arg1, arg2, ...);


### Formatted Input - Scanf

The function **scanf** is the input analog of **printf**, providing many of the same conversion facilities in the opposite direction.

    int scanf(char *format, ...)
