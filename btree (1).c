#include<stdio.h>
#include<stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};

struct node* newNode(int value) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = value;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* addToTree(struct node* root, int val) {
    if (root == NULL)
        return newNode(val);
    if (val <= root->key)
        root->left = addToTree(root->left, val);
    else
        root->right = addToTree(root->right, val);
    return root;
}

int isBST(struct node* root) {
    int leftBST, rightBST;
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    if (root->left != NULL) {
        if (root->key < root->left->key)
            return 0;
        else {
            leftBST = isBST(root->left);
            if (leftBST == 0)
                return 0;
        }
    }
    if (root->right != NULL) {
        if (root->key > root->right->key)
            return 0;
        else {
            rightBST = isBST(root->right);
            if (rightBST == 0)
                return 0;
        }
    }
    return 1;
}

void inOrder(struct node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

void leafNodes(struct node* root) {
    if (root != NULL) {
        leafNodes(root->left);
        leafNodes(root->right);
        if (root->left == NULL && root->right == NULL)
            printf("%d ", root->key);
    }
}

struct node* getSmallest(struct node* root) {
    if (root == NULL)
        return root;
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct node* deleteRoot(struct node* root) {
    struct node* right = root->right;
    struct node* leftOfRight = getSmallest(right);
    leftOfRight->left = root->left;
    return root->right;
}
void display(struct node* root,int level)
{
 int i;
 if(!root)
 return ;
 display(root->right,level+1);
 for(i=1;i<level;i++)
 printf(" ");
 printf("%d \n",root->key);
 display(root->left,level+1);
}

int main() {
    struct node* root = NULL;
    int n, val, i, choice;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter value of %d node: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        root = addToTree(root, val);
    }
    while (1) {
        printf("1.Check if the given Binary tree is BST or not\n");
        printf("2.For a given Binary search tree, print the in-order traversal\n");
        printf("3.For a given Binary tree, print the leaf nodes of the tree\n");
        printf("6.In a BST insert element at a specified location\n");
        printf("7.Delete the root node of BST from a given input\n");
        printf("8.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (isBST(root) == 1)
                    printf("Yes\n");
                else
                    printf("No\n");
            break;
            case 2:
                inOrder(root);
                printf("\n");
            break;
            case 3:
                leafNodes(root);
                printf("\n");
            break;
            case 6:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = addToTree(root, val);
            break;
            case 7:
                root = deleteRoot(root);
            break;
            case 8:
                display(root,1);
            break;
            default:
                printf("wrong choice!");
        }
    }
}