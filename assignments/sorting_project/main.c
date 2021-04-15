#include "file_lib.h"
#include <stdio.h>
#include "sorter.h"


/***********************************************************************
C program that reads a given file and uses the quicksort algorithm to
sort the file's contents and output it to a new file.

@author Kyle Ronayne
@version Winter 2021
***********************************************************************/


/***********************************************************************
Main function of the sorting program that receives two arguments,
resepctively, the name of the un-sorted file and the name of the sorted
output file, and class the appropriate functions to sort the contents of
the provided file.
@param int argc: Argument count
@param char**: Argument vector
***********************************************************************/
int main(int argc, char** argv) {
	char* unsortedFileName = argv[1];
	char* sortedFileName = argv[2];

	char* contents;
	size_t fileSize = load_file(unsortedFileName, &contents);
	
	// Determining the number of words in contents
	int numWords = 0;
	for (int i = 0; i < fileSize; i++) {
		if (contents[i] == '\n') {
			numWords++;
		}
	}
	
	sort(&contents, numWords);

	save_file(sortedFileName, contents, fileSize);

	// Deallocating contents from memory
	free(contents);
	return 0;
}
