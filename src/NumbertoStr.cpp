/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int converter(int num, char str[], int deci, int flag)
{
	int i = 0;
	int j, k = 0, temp = 0;
	while (num)
	{
		str[i] = (num % 10) + '0';
		num =num / 10;
		i++;
	} 
	if (flag && deci == 0)
	{
		str[i] = '-';
		i = i + 1;
	}
	while (i < deci)
		str[i++] = '0';
	//reverse(str,i);
	j = i - 1;
	while (k<j)
	{
		temp = str[k];
		str[k] = str[j];
		str[j] = temp;
		k++;
		j--;
	}
	str[i] = '\0';
	return i;
}
void number_to_str(float number, char *str,int afterdecimal){
	int flag = 0;
	float n;
	if (number<0)
	{
		n = -number;
		flag = 1;
	}
	else
		n = number;
	int ipart = (int)n,i_fpart;
	float fpart = n - (float)ipart; 
	int i = converter(ipart, str, 0, flag);
	if (afterdecimal != 0)
	{
		str[i] = '.';
		fpart = fpart * pow(10.0, afterdecimal);
		i_fpart = (int)fpart;
		converter(i_fpart, str + i + 1, afterdecimal, flag);
	}
}