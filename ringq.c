#include <stdio.h>
#include <assert.h>
#define MAX 8
struct queue {
	int data[MAX];
	int front, rear;
};
void init(struct queue *q)
{
	int i;
	q->front = q->rear = 0;
	for (i = 0; i < MAX; i += 1) q->data[i] = -1;
}
int size(struct queue *q)
{
	return (q->rear - q->front)%MAX;
}
int front(struct queue *q) { return q->data[q->front]; }
void enqueue(struct queue *q, int data)
{
	printf("e: %d %d %d\n", q->front, q->rear, (q->front - 1) % MAX);
	if (q->front == (q->rear + 1) % MAX) assert(0); /*full*/
	q->data[q->rear] = data;
	q->rear = (q->rear + 1) % MAX;
}
void dequeue(struct queue *q)
{
	if (q->front == q->rear) assert(0); /*empty*/
	q->data[q->front];
	q->front = (q->front + 1) % MAX;
}
int main(void)
{
	int i;
	struct queue q;
	init(&q);
	enqueue(&q, 1);
	printf("%d\n", front(&q));
	enqueue(&q, 2);
	printf("%d\n", front(&q));
	enqueue(&q, 3);
	printf("%d\n", front(&q));
	dequeue(&q);
	printf("%d\n", front(&q));
	//init(&q);
	for (i = 0; ; i += 1)
		enqueue(&q, i);
}
