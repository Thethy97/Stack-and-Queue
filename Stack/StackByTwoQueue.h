#pragma once
//两个队列形成一个栈

#include"Queue.h"

typedef struct QStack
{
	Queue q1;
	Queue q2;
}QStack;

void QStackInit(QStack* stq);
void QStackDestory(QStack* stq);
void QStackPush(QStack* stp,DataType x);
void QStackPop(QStack* stq);
DataType QStackTop(QStack* stq);
int QStackEmpty(QStack* stq);
int QStackSize(QStack* stq);
void TestQstack();
