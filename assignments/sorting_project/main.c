#include "file_lib.h"
#include <stdio.h>
#include "sorter.h"
	
/*
 * Read the file from the command-line.
 * Usage:
 * ./a.out FILE_TO_READ FILE_TO_WRITE
 *
 */

int main(int argc, char** argv) {
	char* unsortedFileName = argv[1];
	char* sortedFileName = argv[2];

	char* contents;
	size_t fileSize = fopen(unsortedFileName, "r");

	int numWords = 0;
	for (int i = 0; i < fileSize; i++) {
		if (contents[i] == '\n') {
			numWords++;
		}
	}
	
	sort(&contents, numWords);

	fprintf(sortedFileName, contents, fileSize);
	free(contents);
	return 0;
}

// You can see if your file worked correctly by using the
// command:
//
// diff ORIGINAL_FILE NEW_FILE
//
// If the command returns ANYTHING the files are different.
