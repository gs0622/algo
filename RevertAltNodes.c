/*
Given a linked list, reverse alternate nodes and append them to end of list. Extra allowed space is O(1) 
Examples

Input List:  1->2->3->4->5->6
Output List: 1->3->5->6->4->2

Input List:  12->14->16->18->20
Output List: 12->16->20->18->14
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    int data;
    struct node *next;
} node;

struct queue {
    struct node *front;
    struct node *rear;
    int size;
};

struct stack {
    struct node *top;
    int size;
};

int queue_size(struct queue *q)
{
    return q->size;
}

int queue_empty(struct queue *q)
{
    return (0 == q->size)? 1/*true*/: 0;
}

void queue_push(struct queue *q, int v)
{
    struct node *tmp = calloc(1, sizeof(struct node));
    tmp->data = v;
	//printf("qi:%d-> ", v);
    if (queue_empty(q)) q->front = q->rear = tmp;
    else q->rear->next = tmp, q->rear = tmp; /*old tail to new*/
    q->size += 1;
}

int queue_pop(struct queue *q, int *p)
{
	struct node *tmp;
	if (queue_empty(q)) return -1;
	tmp = q->front;
	if (1 == q->size) q->front = q->rear = NULL;
	else q->front = q->front->next;
	//printf("qo:%d-> ", tmp->data);
	*p = tmp->data;
	q->size -= 1;
	free(tmp);
	return 0;
}

void queue_show(struct queue *q)
{
    struct node *p = q->front;
    for (p = q->front; ; p = p->next) {
        printf("%d%s", p->data, p->next? " ": "");
        if (!p->next) break;
    }
    puts("");
}

int stack_size(struct stack *s)
{
    return s->size;
}

int stack_empty(struct stack *s)
{
    return (0 == s->size)? 1/*true*/: 0;
}

void stack_push(struct stack *s, int v)
{
    struct node *tmp = calloc(1, sizeof(struct node));
	//printf("si:%d-> ", v);
    tmp->data = v, tmp->next = s->top;
    s->top = tmp, s->size += 1;
}

int stack_pop(struct stack *s, int *p)
{
    struct node *tmp;
    if (stack_empty(s)) return -1;
    tmp = s->top;
	//printf("so:%d-> ", tmp->data);
    *p = tmp->data;
    s->top = tmp->next, s->size -= 1;
    free(tmp);
    return 0;
}

struct node *queue(struct node *head, int data)
{
    struct node *cur, *last, *tmp = calloc(1, sizeof(struct node));
    assert(tmp);
    tmp->data = data;
    if (NULL == head)
        head = tmp;
    else {
        cur = last = head;
        while (cur->next) last = cur, cur = cur->next;
        cur->next = tmp;
    }
    printf("q:%d-> ", data);
    return head;
}

void free_queue(struct node *head)
{
    struct node *cur = head;
    while (head) {
        printf("f:%d%s", head->data, head->next? "-> ": "\n");
        head = head->next, free(cur), cur = head;
    }
}

int main(int argc, char **argv)
{
    int i, data;
	struct queue q = {};
	struct queue r = {};
	struct stack s = {};
    for (i = 1; i < argc; i++) {
        data = atoi(argv[i]);
		queue_push(&q, data);
    }
    while (!queue_empty(&q)) {
        queue_pop(&q, &data);
        queue_push(&r, data);
        if (0 == queue_pop(&q, &data))
            stack_push(&s, data);
    }
    while (!stack_empty(&s)) {
        stack_pop(&s, &data);
        queue_push(&r, data);
    }
    //free_queue(head);
    queue_show(&r);
	while (!queue_empty(&r)) queue_pop(&r, &data);
    return 0;
}

