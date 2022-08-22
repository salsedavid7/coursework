#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declarations of the two functions you will implement
// Feel free to declare any helper functions
void printPuzzle(char** arr, int n);
void searchPuzzle(char** arr, int n, char** list, int listSize);

// Main function, DO NOT MODIFY!!!	
int main(int argc, char **argv) {
    int bSize = 15;
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
		return 2;
	}
    int i, j;
    FILE *fptr;
    char **block = (char**)malloc(bSize * sizeof(char*));
	char **words = (char**)malloc(50 * sizeof(char*));

    // Open file for reading puzzle
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Cannot Open Puzzle File!\n");
        return 0;
    }

	// Read puzzle block into 2D arrays
    for(i = 0; i < bSize; i++) {
        *(block+i) = (char*)malloc(bSize * sizeof(char));

        fscanf(fptr, "%c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", *(block+i), *(block+i)+1, *(block+i)+2, *(block+i)+3, *(block+i)+4, *(block+i)+5, *(block+i)+6, *(block+i)+7, *(block+i)+8, *(block+i)+9, *(block+i)+10, *(block+i)+11, *(block+i)+12, *(block+i)+13, *(block+i)+14 );
    }
	fclose(fptr);

	// Open file for reading word list
	fptr = fopen("states.txt", "r");
	if (fptr == NULL) {
        printf("Cannot Open Words File!\n");
        return 0;
    }
	
	// Save words into arrays
	for(i = 0; i < 50; i++) {
		*(words+i) = (char*)malloc(20 * sizeof(char));
		fgets(*(words+i), 20, fptr);		
	}
	
	// Remove newline characters from each word (except for the last word)
	for(i = 0; i < 49; i++) {
		*(*(words+i) + strlen(*(words+i))-2) = '\0';	
	}
	
	// Print out word list
	printf("Printing list of words:\n");
	for(i = 0; i < 50; i++) {
		printf("%s\n", *(words + i));		
	}
	printf("\n");
	
	// Print out original puzzle grid
    printf("Printing puzzle before search:\n");
    printPuzzle(block, bSize);
	printf("\n");

	// Call searchPuzzle to find all words in the puzzle
	searchPuzzle(block, bSize, words, 50);
	printf("\n");
	
	// Print out final puzzle grid with found words in lower case
    printf("Printing puzzle after search:\n");
    printPuzzle(block, bSize);
	printf("\n");
	
    return 0;
}

