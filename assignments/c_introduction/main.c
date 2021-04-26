#include <stdio.h>
#include <stdlib.h>
#include "CircleLibrary.h"
#include "RectangleLibrary.h"

int main(int argc, char* argv[]) {

	if (argc == 2) {
		double radius = atof(argv[1]);

		printf("Perimeter of a Circle with a Radius of %f =  %f\n",radius, calcCPerimeter(radius));
		printf("Area of a Circle with a Radius of %f = %f\n", radius, calcCArea(radius));
	} 
	
	if (argc == 3) {
		double length = atof(argv[1]);
		double width = atof(argv[2]);

		printf("Perimeter of a %f x %f Rectangle = %f\n", length, width, calcRPerimeter(length, width));
		printf("Area of a %f x %f Rectangle = %f\n", length, width, calcRArea(length, width));
	}	
	return 0;
}
