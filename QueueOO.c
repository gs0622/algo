/* Queue implementation in objective style
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
    struct node *back;
    int (*enqueue)(void *self, char *fspec);
    int (*dequeue)(void *self);
};