void printPuzzle(char** arr, int n) {
	// This function will print out the complete puzzle grid (arr). It must produce the output in the SAME format as the samples in the instructions.
	// Your implementation here
	int x,y;
	for (x = 0; x < n; x++) {
		for(y = 0; y < n; y++) {
			printf("%c ", *(*(arr + x) + y));
		}
		printf("\n");
	}
}
void checkWord(char** arr, int n, int y, int x, char* word, int length) {
	int offset = 32;
	//if statement pings if theres is enough room in the grid to search down
	if (y + length <= n) {
		int i = 0;
		for (i = 0; i < length; i++) {
			if (i > 0) {
			}
			if ((*(word + i) < 96 && *(*(arr + y + i) + x) == *(word + i) + offset) || *(*(arr + y + i) + x) == *(word + i) || *(*(arr + y + i) + x) == *(word + i) - offset || *(*(arr + y + i) + x) == *(word + i) - offset + offset) { 
				continue;
			}
			break;
		}
		if (i == length) {
			printf("Word found: ");
			for (i = 0; i < length; i++) {
				printf("%c", *(word + i));
			}
			printf("\n");
			for (i = 0; i < length; i++) {
				if (*(*(arr + y + i) + x) < 96) {
					*(*(arr + y + i) + x) += offset;
				}
			} 
		}
	//Pings if there's room in the grid to search up 
	if (y - length >= -1) {
		int i = 0;
		for (i = 0; i < length; i++) {
			if (i > 0) {
			}
			if ((*(word + i) < 96 && *(*(arr + y - i) + x) == *(word + i) + offset) || *(*(arr + y - i) + x) == *(word + i) || *(*(arr + y - i) + x) == *(word + i) - offset || *(*(arr + y - i) + x) == *(word + i) - offset + offset) { 
				continue;
			}
			break;
		}
		if (i == length) {
			printf("Word found: ");
			for (i = 0; i < length; i++) {
				printf("%c", *(word + i));
			}
			printf("\n");
			for (i = 0; i < length; i++) {
				if (*(*(arr + y - i) + x) < 96) {
					*(*(arr + y - i) + x) += offset;
				}
			}
		}
		/// Pings if there's room in the grid to horiz
		if (x + length <= n) {
			int i = 0;
			for (i = 0; i < length; i++) {
				if (i > 0) {
				}
				if ((*(word + i) < 96 && *(*(arr + y - i) + x + i) == *(word + i) + offset) || *(*(arr + y - i) + x + i) == *(word + i) || *(*(arr + y - i) + x + i) == *(word + i) - offset || *(*(arr + y - i) + x + i) == *(word + i) - offset + offset) { 
					continue;
				}
				break;
			}
			if (i == length) {
				printf("Word found: ");
				for (i = 0; i < length; i++) {
					printf("%c", *(word + i));
				}
				printf("\n");
				for (i = 0; i < length; i++) {
					if (*(*(arr + y - i) + x + i) < 96) {
						*(*(arr + y - i) + x + i) += offset;
					}
				} 
			}
		}
	}
		//Pings if theres enough room in the grid to search horizontally
		if (x + length <= n) {
			int i = 0;
			for (i = 0; i < length; i++) {
				if (i > 0) {
				}
				if ((*(word + i) < 96 && *(*(arr + y + i) + x + i) == *(word + i) + offset) || *(*(arr + y + i) + x + i) == *(word + i) || *(*(arr + y + i) + x + i) == *(word + i) - offset || *(*(arr + y + i) + x + i) == *(word + i) - offset + offset) { 
					continue;
				}
				break;
			}
			if (i == length) {
				printf("Word found: ");
				for (i = 0; i < length; i++) {
					printf("%c", *(word + i));
				}
				printf("\n");
				for (i = 0; i < length; i++) {
					if (*(*(arr + y + i) + x + i) < 96) {
						*(*(arr + y + i) + x + i) += offset;
					}
				} 
			}
		}
	}
	
	/// Pings if theres enough room in grid to search horizontally
	if (x + length <= n) {
		int i = 0;
		for (i = 0; i < length; i++) {
			if (i > 0) {
			}
			if ((*(word + i) < 96 && *(*(arr + y) + x + i) == *(word + i) + offset) || *(*(arr + y) + x + i) == *(word + i) - offset  || *(*(arr + y) + x + i) == *(word + i) || *(*(arr + y) + x + i) == *(word + i) - offset + offset) { 
				continue;
			}
			return;
		}
		printf("Word found: ");
		for (i = 0; i < length; i++) {
			printf("%c", *(word + i));
		}
		printf("\n");
		for (i = 0; i < length; i++) {
			if (*(*(arr + y) + x + i) < 96) {
				*(*(arr + y) + x + i) += offset;
			}
		} 
	}
}
void searchPuzzle(char** arr, int n, char** list, int listSize) {
	// This function checks if arr contains words from list. If a word appears in arr, it will print out that word and then convert that word entry in arr into lower case.
	// Your implementation here
//function will go through entire grid and compare each letter with the first letter frmo word list then checkword will determine if a word is found
	
	int x = 0, y = 0, k = 0;
	for (x = 0; x < n; x++) { //left/right
		for (y = 0; y < n; y++) { // up/down 
			for (k = 0; k < listSize; k++) { // goes thru grid and compares first letter with first letter from list
				if (**(list + k) == *(*(arr + x) + y) || **(list + k) == *(*(arr + x) + y) - 32) { //goes thru each char in list and compares to grid
					int length = 0;
					for (int l = 0; *(*(list + k) + l) != (char)0; l++) {
						length++;
					}
					checkWord(arr, n, x, y, *(list + k), length);
				}
			}
		}	
	}
	return;
}
