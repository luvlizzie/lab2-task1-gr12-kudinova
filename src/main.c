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
 * Main function for testing fill_array_random and print_array
 */
int main() {
		// Тест is_palindrome
		int test_numbers[] = {121, 123, 454, 789, 999, 12321};
		int test_size = 6;

		printf("Testing is_palindrome function:\n");
		for (int i = 0; i < test_size; i++) {
				printf("%d is %s\n", 
							 test_numbers[i], 
							 is_palindrome(test_numbers[i]) ? "palindrome" : "not palindrome");
		}

		// Тест fill_array_random и print_array
		printf("\nTesting array functions:\n");
		int array[10];
		fill_array_random(array, 10);
		print_array(array, 10);

		return 0;
}