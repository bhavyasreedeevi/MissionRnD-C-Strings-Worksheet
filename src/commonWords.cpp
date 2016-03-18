/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include<string.h>
#include <malloc.h>
#define SIZE 31
char ** commonWords(char *str1, char *str2)
{
	if (str1 == NULL || str2 == NULL || str1 == '\0' || str2 == '\0')
		return NULL;
	else{
		char **common = (char **)malloc(SIZE* sizeof(char *));
		char **set1 = (char **)malloc(SIZE* sizeof(char *));
		char **set2 = (char **)malloc(SIZE* sizeof(char *));
		 int len1, len2;
		int  rows1=0, rows2=0, j=0, x=0, y = 0;
		len1 = strlen(str1);
		len2 = strlen(str2);
		for (int i = 0; i < SIZE; i++)
		{
			common[i] = (char *)malloc(SIZE * sizeof(char));
			set1[i] = (char *)malloc(SIZE * sizeof(char));
			set2[i] = (char *)malloc(SIZE * sizeof(char));
		}
		for (int i = 0; i < len2; i++)
		{
			for ( j = 0; str2[i] != ' '; j++, i++)
			{
				set2[rows2][j] = str2[i]; y++;
			}
			if (y!=0)
			{
				set2[rows2][j] = '\0';
				rows2++;
			}
		}

		rows1 = 0;
		for (int i = 0; i < len1; i++)
		{
			y = 0;
			for ( j = 0; str1[i] != ' '; j++)
			{
				set1[rows1][j] = str1[i]; y++;
				i++;
			}
			if (y)
			{

				set1[rows1][j] = '\0';

				rows1++;
			}
		}
		x = 0;
		for (int i = 0; i < rows1; i++)
		{

			for ( j = 0; j < rows2; j++)
			{

				if (!strcmp(set1[i], set2[j]))
				{
					strcpy(common[x++], set2[j]);
				}
			}
		}
		if (x == 0) return NULL;
		return common;
	}
}