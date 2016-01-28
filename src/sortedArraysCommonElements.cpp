/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int datecode(char *date)
{
	int agevalue = 0, i = 0;
	int a[3] = { 10, 100, 10000 };
	while (*date)
	{
		agevalue += (strtol(date, &date, 10)*a[i++]);
		date++;
	}
	return agevalue;
}

int equal(struct transaction *a, struct transaction *b)
{
	int a_date = datecode(a->date);
	int b_date = datecode(b->date);
	if (a_date == b_date)
		return 0;
	else if (a_date > b_date)
		return 1;
	else
		return -1;
}

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) 
{
	if ((A == NULL) || (B == NULL))
		return NULL;
	struct transaction *result = (struct transaction *)malloc(sizeof(struct transaction) * ALen);
	int i = 0, j = 0, k = 0, is_equal;

	while (i<ALen && j<BLen)
	{
		is_equal = equal(&A[i], &B[j]);
		if (is_equal == 0)
		{
			result[k] = A[i];
			i++;
			j++;
			k++;
		}
		else if (is_equal == 1)
		{
			j++;
		}
		else
		{
			i++;
		}
	}
	if (k>0)
		return result;
	return NULL;
}