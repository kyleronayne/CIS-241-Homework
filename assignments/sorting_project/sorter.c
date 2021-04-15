#include "sorter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/***********************************************************************
C program that reads a given file and uses the quicksort alogrithm
to sort the file's contents and output it to an new file.

@author Kyle Ronayne
@version Winter 2021
***********************************************************************/


/***********************************************************************
Swaps the memory location for two strings. Helper function for the
quicksort function.
@param char** a: Pointer to the first string in the array
@param char** b: Potiner to the second string in the array
***********************************************************************/
void swap(char** a, char** b) {
	char* temp = *a;
	*a = *b;
	*b = temp;
}


/***********************************************************************
A funtion that implements the quicksort algorithm to sort the contents
of an unsorted array.
@param char** contents: The unsorted array of strings
@param int left: The index to start sorting the contents array
@param int right: The index to stop sorting the contents array
***********************************************************************/
void quicksort(char** contents, int left, int right) {

	// Recursive base case
	if (left >= right) return;
	
	// Generated a random pivot index to define the pivot point
	int pivotIndex = srand(1); (rand()%(right - left)) + left;

	// The pivot used for partitioning contents
	char* pivot = contents[pivotIndex];

	swap(&contents[pivotIndex], &contents[right]);

	// Paritioning
	int l = left;
	int r = right - 1;
	while (1) {
		while (strcasecmp(contents[l], pivot) < 0) {
			l++;
		}

		while (r >= left && strcasecmp(pivot, contents[r]) < 0)
	       	{
			r--;
		}

		if (l >= r) {
			break;
		}

		swap(&contents[l], &contents[r]);
	}
	pivotIndex = l;

	// Swapping strings based on appropraite pivot
	swap(&contents[pivotIndex], &contents[right]);

	quicksort(contents, left, pivotIndex - 1);
	quicksort(contents, pivotIndex + 1, right);
}

void sort(char** contents, int size) {
	int numWords = size;
	int maxWordLength = 0;
	int numBytes = 0;

	int tempMaxWordLength = 0;
	for (int i = 0; i < numWords; i++) {
		while ((*contents)[numBytes++] != '\n') {
			tempMaxWordLength++;
			if (tempMaxWordLength > maxWordLength) {
				maxWordLength = tempMaxWordLength;
			}
		}
		tempMaxWordLength = 0;
	}

	char** list;
	list = (char **)malloc(numWords * sizeof(char*));
	for (int i = 0; i < numWords; i++) {
		list[i] = (char*)malloc(maxWordLength * sizeof(char));
	}

	int a = 0;
	int b = 0;
	for (int i = 0; i < numBytes; i++) {
		if((*contents)[i] == '\n') {
			// set to null character
			list[a][b] = '\0';
			a++;
			b = 0;
		} else {
			list[a][b++] = (*contents)[i];
		}
	}

	quicksort(list, 0, numWords - 1);

	char* sortedContents = malloc(numBytes);
	strcpy(sortedContents, "");
	for (int i = 0; i < numWords; i++) {
		strcat(sortedContents, list[i]);
		strcat(sortedContents, "\n");
	}
	strcpy(*contents, sortedContents);

	for (int i = 0; i < numWords; i++) {
		free(list[i]);
	}
	free(list);
	free(sortedContents);
}
