#pragma once
#include <stdlib.h>

//����������� ������ ��� ������� �����. _num - ����� � ���� ������
struct BigNumber* MemConstructor(char* _num);

//����� ����� ���� BigNumber � �������
int PrintBigNumber(struct BigNumber* obj);

//����� ���� ����� BigNumber
int BigNumberSum(struct BigNumber* obj1, struct BigNumber* obj2);