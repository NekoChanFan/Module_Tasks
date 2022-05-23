#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct BigNumber {
	short* num;
	int size;
};

struct BigNumber* MemConstructor(char* _num)
{
	struct BigNumber* obj = malloc(sizeof(struct BigNumber));
	if (!obj)
		return NULL;
	int size = strlen(_num);
	obj->num = malloc(size * sizeof(short));
	if (!obj->num)
	{
		perror("ERROR");
		free(obj);
		return NULL;
	}

	obj->size = size;

	for (int i = 0; i < obj->size; ++i)
		obj->num[i] = _num[i] - 48;


	return obj;
}

int PrintBigNumber(struct BigNumber* obj)
{
	for (int i = 0; i < obj->size; i++)
	{
		printf("%hi", obj->num[i]);
	}
	printf("\n");
	return 0;
}

int BigNumberSum(struct BigNumber* obj1, struct BigNumber* obj2) 
{
	int SizeMax = 0;
	if (obj1->size > obj2->size)
		SizeMax = obj1->size;
	else
		SizeMax = obj2->size;

	struct BigNumber* res = malloc(sizeof(struct BigNumber));
	res->size = SizeMax + 1;
	res->num = malloc(res->size * sizeof(short));
	for (int i = 0; i < res->size; ++i)
	{
		res->num[i] = 0;
	}


	int temp = 0;
	int i = 0;
	for (; i < min(obj1->size, obj2->size); i++)
	{
		res->num[res->size - i - 1] += temp;

		temp = 0;
		if (res->num[res->size - i - 1] + obj1->num[obj1->size - i - 1] + obj2->num[obj2->size - i - 1] < 10)
			res->num[res->size - i - 1] += obj1->num[obj1->size - i - 1] + obj2->num[obj2->size - i - 1];
		else
		{
			temp = 1;
			res->num[res->size - i - 1] = (res->num[res->size - i - 1] + obj1->num[obj1->size - i - 1] + obj2->num[obj2->size - i - 1]) % 10;
		}
	}

	if (temp)
		res->num[res->size - i - 1] += temp;
	if (obj1->size != obj2->size)
	{
		for (int j = i; j < (max(obj1->size, obj2->size)); j++)
		{
			if (obj1->size > obj2->size)
				res->num[res->size - j - 1] += obj1->num[obj1->size - j - 1];
			else
				res->num[res->size - j - 1] += obj2->num[obj2->size - j - 1];

		}
	}

	struct BigNumber* buff = NULL;
	if (res->num[0] == 0)
	{
		buff = malloc(sizeof(struct BigNumber));
		buff->size = SizeMax;
		buff->num = malloc(buff->size * sizeof(short));
		int i = 1;
		int j = 0;
		for (; i < res->size; i++, j++)
		{
			buff->num[j] = res->num[i];
		}
		free(res);
		return buff;
	}
	return res;
}
