
/*
 * assignment-6.c
 *
 * CS 5001 Fall 2017 Silicon Valley
 * Assignment 6: Point Circle Rectangle Structures
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Define and typedef a struct Point 
typedef struct 
{
	double x;
	double y;
} Point;

// An instance of Point
Point p1;

// Define and typedef a struct Circle
typedef struct 
{
	double radius;
	Point center;
} Circle;

// Define and typedef a struct Rectangle
typedef struct 
{	
	Point origin;
	double width;
	double height;
} Rectangle;

/**
* compute the distance between two Points
* @param p1 a pointer to Point 1
* @param p2 a pointer to Point 2
* @return the distance between p1 and p2
*/
double distanceofPoints(Point *p1, Point *p2) {
	double dx = p1->x - p2->x;
	double dy = p1->y - p2->y;
	return sqrt(dx * dx + dy * dy);
}

/**
* check if two circles intersect
* @param circle1 a pointer to Circle 1
* @param circle2 a pointer to Circle 2
* @return true if two circles intersect and vice versa
*/
bool intersectCircles(Circle *circle1, Circle *circle2) {
	return (distanceofPoints(&(circle1->center), &(circle2->center)) < circle1 -> radius + circle2 -> radius);
}

/**
* set the fields of Rectangle to the bounding box that encloses the circle
* @param circle a pointer to the enclosed Circle
* @param boundingBox a pointer to the Ractangle result
* @return a pointer to the enclosing rectangle
*/
Rectangle *getBoundingBox(Circle *circle, Rectangle *boundingBox) {
	boundingBox->origin.x = circle->center.x - circle->radius;
	boundingBox->origin.y = circle->center.y + circle->radius;
	boundingBox->width = 2 * circle->radius;
	boundingBox->height = 2 * circle->radius; 
	return boundingBox;
}

/**
* print the bounding-box
* @param circle the enclosed circle
* @param boundingBox the enclosing rectanglez`
*/
void printBoundingBox(Circle *circle, Rectangle *boundingBox) {
	getBoundingBox(circle, boundingBox);
	printf("The origin of the bounding-box is: (%.1f, %.1f)\n", boundingBox->origin.x, boundingBox->origin.y);
	printf("The width of the bounding-box is: %.1f\n", boundingBox->width);
	printf("The height of the bounding-box is: %.1f\n", boundingBox->height);
}

/**
* print wheter Circle 1 and Circle 2 intersect
* @param circle1 a pointer to Circle 1
* @param circle2 a pointer to Ciecle 2
*/
void showIntersection(Circle *circle1, Circle *circle2) {
	if (intersectCircles(circle1, circle2))
		printf("intersect\n");
	else 
		printf("do not intersect\n");
}


int main(void) {

	Circle circle1 = {10, {0, 0}};
	Circle circle2 = {10, {21, 0}};
	Circle circle3 = {10, {20, 0}};
	Circle circle4 = {10, {19, 0}};

	showIntersection(&circle1, &circle2);
	showIntersection(&circle1, &circle3);
	showIntersection(&circle1, &circle4);

	Rectangle boundingBox;
	Rectangle *pb = &boundingBox;
	printBoundingBox(&circle1, pb);
	printBoundingBox(&circle2, pb);
	printBoundingBox(&circle3, pb);
	printBoundingBox(&circle4, pb);
}