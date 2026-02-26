/*
 * Author: Kudinova Elizaveta, group 12
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Function: is_palindrome
 * ------------------------
 *   number: natural number to check
 *   
 *   returns: 1 if number is palindrome, 0 otherwise
 */
int is_palindrome(int number) {
		int original = number;
		int reversed = 0;
		int digit;

		while (number > 0) {
				digit = number % 10;
				reversed = reversed * 10 + digit;
				number = number / 10;
		}

		return (original == reversed);
}

/*
 * Function: fill_array_random
 * ----------------------------
 *   array: array to fill
 *   size: size of the array
 *   
 *   fills array with random numbers from 1 to 999
 */
void fill_array_random(int array[], int size) {
		for (int i = 0; i < size; i++) {
				array[i] = rand() % 998 + 1;  // random numbers from 1 to 999
		}
}

/*
 * Function: print_array
 * ----------------------
 *   array: array to print
 *   size: size of the array
 *   
 *   prints array elements in one line
 */
void print_array(int array[], int size) {
		printf("Array: ");
		for (int i = 0; i < size; i++) {
				printf("%d ", array[i]);
		}
		printf("\n");
}

/*
 * Function: count_palindromes
 * ----------------------------
 *   array: array to process
 *   size: size of the array
 *   
 *   returns: number of palindrome numbers in the array
 */
int count_palindromes(int array[], int size) {
		int count = 0;

		for (int i = 0; i < size; i++) {
				if (is_palindrome(array[i])) {
						count++;
				}
		}

		return count;
}

/*
 * Main function
 */
int main(int argc, char *argv[]) {
		// Check command line arguments
		if (argc != 2) {
				printf("Usage: %s <array_size>\n", argv[0]);
				printf("Example: %s 10\n", argv[0]);
				return 1;
		}

		// Get array size from command line
		int size = atoi(argv[1]);

		if (size <= 0) {
				printf("Error: array size must be positive\n");
				return 1;
		}

		if (size > 100) {
				printf("Error: array size too large (max 100)\n");
				return 1;
		}

		// Initialize random seed
		srand(time(NULL));

		// Create and fill array
		int array[100];  // maximum size 100
		fill_array_random(array, size);

		// Print original array
		printf("Original ");
		print_array(array, size);

		// Count palindromes
		int palindrome_count = count_palindromes(array, size);

		// Print result
		printf("Number of palindrome numbers: %d\n", palindrome_count);

		return 0;
}