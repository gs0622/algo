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
#include <stdarg.h>
#include <assert.h>

struct node {
    int data;
    struct node *next;
};

#define dprintf(...)    printf(__VA_ARGS__)

void queue(struct node *head, int data)
{
    struct node *last = head, *cur = calloc(1, sizeof(struct node));
    assert(cur && head);
    while (head->next) last = head, head = head->next;
    cur->data = data, last->next = cur;
    printf("%d ", data);
}

void free_queue(struct node *head)
{
    struct node *cur = head;
    while (head->next) {
        printf("%d ", head->data);
        head = head->next, free(cur), cur = head;
    }
}

int main(int argc, char **argv)
{
    int i, data;
    struct node *head = calloc(1, sizeof(struct node));
    for (i = 1; i < argc; i++) {
        data = atoi(argv[i]);
        //printf("%d ", data);
        queue(head, data);
    }
    free_queue(head);
    return 0;
}

