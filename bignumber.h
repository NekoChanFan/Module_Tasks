#pragma once
#include <stdlib.h>

//Конструктор памяти для больших чисел. _num - число в виде строки
struct BigNumber* MemConstructor(char* _num);

//Вывод числа типа BigNumber в консоль
int PrintBigNumber(struct BigNumber* obj);

//Сумма двух чисел BigNumber
int BigNumberSum(struct BigNumber* obj1, struct BigNumber* obj2);