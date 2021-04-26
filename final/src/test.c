#include "test.h"
#include "math.h"
#include "student.h"
#include <stdlib.h>
#include <stdio.h>
#include <cstring>

/**
 * Example for demonstration at start of test.
 */

int example(){
	return 42;
}

/**
 * Warmup (but counts for credit!)
 * Square the value x points to.
 */
void easyPeasy(int* x){
	*x = *x * *x;
}

/**
 * Set a's first name to "Jigglypuff".
 * Set the last name to "Ketchum".
 * Set the g number to 10, the gpa to 1.16.
 */
void one(Student* a) {
	a->first_name = "Jigglypuff";
	a->last_name = "Ketchum";
	a->g_number = 10;
	a->gpa =  1.16;
}

/**
 * Copy the information from Student b to Student a.
 * (pointer parameters).
 */
void two(Student* a, Student* b) {
	set_first_name(a, (char*) get_first_name(b));
	set_last_name(a, (char*) get_last_name(b));
	set_g_number(a, (int) get_g_number(b));
	set_gpa(a, (float) get_gpa(b));
	set_roommate(a, get_roommate(b));
}

/**
 * Copy the information from Student a to Student b.
 * (mixed variable type parameters).
 */

void three(Student a, Student* b) {
	b->first_name = a.first_name;
	b->last_name = a.last_name;
	b->g_number = a.g_number;
	b->gpa = a.gpa;
	b->roommate = a.roommate;
}

/**
 * Create and return a Student.  Give it the values
 * "T. Yoshisaur" (first_name)
 * "Munchakoopas" (last_name)
 * 1990		  (g_number)
 * 3.1		  (gpa)
 * Mario	  (roommate [defined above])
 * Remember: C is pass by copy ONLY.
 */
Student four(){
	Student a;

	strcpy((char*) a.first_name, "T. Yoshisaur");
	strcpy((char*) a.last_name, "Munchakoopas");
	a.g_number = 1990;
	a.gpa = 3.1;
	a.roommate = &Mario;

	return a;
}

/**
 * Create and return a Student*.  Give it the value
 * "Luigi" (first_name)
 * "Mario" (last_name)
 * 2       ( :( )
 * 3.54    (gpa [we know he's the smart one])
 * Remember: C is pass by copy ONLY.
 */
Student* five() {
	Student* student;
	student->first_name = "Luigi";
	student->last_name = "Mario";
	student->g_number = 2;
	student->gpa = 3.54;
	student->roommate = NULL;
	return student;
}

/**
 * Create a hunk of memory we can use as an array of 10
 * Students.  Set the 4th element (meaning use array
 * index 3) to
 *
 * "Luigi" (first_name)
 * "Mario" (last_name)
 * 2       ( :( )
 * 3.54    (gpa [we know he's the smart one])
 */
Student* six(){
	return NULL;
}

/**
 * Seven will take a pointer to a pointer.  It should
 * create a hunk of memory that can be used as an array
 * of size 10, and will set the pointer correctly so
 * that the "array" is usable in main.
 * Set the 10th (index 9) element equal to
 *
 * "Luigi" (first_name)
 * "Mario" (last_name)
 * 2       ( :( )
 * 3.54    (gpa [we know he's the smart one])
 */
void seven(Student** students){
	
}

/**
 * Given a, b, and c calculate the first solution for
 * the quadratic equation (given below).
 *
 * -b + sqrt(b^2 - 4ac) / (2a)
 */
double quadratic(double a, double b, double c){
}

/**
 * Given a "string" (a character array) and a length,
 * replace each lower case character with its uppercase
 * equivalent.
 *
 * Do not use any string functions provided by the library.
 * Merely check to see if each character is between the
 * range of values for a lowercase letter.  If it is,
 * replace it with the uppercase value equivalent.
 *
 * If you are writing more than five lines you are doing it wrong.
 */
#include <stdio.h>
void capitalize(char* str, size_t len){
}
