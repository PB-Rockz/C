#include <cstddef>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;
int main()
{
    node *p, *p1, *p2;
    p = (node *)malloc(sizeof(node));
    p->data = 10;
    p->left = NULL;
    p->right = NULL;

    p1 = (node *)malloc(sizeof(node));
    p1->data = 20;
    p1->left = NULL;
    p1->right = NULL;

    p2 = (node *)malloc(sizeof(node));
    p2->data = 30;
    p2->left = NULL;
    p2->right = NULL;

    p->left = p1;
    p->right = p2;

}
