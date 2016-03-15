/*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
#include <stdio.h>
#include<string.h>
char KthIndexFromEnd(char *str, int K) {
	if (str==""||str==NULL)
		return '\0';
	int len = strlen(str);
	int position = len - 1 - K;
	char kth_char = str[position];
	return(kth_char);
}