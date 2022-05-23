#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "bignumber.h"

struct BigNumber {
	short* num;
	int size;
};

int first()
{
	int sum = 0;
	for (int i = 3; i < 1000; ++i)
	{
		if (i % 3 == 0 || i % 5 == 0)
			sum += i;
	}
	return sum;
}

unsigned long Fib(int i)
{
	int a = 0, b = 1;
	while (i)
	{
		int c = a;
		a = a + b;
		b = c;
		--i;
	}
	return a;
}

unsigned long second()
{
	unsigned long sum = 0;
	for (int i = 0; Fib(i) <= 4000000; ++i)
	{
		if (Fib(i) % 2 == 0)
			sum += Fib(i);
	}
	return sum;
}

unsigned long long task_3(unsigned long long number)
{
	unsigned long long div = 2;
	while (number != 1)
	{
		while (number % div == 0)
			number /= div;
		++div;
	}
	return div - 1;
}

int reverse(int num)
{
	int tmp = num, n = 0;
	while (tmp)
	{
		tmp /= 10;
		n++;
	}
	int rnum = 0, q = pow(10, n - 1);
	while (num)
	{
		rnum = rnum + num % 10 * q;
		num = num / 10;
		q /= 10;
	}

	return rnum;
}

long task_4()
{
	long max = 0;
	for (int i = 0; i < 1000; ++i)
	{
		for (int j = 0; j < 1000; ++j)
		{
			if (i * j == reverse(i * j) && i * j > max)
				max = i * j;
		}
	}

	return max;
}

long task_5()
{
	long result = 2;
	while (1)
	{
		int flag = 1;
		for (int i = 1; flag && i <= 20; ++i)
		{
			if (result % i)
				flag = 0;
		}
		if (flag)
			break;
		result += 2;
	}
	return result;
}

unsigned long long task_6()
{
	unsigned long long sumSquared = 0;
	for (int i = 0; i <= 100; ++i)
		sumSquared += i;
	sumSquared *= sumSquared;

	unsigned long long sumOfSquares = 0;
	for (int i = 0; i <= 100; ++i)
		sumOfSquares += i * i;

	return sumSquared - sumOfSquares;

}

unsigned long long task_7()
{
	unsigned long long prime = 0;
	int n = 1;
	unsigned long long tmp = 2;
	while (n <= 10001)
	{
		unsigned long long i = 2;
		for (; i < tmp; ++i)
		{
			if (tmp % i == 0)
				break;
		}
		if (i == tmp)
		{
			prime = tmp;
			++n;
		}
		tmp++;
	}
	return prime;
}

unsigned long long task_8(char* number)
{
	unsigned long long max = 0;
	for (int i = 0; number[i + 13] != 0; ++i)
	{
		unsigned long long temp = 1;
		for (int j = i; j < i + 13; ++j)
		{
			temp *= number[j] - 48;
		}
		if (temp > max)
			max = temp;
	}


	return max;
}

unsigned long task_9()
{
	for (int i = 1; i <= 1000; ++i)
	{
		for (int j = i + 1; j <= 1000; ++i)
		{
			for (int k = j + 1; k <= 1000; ++k)
			{
				if (i + j + k == 1000 && i * i + j * j == k * k)
					return i * j * k;
			}
		}
	}
	return 0;
}



unsigned long long task_10()
{
	unsigned long long sum = 5;
	int limit = 2000000;
	for (int i = 5; i <= limit; i += 2)
	{
		int div = 2; int f = 1;
		for(; div < (int)sqrt(i)+1; ++div)
			if (i % div == 0) { f = 0; break; }

		if (f) { sum += i; }
	}
	return sum;
}



int task_11()
{
	int grid[20][20] = {
		 8,2,22,97,38,15,0,40,00,75,4,5,7,78,52,12,50,77,91,8,
		 49,49,99,40,17,81,18,57,60,87,17,40,98,43,69,48,04,56,62,00,
		 81,49,31,73,55,79,14,29,93,71,40,67,53,88,30,03,49,13,36,65,
		 52,70,95,23,04,60,11,42,69,24,68,56,01,32,56,71,37,02,36,91,
		 22,31,16,71,51,67,63,89,41,92,36,54,22,40,40,28,66,33,13,80,
		 24,47,32,60,99,03,45,02,44,75,33,53,78,36,84,20,35,17,12,50,
		 32,98,81,28,64,23,67,10,26,38,40,67,59,54,70,66,18,38,64,70,
		 67,26,20,68,02,62,12,20,95,63,94,39,63,8,40,91,66,49,94,21,
		 24,55,58,05,66,73,99,26,97,17,78,78,96,83,14,88,34,89,63,72,
		 21,36,23,9,75,00,76,44,20,45,35,14,00,61,33,97,34,31,33,95,
		 78,17,53,28,22,75,31,67,15,94,03,80,04,62,16,14,9,53,56,92,
		 16,39,05,42,96,35,31,47,55,58,88,24,00,17,54,24,36,29,85,57,
		 86,56,00,48,35,71,89,07,05,44,44,37,44,60,21,58,51,54,17,58,
		 19,80,81,68,05,94,47,69,28,73,92,13,86,52,17,77,04,89,55,40,
		 04,52,8,83,97,35,99,16,07,97,57,32,16,26,26,79,33,27,98,66,
		 88,36,68,87,57,62,20,72,03,46,33,67,46,55,12,32,63,93,53,69,
		 04,42,16,73,38,25,39,11,24,94,72,18,8,46,29,32,40,62,76,36,
		 20,69,36,41,72,30,23,88,34,62,99,69,82,67,59,85,74,04,36,16,
		 20,73,35,29,78,31,90,01,74,31,49,71,48,86,81,16,23,57,05,54,
	};
	int mult = 0;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			int vert = 0, horz = 0, diagl = 0, diagr = 0;
			if (j < 17)
			{
				horz = grid[i][j] * grid[i][j + 1] * grid[i][j + 2] * grid[i][j + 3];
			}
			if (i < 17)
			{
				vert = grid[i][j] * grid[i + 1][j] * grid[i + 2][j] * grid[i + 3][j];
			}
			if (i < 17 && j < 17)
			{
				diagr = grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j + 2] * grid[i + 3][j + 3];
			}
			if (i > 3 && i < 17 && j > 3)
			{
				diagl = grid[i][j] * grid[i + 1][j - 1] * grid[i + 2][j - 2] * grid[i + 3][j - 3];
			}
			mult = max(mult, max(horz, max(vert, max(diagr, diagl))));
		}
	}

	return mult;

}

