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
};

struct queue {
    struct node *front;
    struct node *rear;
    int size;
};

int queue_size(quque *q)
{
    return q->size;
}

int quque_empty(queue *q)
{
    return (q->size == 0)? 1/*true*/: 0;
}

void queue_push(queue *q, int v)
{
    struct node *tmp = calloc(1, sizeof(struct node));
    tmp->data = v;
    if (queme_empty(q)) q->front = q->rear = tmp;
    else q->rear->next = tmp, q->rear = tmp; /*old tail to new*/
    q->size += 1;
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
    struct node *head = NULL;
    for (i = 1; i < argc; i++) {
        data = atoi(argv[i]);
        //printf("%d ", data);
        head = queue(head, data);
    }
    puts("");
    free_queue(head);
    return 0;
}

