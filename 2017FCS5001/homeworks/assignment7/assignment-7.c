#include <stdio.h>
#include <stdlib.h>

typedef struct {
	double x;
	double y;
} Point;

Point *createPoint(double x, double y);




Point *createPoint(double x, double y) {
	Point *p = malloc(sizeof(Point));
	p->x = x;
	p->y = y;
	return p;
}
x	