/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include <stdlib.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int agecode(char *date)
{
	int agevalue = 0, i = 0;
	int a[] = { 10, 100, 10000 };
	while (*date)
	{
		agevalue += (strtol(date, &date, 10)*a[i++]);
		date++;
	}
	return agevalue;
}

int countGreaterNumbers(struct transaction *Arr, int len, char *date) 
{
	int i = 0, count = 0;
	int date_age = agecode(date);
	for (i = 0; i < len; i++)
	{
		if (agecode(Arr[i].date) > date_age)
		{
			count++;
		}
	}
	return count;
}
