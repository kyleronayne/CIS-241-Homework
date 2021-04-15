#include "stdio.h"
#include "circleLib.h"
#include "newLib.h"

double caclRectanglePerim(double length, double width);
double calcRectangleArea(double length, double width);

int  main(int argc, char* argv[]) {
	double length, width;
	printf("Rectangle Perimeter: %f\n", calcRectanglePerim(length, width));
	printf("Rectangle Area: %f\n", calcRectangleArea(length, width));
}
