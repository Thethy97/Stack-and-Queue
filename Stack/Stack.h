#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int DataType;
//把对栈进行运算的一端称为栈顶，另一端称为栈底
//#define N 10;
//typedef struct stack
//{
//	DataType* _a[N];
//	int _top;//栈顶
//
//}Stack;
//顺序栈和顺序表数据成员相同
//不同之处：顺序栈的入栈和出栈操作只允许对当前栈顶进行操作。
//顺序栈
//后进先出
typedef struct stack
{
	DataType* _a;
	int _top;//栈顶
	int _capacity;//容量
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);

void StackPush(Stack* ps, DataType x);
void StackPop(Stack* ps);
DataType StackTop(Stack* ps);
int StackEmpty(Stack* ps);
int StackSize(Stack* ps);
void TestStack();
