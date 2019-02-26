#include"StackByTwoQueue.h"
#include"Stack.h"
void QStackInit(QStack* stq)
{
	QueueInit(&stq->q1);
	QueueInit(&stq->q2);
}
void QStackDestory(QStack* stq)
{
	QueueDestory(&stq->q1);
	QueueDestory(&stq->q2);
}
void QStackPush(QStack* stq, DataType x)
{
	assert(stq);
	if (QueueEmpty(&stq->q1) != 0)
	{
		QueuePush(&stq->q1, x);
	}
	else
	{
		QueuePush(&stq->q1, x);

	}
}
void QStackPop(QStack* stq)
{
	assert(stq);
	Queue* empty = &stq->q1, *nonempty = &stq->q2;
	if (QueueEmpty(&stq->q1) != 0)
	{
		empty = &stq->q2;
		nonempty = &stq->q1;
	}
	while (QueueSize(nonempty) > 1)
	{
		QueuePush(empty, QueueFront(nonempty));
		QueuePop(nonempty);
	}
	QueuePop(nonempty);
}

DataType QStackTop(QStack* stq)
{
	assert(stq);
	Queue* empty = &stq->q1, *nonempty = &stq->q2;
	if (QueueEmpty(&stq->q1) != 0)
	{
		empty = &stq->q2;
		nonempty = &stq->q1;
	}
	while (QueueSize(nonempty) > 1)
	{
		QueuePush(empty, QueueFront(nonempty));
		QueuePop(nonempty);
	}
	QueueFront(nonempty);
}
int QStackEmpty(QStack* stq)
{
	return QueueEmpty(&stq->q1) | QueueEmpty(&stq->q2);
}
int QStackSize(QStack* stq)
{
	return QueueSize(&stq->q1) + QueueSize(&stq->q2);
}

void TestQStack()
{
	QStack s;
	QStackInit(&s);

	QStackPush(&s, 1);
	QStackPush(&s, 2);
	QStackPush(&s, 3);
	QStackPush(&s, 4);

	while (QStackEmpty(&s))
	{
		printf("%d", QStackTop(&s));
		QStackPop(&s);
	}
}