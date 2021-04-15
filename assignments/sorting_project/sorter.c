#include "sorter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/***********************************************************************
Functions emulating the quicksort alogrithm to sort a file's contents.

@author Kyle Ronayne
@version Winter 2021
***********************************************************************/


/***********************************************************************
Swaps the memory location for two strings. Helper function for the
quicksort function.
@param char** a: Pointer to the first string in the array
@param char** b: Potiner to the second string in the array
@return: None
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
@return None
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


/***********************************************************************
A function that receives a string of words and sorts them.
@param char** contents: A pointer to a string of newline separated words
@param int size: The number of words in the contents string
@return: None
***********************************************************************/
void sort(char** contents, int size) {

	// The number of words in contents
	int numWords = size;
	int maxWordLength = 0;

	// The number of bytes of contents
	int numBytes = 0;

	// Determining the length of the longest word
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

	// Creating an array of the appropraite size and placing the
	// words into it
	char** list;
	list = (char **)malloc(numWords * sizeof(char*));
	for (int i = 0; i < numWords; i++) {
		list[i] = (char*)malloc(maxWordLength * sizeof(char));
	}
	int a = 0;
	int b = 0;
	for (int i = 0; i < numBytes; i++) {
		if((*contents)[i] == '\n') {
			// Set to null character, we do not want to
			// inlcude a newline character as part of the
			// string
			list[a][b] = '\0';
			a++;
			b = 0;
		} else {
			list[a][b++] = (*contents)[i];
		}
	}

	// Using the quicksort function to sort the array of strings
	quicksort(list, 0, numWords - 1);

	// Transforming the array back into a string
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

	// Deallocating list from memory
	free(list);

	// Deallocating sortedContents
	free(sortedContents);
}
