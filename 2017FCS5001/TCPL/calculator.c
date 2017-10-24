#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int main(void) {
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push (atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-';
				op2 = pop();
				push(pop() - op2);
				break;
			case '/';
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("go fuck yourself\n");
				break;
			case '\n'
				printf("%t\n", pop());
				break;
		}
	}
	return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
	if (sp < MAXVAL) {
		val(sp++) = f;
	}
}

double pop(void) {
	if (sp > 0) {
		return val[--sp];
	}
}

#include <ctype.h>

int getch(void)
void ungetch(int) 

int getop(char s[]) {
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!is)
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	buf[bufp++] = c;
}