void ex_13()
{
	FILE* F = NULL;
	fopen_s(&F, "13.txt", "r");
	char BillKitches[51] = {0};
	struct BigNumber* x = NULL;
	struct BigNumber* y = NULL;
	x = MemConstructor("0");
	for (int i = 0; i < 100; i++)
	{
		fscanf_s(F, "%s", BillKitches, 51);
		y = MemConstructor(BillKitches);
		x = BigNumberSum(x, y);

	}

	for (int i = 0; i < 10; ++i)
	{
		printf("%d", x->num[i]);
	}
}

int CountDiv(long long int num)
{
	long int div = 2;
	int DivCount = 2;
	for (; div <= sqrt(num); div++)
	{
		if (num % div == 0)
		{
			DivCount += 2;
		}
	}

	if (div * div == num)
		DivCount++;

	return DivCount;
}


long long TriangNum(int number)
{
	long long n = 0;
	for (int i = 0; i <= number; i++)
	{
		n += i;
	}

	return n;
}

long long int ex_12()
{
	int f = 1;
	long long int res = 0;
	for (int i = 1; f; i++)
	{
		long long int res = TriangNum(i);
		if (CountDiv(res) >= 500)
		{
			return res;
			f = 0;
		}
	}
	return 0;
}

unsigned long long ex_14()
{
	unsigned long long number = 0;
	int length = 0;

	unsigned long long MaxSeqStart = 0;
	int maxLength = 0;

	for (int i = 999999; i > 1; i--)
	{
		number = i;
		length = 1;

		while (number != 1)
		{
			if (number % 2 == 0)
				number /= 2;
			else
				number = number * 3 + 1;

			length++;
		}

		if (maxLength < length)
		{
			MaxSeqStart = i;
			maxLength = length;
		}
	}
	return MaxSeqStart;
}

unsigned long long ex_15()
{
	unsigned long long grid[21][21] = { 0 };
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			if (i == 0 || j == 0)
				grid[i][j] = 1;
		}
	}

	for (int i = 1; i < 21; i++)
	{
		for (int j = 1; j < 21; j++)
		{
			grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
		}
	}

	return grid[20][20];
}


int brackets(char* str, int len)
{
	int Bracket = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '(')
			Bracket++;
		if (str[i] == ')')
			Bracket--;
		if (Bracket < 0)
			return i;

	}
	if (Bracket > 0)
		return -1;
	else
		return 0;
}


int comparedates(char* date1, char* date2)
{
	int i = 6;
	for (; i < 10 && date1[i] && date1[i] == date2[i]; ++i);
	if (date1[i] < date2[i])
		return -1;
	else if (date2[i] < date1[i])
		return 1;

	for (i = 3; i < 5 && date1[i] == date2[i]; ++i);
	if (date1[i] < date2[i])
		return -1;
	else if (date2[i] < date1[i])
		return 1;

	for (i = 0; i < 2 && date1[i] == date2[i]; ++i);
	if (date1[i] < date2[i])
		return -1;
	else if (date2[i] < date1[i])
		return 1;

	return 0;
}

void Sort(FILE* f, FILE* newF)
{
	int pos;
	char temp[12] = { 0 };
	char max[12] = { 0 };
	while (fscanf(f, "%s", temp) != EOF)
	{
		printf("%s", temp);
		for (int i = 0; i < 12; i++)
		{
			max[i] = 0;
		}
		do {
			if (comparedates(temp, max) >= 0)
			{
				for (int i = 0; i < 12; i++)
					max[i] = temp[i];
				pos = ftell(f) - 10;
			}
		} while (fscanf(f, "%s", temp) != EOF);

		fprintf(newF, "%s ", max);

		fseek(f, pos, SEEK_SET);
		for (int i = 0; i < strlen(max); i++)
			fprintf(f, " ");


		rewind(f);
	}
}
