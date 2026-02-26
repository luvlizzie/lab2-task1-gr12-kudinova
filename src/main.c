/*
 * Author: Kudinova Elizaveta, group 12
 */

#include <stdio.h>
#include <stdlib.h>

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
 * Main function for testing is_palindrome
 */
int main() {
		// Тест функции на нескольких числах
		int test_numbers[] = {121, 123, 454, 789, 999, 12321};
		int test_size = 6;

		printf("Testing is_palindrome function:\n");
		for (int i = 0; i < test_size; i++) {
				printf("%d is %s\n", 
							 test_numbers[i], 
							 is_palindrome(test_numbers[i]) ? "palindrome" : "not palindrome");
		}

		return 0;
}