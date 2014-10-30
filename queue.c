/* Queue implementation in C style
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
};
