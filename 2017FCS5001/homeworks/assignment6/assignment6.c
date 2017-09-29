#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef struct 
{
	int x;
	int y;
} Point;

Point p1;

typedef struct 
{
	double radius;
	Point center;
} Circle;

typedef struct 
{	
	Point origin;
	double width;
	double height;
} Rectangle;


double distanceofPoints(Point *p1, Point *p2) {
	int dx = p1->x - p2->x;
	int dy = p1->y - p2->y;
	return sqrt((double) dx * dx  + dy * dy);
}

bool intersectCircles(Circle *c1, Circle *c2) {
	return (distanceofPoints(&(c1->center), &(c2->center)) < c1 -> radius + c2 -> radius);
}

Rectangle *getBoundingBox(Circle *c, Rectangle *boundingBox) {
	boundingBox->origin.x = c->center.x - c->radius;
	boundingBox->origin.y = c->center.y + c->radius;
	boundingBox->width = 2 * c->radius;
	boundingBox->height = 2 * c->radius; 
	return boundingBox;
}

void showIntersection(Circle *c1, Circle *c2) {
	if (intersectCircles(c1, c2))
		printf("intersect\n");
	else 
		printf("do not intersect\n");
}

int main(void) {

	Circle c1 = {10, {0, 0}};
	Circle c2 = {10, {21, 0}};
	Circle c3 = {10, {20, 0}};
	Circle c4 = {10, {19, 0}};

	showIntersection(&c1, &c2);
	showIntersection(&c1, &c3);
	showIntersection(&c1, &c4);	
}