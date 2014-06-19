#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void insert(int v)
{
    struct node *cur, *parent, *tmp = malloc(sizeof(struct node));
    if (NULL==tmp) return; /*no memory*/
    printf("insert %d\n", v);
    tmp->data = v, tmp->left = NULL, tmp->right = NULL;
    if (NULL==root) root=tmp; /*bst empty case*/
    else {
        cur = root;
        while (cur) {
            parent = cur;
            cur = (v > cur->data)? cur->right: cur->left;
        }
        if (v > parent->data) parent->right = tmp; else parent->left = tmp;
    }
}

void delete(int v)
{
#if 0 /*TBD*/
    struct node *cur = root, *parent = NULL;
    int found = 0;
    printf("delete %d: ", v);
    while (cur) {
        if (v == cur->data) {
            found = 1;
            break;
        }
        parent = cur;
        cur = (v > cur->data)? cur->right: cur->left;
    }
    if (!found) {
        printf("failed\n");
        return;
    }
    if (NULL == cur->left && NULL == cur->right) { /*leaf*/
    
    }
#endif
}

int bst_search(int key, struct node *cur)
{
    if (NULL==cur) return 0; /*not found*/
    if (key == cur->data) return 1; /*found*/
    return bst_search(key, (key > cur->data)? cur->right: cur->left);
}

void search(int v)
{
#if 0
    struct node *cur = root;
    printf("search %d: ", v);
    while (cur) {
        if (v == cur->data) {
            printf("found\n");
            return;
        }
        cur = (v > cur->data)? cur->right: cur->left;
    }
    printf("not found\n");
#else
    printf("search %d: ", v);
    if (bst_search(v, root)) printf("found\n"); else printf("not found\n");
#endif
}

void preorder(struct node *cur)
{
    if (NULL==cur) return;
    printf("%d ", cur->data); /*visit*/
    preorder(cur->left);
    preorder(cur->right);
}

void inorder(struct node *cur)
{
    if (NULL==cur) return;
    preorder(cur->left);
    printf("%d ", cur->data); /*visit*/
    preorder(cur->right);
}

void postorder(struct node *cur)
{
    if (NULL==cur) return;
    preorder(cur->left);
    preorder(cur->right);
    printf("%d ", cur->data); /*visit*/
}

typedef void (*callback)(int);
callback bst[3] = { search,  insert, delete };

int main(int argc, char **argv)
{
    int i, j;
    if (argc > 1) {
        for (i=1; i<argc; i++) insert(atoi(argv[i]));
    }
    while (1) {
        printf("0. search 1. insert 2. delete 3. preorder 4. inorder 5. postorder\n");
        if (scanf("%d", &i)!=1) break;
        if (i>5||i<0) continue;
        switch (i) {
        case 0: case 1:
            if (scanf("%d", &j)!=1) continue;
            bst[i](j);
            break;
        case 3:
            preorder(root);
            printf("\n");
            break;
        case 4:
            inorder(root);
            printf("\n");
            break;
        case 5:
            postorder(root);
            printf("\n");
            break;
        }
    }
    return 0;
}

