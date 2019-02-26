#include"TwoStackByQueue.h"
#include"Stack.h"

void SQueueInit(SQueue* pq)
{

	StackInit(&pq->s1);
	StackInit(&pq->s2);
}
void SQueueDestory(SQueue* pq)
{
	StackDestory(&pq->s1);
	StackDestory(&pq->s2);
}
void SQueuePush(SQueue* pq, DataType x)
{

	//assert(pq);
	//Stack *p1, *p2;
	//p1 = &(pq->s1);
	//p2 = &(pq->s2);
	StackPush(&(pq->s1),x);
}
void SQueuePop(SQueue* pq)
{
	int i = 0;
	assert(pq);
	if (StackEmpty(&pq->s2) == 0)
	{
		while (StackEmpty(&pq->s1))
		{
			i = StackTop(&pq->s1);
			StackPush(&pq->s2, i);
			StackPop(&pq->s1);
		}
	}
	StackPop(&pq->s2);
}

DataType SQueueFront(SQueue* pq)
{
	assert(pq);
	int i = 0;
	if (StackEmpty(&pq->s2) == 0)
	{
		while (StackEmpty(&pq->s1))
		{
			i = StackTop(&pq->s1);
			StackPush(&pq->s2, i);
			StackPop(&pq->s1);
		}
	}
	StackTop(&pq->s2);
}
int SQueueEmpty(SQueue* pq)
{
	return StackEmpty(&pq->s1) | StackEmpty(&pq->s2);
}
int SQueueSize(SQueue* pq)
{
	return StackSize(&pq->s1) + StackSize(&pq->s2);
}

void TestSQueue()
{
	SQueue q;
	SQueueInit(&q);

	SQueuePush(&q, 1);
	SQueuePush(&q, 2);
	//SQueuePush(&q, 3);
	/*SQueuePush(&q, 4);*/

	//SQueuePop(&q);
	//SQueuePop(&q);

	SQueuePush(&q, 5);
	SQueuePush(&q, 6);
	while (SQueueEmpty(&q))
	{
		printf("%d ", SQueueFront(&q));
		SQueuePop(&q);
	}
	//SQueueDestory(&q);
}
