#pragma once

#include"Stack.h"
typedef struct SQueue
{
	Stack s1;
	Stack s2;
}SQueue;


void SQueueInit(SQueue* pq);
void SQueueDestory(SQueue* pq);

void SQueuePush(SQueue* pq, DataType x);
void SQueuePop(SQueue* pq);
DataType SQueueFront(SQueue* pq);
int SQueueEmpty(SQueue* pq);
int SQueueSize(SQueue* pq);

void TestSQueue();

