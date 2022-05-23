#pragma once
#include <stdlib.h>
#include <stdio.h>
/*
Функции являются ответами на соответствующие задания проекта эйлера
*/

int first();

unsigned long second();

unsigned long long task_3(unsigned long long number);

long task_4();

long task_5();

unsigned long long task_6();

unsigned long long task_7();

unsigned long long task_8(char* number);

unsigned long task_9();

unsigned long long task_10();

int task_11();

long long int ex_12();

void ex_13();

unsigned long long ex_14();

unsigned long long ex_15();

/////////////////////////Функция для задания со скобками/////////////////////////////////

int brackets(char* str, int len);


////////////////////////////Cортировка дат////////////////////////////////////////////

/*
Сортирует файл с датами формата дд/мм/гггг. Записывает результат в newfile.
*/
void Sort(FILE* f, FILE* newF);