/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#include <stdio.h>
#include <string.h>
char removeSpaces(char *str) {
	int index, j = 0;
	if (str == NULL || str == "")
		return '\0';
	else
	{
		for (index = 0; str[index] != '\0'; index++)
		{
			if (str[index] != ' ')
				str[j++] = str[index];
		}
		str[j] = '\0';
	}
}