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
        //printf("%.2d ", p->val);
        p->next = (i==n-1)? NULL: p+1;
    }
    //puts("");
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
static int cmp(const void *p, const void *q)
{
	int i = *((int *)p), j = *((int *)q);
	return (i-j);
}
/*quicksort for single list, O(nlgn) time, O(n) space */
void qsort_list(struct node *head)
{
	int *tmp, n;
    struct node *p;
    for (n=0,p=head; p; p=p->next,n++);
    tmp = malloc(sizeof(int)*n);
    if (NULL==tmp) {
        perror("no memory");
        return;
    }
    for (n=0, p=head; p; p=p->next) tmp[n++]=p->val;    /*grab all val into array*/
    qsort(tmp, n, sizeof(int), cmp);
    for (n=0, p=head; p; p=p->next) p->val = tmp[n++];  /*put array back to list*/
}
static struct node *merge(struct node *p, struct node *q)
{
    struct node *r;
    if (!p) return q;
    if (!q) return p;
    if (p->val > q->val) r = q, r->next = merge(q->next, p);
    else r = p, r->next = merge(p->next, q);
    return r;
}
void merge_sort(struct node **headref)
{
    struct node *slow, *fast, *head;
    assert(headref);
    head = *headref;
    if (!head || !head->next) return;
    slow = head, fast = head->next;
    while (fast) {
        fast = fast->next;
        if (fast) slow = slow->next, fast = fast->next;
    }
    fast = slow->next, slow->next = NULL, slow = head;
    merge_sort(&slow);
    merge_sort(&fast);
    *headref = merge(slow, fast);
}
int main(int argc, char **argv)
{
    struct node *head, *tmp;
    int n = (argc>1)? atoi(argv[1]) : 10;
    srand((unsigned int)time(NULL));
    head = tmp = create(n);
    print_list(head);
    //selection_sort(head);
    //qsort_list(head);
    merge_sort(&tmp);
    print_list(tmp);
    free(head);
    return 0;
}
