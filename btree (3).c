#include <stdio.h>
#include <stdlib.h>
struct node
{
    int item;
    struct node *left;
    struct node *right;
};
struct node *p = NULL;
void create(struct node *);
void display(struct node *, int);
void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);
void replace(struct node *);
void delete (struct node *);
int main()
{
    int ch, ele;
    while (1)
    {
        printf("\n1. Insertion at a element in tree.");
        printf("\n2. Post-order, Pre-order, Inorder Traversal.");
        printf("\n3. Delete a element from Tree.");
        printf("\n4. Replace elements in tree with Multiples of 3 with 5.");
        printf("\n5. Display Tree");
        printf("\n6. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            p = (struct node *)malloc(sizeof(struct node));
            create(p);
            break;
        case 2:
            printf("\nInorder Traversal: \n");
            inorder(p);
            printf("\nPreorder Traversal: \n");
            preorder(p);
            printf("\nPostorder Traversal: \n");
            postorder(p);
            break;
        case 3:
            delete (p);
            break;
        case 4:
            printf("\nReplacing before nodes: \n");
            display(p, 1);
            replace(p);
            printf("\nReplacing after nodes: \n");
            display(p, 1);
            break;
        case 5:
            display(p, 1);
            break;
        case 6:
            exit(1);
        default:
            printf("\ninvalid choice");
            break;
        }
    }
    return 0;
}
void create(struct node *ptr)
{
    char ch;
    struct node *nleft;
    struct node *nright;
    if (ptr != NULL)
    {
        printf("\nEnter Item To Be Inserted in tree: ");
        scanf("%d", &ptr->item);
        printf("\nDo You Want To Add Left Child For %d?(Y/N): ", ptr->item);
        scanf(" %c", &ch);
        if ((ch == 'Y') || (ch == 'y'))
        {
            nleft = (struct node *)malloc(sizeof(struct node));
            ptr->left = nleft;
            create(nleft);
        }
        else
        {
            ptr->left = NULL;
            create(NULL);
        }
        printf("\nDo You Want To Add Right Child For %d?(Y/N): ", ptr->item);
        scanf(" %c", &ch);
        if ((ch == 'Y') || (ch == 'y'))
        {
            nright = (struct node *)malloc(sizeof(struct node));
            ptr->right = nright;
            create(nright);
        }
        else
        {
            ptr->right = NULL;
            create(NULL);
        }
    }
    return;
}
void display(struct node *ptr, int level)
{
    if (ptr != NULL)
    {
        display(ptr->right, level + 1);
        for (int i = 0; i < level; i++)
            printf("  ");
        printf("%4d\n", ptr->item);
        display(ptr->left, level + 1);
    }
    return;
}
void postorder(struct node *ptr)
{
    if (ptr->left != NULL)
    {
        postorder(ptr->left);
    }
    if (ptr->right != NULL)
    {
        postorder(ptr->right);
    }
    printf("->");
    printf("%d", ptr->item);
    return;
}
void inorder(struct node *ptr)
{
    if (ptr->left != NULL)
    {
        inorder(ptr->left);
    }
    printf("->");
    printf("%d", ptr->item);
    if (ptr->right != NULL)
    {
        inorder(ptr->right);
    }
    return;
}
void preorder(struct node *ptr)
{
    printf("->");
    printf("%d", ptr->item);
    if (ptr->left != NULL)
    {
        preorder(ptr->left);
    }
    if (ptr->right != NULL)
    {
        preorder(ptr->right);
    }
    return;
}
void replace(struct node *ptr)
{
    if (ptr != NULL)
    {
        if ((ptr->item) % 3 == 0)
        {
            ptr->item = 5;
            replace(ptr->left);
            replace(ptr->right);
        }
        else
        {
            ptr->item = ptr->item;
            replace(ptr->left);
            replace(ptr->right);
        }
    }
}
void delete (struct node *ptr)
{
    if (ptr == NULL)
        return;
    delete (ptr->left);
    delete (ptr->right);
    printf("\n Deleting node: %d", ptr->item);
    free(ptr);
}
