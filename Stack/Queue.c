#include"Queue.h"


void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_front = NULL;
	pq->_back = NULL;
}
void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* next = NULL;
	QueueNode* cur = pq->_front;
	while (cur != NULL)
	{
		next = cur->_next;
		free(cur);

		cur = next;
	}
	pq->_back = pq->_front = NULL;
}
QueueNode* BuyQueueNode(DataType x)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	assert(node);

	node->_next = NULL;
	node->_data = x;

	return node;

}
void QueuePush(Queue* pq, DataType x)//队尾插入
{
	assert(pq);
	QueueNode* back = NULL;
	if (pq->_back == NULL)
	{
		pq->_front = pq->_back = BuyQueueNode(x);
	}
	else
	{
		back = BuyQueueNode(x);
		pq->_back->_next = back;
		pq->_back = back;
	}
}
void QueuePop(Queue* pq)//队头删除
{
	/*assert(pq);
	QueueNode* newnode = pq->_front;
	QueueNode* next = newnode->_next;
	free(pq->_front);
	pq->_front = next;*/
	QueueNode* cur = NULL;
	assert(pq);
	if (pq->_front == NULL)
		return;
	cur = pq->_front->_next; //先将下一个节点保存，在free front,防止内存泄漏
	free(pq->_front);
	pq->_front = cur;
	if (cur == NULL)
	{
		pq->_back = NULL;
	}
}
DataType QueueFront(Queue* pq)
{
	assert(pq);
	QueueNode* node = pq->_front;
	//assert(node != 0x1);

	return node->_data;//
}
int QueueEmpty(Queue* pq)//
{
	assert(pq);
	if (pq->_front == NULL)
		return 0;
	else
		return 1;
	//return pq->_front = NULL ? 0 : 1;//出现异常
}
int QueueSize(Queue* pq)
{
	int size = 0;
	QueueNode* cur = pq->_front;
	while (cur != NULL)
	{
		size++;
		cur = cur->_next;
	}
	return size;
}
void TestQueue()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	while (QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	QueueDestory(&q);
}