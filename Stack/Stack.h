#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int DataType;
//�Ѷ�ջ���������һ�˳�Ϊջ������һ�˳�Ϊջ��
//#define N 10;
//typedef struct stack
//{
//	DataType* _a[N];
//	int _top;//ջ��
//
//}Stack;
//˳��ջ��˳������ݳ�Ա��ͬ
//��֮ͬ����˳��ջ����ջ�ͳ�ջ����ֻ�����Ե�ǰջ�����в�����
//˳��ջ
typedef struct stack
{
	DataType* _a;
	int _top;//ջ��
	int _capacity;//����
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);

void StackPush(Stack* ps, DataType x);
void StackPop(Stack* ps);
DataType StackTop(Stack* ps);
int StackEmpty(Stack* ps);
int StackSize(Stack* ps);