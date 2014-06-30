#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
struct node {
    int val;
    struct node *next;
};
struct node *create(int n)
{
    int i;
    struct node *p, *head;
    if (n<=0) return NULL;
    p = head = malloc(sizeof(struct node)*n);
    for (i=0;p!=NULL && i<n;i++,p++) {
        p->val = rand()%100;
        p->next = (i==n-1)? NULL: p+1;
    }
    return head;
}
void print_list(struct node *head)
{
	struct node *p = head;

	while (p) {
		printf("%.2d%s", p->val, (p->next)?  " ": "\n");
		p = p->next;
	}
}
#if 0
/*selection_sort for single list, O(n^2) time, O(1) space */
void selection_sort(struct node *head)
{
	int tmp;
    struct node *p=head, *q;
    while (p) {
        q = p->next;
        while (q) {
            if (p->val > q->val)
                tmp = p->val, p->val = q->val, q->val = tmp;
            q = q->next;
        }
        p = p->next;
    }
}
#endif
/*selection_sort for single list, O(n^2) time, O(1) space */
void BubbleSort(struct node *head)
{
	int tmp, sz, i, j;
    struct node *p=head;
    for (p=head,sz=0;p;) sz++, p=p->next; /*count length*/
    for (i=sz-1;i>0;i--) { /*length-1 comparasion only*/
        p=head;
        for (j=0;j<i;j++) {
            if (p->val > p->next->val)
                tmp = p->val, p->val = p->next->val, p->next->val = tmp;
            p = p->next;
        }
    }
}
int main(int argc, char **argv)
{
    struct node *head;
    int n = (argc>1)? atoi(argv[1]) : 10;
    srand((unsigned int)time(NULL));
    head = create(n);
    print_list(head);
    BubbleSort(head);
    print_list(head);
    free(head);
    return 0;
}
