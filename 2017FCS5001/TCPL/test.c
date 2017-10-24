#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char str[] = "HELLO";
	char *s = "HELLO";
	char *t = "HELLO";
	printf("%p\n", str);
	printf("%p\n", s);
	printf("%p\n", t);
}