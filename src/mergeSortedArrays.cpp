/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int datecode_struct(char *date)
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

int equal_struct(struct transaction *a, struct transaction *b)
{
	int a_date = datecode_struct(a->date);
	int b_date = datecode_struct(b->date);
	if (a_date == b_date)
		return 0;
	else if (a_date > b_date)
		return 1;
	else
		return -1;
}


struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) 
{
	if ((A == NULL) || (B == NULL))
		return NULL;
	int len = ALen + BLen;
	struct transaction *result = (struct transaction *)malloc(sizeof(struct transaction) * len);
	int i = 0, j = 0, k = 0, is_equal;

	while (i<ALen && j<BLen)
	{
		is_equal = equal_struct(&A[i], &B[j]);
		if (is_equal == 0)
		{
			result[k++] = A[i];
			result[k] = B[j];
			i++;
			j++;
		}
		else if (is_equal == 1)
		{
			result[k] = B[j];
			j++;
		}
		else
		{
			result[k] = A[i];
			i++;
		}
		k++;
	}
	while (i<ALen)
	{
		result[k] = A[i];
		k++;
		i++;
	}
	while (j<BLen)
	{
		result[k] = B[j];
		k++;
		j++;
	}
	if (k>0)
		return result;
	return NULL;
}