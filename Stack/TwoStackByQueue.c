#include"TwoStackByQueue.h"
#include"Stack.h"

void SQueueInit(SQueue* pq)
{
	Stack *p1, *p2;
	p1 = &(pq->s1);
	p2 = &(pq->s2);
	StackInit(p1);
	StackInit(p2);
}
void SQueueDestory(SQueue* pq)
{
	Stack *p1, *p2;
	p1 = &(pq->s1);
	p2 = &(pq->s2);
	StackDestory(p1);
	StackDestory(p2);
}
void SQueuePush(SQueue* pq, DataType x)
{
	assert(pq);
	Stack *p1, *p2;
	p1 = &(pq->s1);
	p2 = &(pq->s2);
	StackPush(p1,x);
}
void SQueuePop(SQueue* pq)
{
	int i = 0;
	assert(pq);
	Stack *p1, *p2;
	
	p1 = &(pq->s1);
	p2 = &(pq->s2);
	while (StackEmpty(p1))
	{
		i = StackTop(p1);
		StackPush(p2,i);
		StackPop(p1);
	}
	StackPop(p2);
}

DataType SQueueFront(SQueue* pq)
{
	assert(pq);
	Stack *p2;

	p2 = &(pq->s2);
	return StackTop(p2);
}
int SQueueEmpty(SQueue* pq)
{
	assert(pq);
	Stack *p1, *p2;

	p1 = &(pq->s1);
	p2 = &(pq->s2);

	if (StackEmpty(p1) && StackEmpty(p2))
		return 0;
	else
		return 1;
}
int SQueueSize(SQueue* pq)
{
	assert(pq);
	Stack *p1, *p2;

	p1 = &(pq->s1);
	p2 = &(pq->s2);

	return StackSize(p1) + StackSize(p2);
}

void TestSQueue()
{
	SQueue q;
	SQueueInit(&q);

	SQueuePush(&q, 1);
	SQueuePush(&q, 2);
	SQueuePush(&q, 3);
	SQueuePush(&q, 4);

	while (SQueueEmpty(&q))
	{
		printf("%d ", SQueueFront(&q));
		SQueuePop(&q);
	}
	SQueueDestory(&q);
}
