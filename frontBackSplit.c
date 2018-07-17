#include <stdio.h>
struct node {
    int data;
    struct node *next;
};

void frontBackSplit(struct node *src, struct node **front, struct node **back) {
    if (!src || !(src->next)) {
        *front = src;
        *back = NULL;
        return;
    }
    struct node *fast, *slow;
    slow = src;
    fast = src->next;
    while (fast->next) {
        fast = fast->next;
        if (fast) {
            fast = fast->next;
            slow = slow->next;
        }
    }
    *front = src;
    *back = slow->next;
    slow->next = NULL;
}

int main(void) {
    return 0;
}
