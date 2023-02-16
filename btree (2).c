#include <stdio.h>
#include <stdlib.h>

struct node
{
 int value;
 struct node *left;
 struct node *right;
}
*root = NULL, *temp = NULL, *temp2, *temp1;
void delete1();
void insert();
void delete();
void display();
void inorder(struct node *t);
void create();
void search(struct node *t);
void preorder(struct node *t);
void postorder(struct node *t);
void search1(struct node *t,int item);
int smallest(struct node *t);
int largest(struct node *t);
void replace();

int flag = 1;

void main()
{
 int choice;
 printf("\n\t 1.Insert element\n\t 2.Delete an element from the tree\n\t 3.Inorder Traversal\n\t 4.Preorder Traversal \n\t 5.Postorder Traversal \n\t 6.Display Tree \n\t 7.Replace the number by \n\t 8.Exit");

 while(1)
 {
 printf("\n Please enter your choice : ");
 scanf("%d", &choice);
 switch (choice)
 {
 case 1: 
 insert();
 break;
 case 2: 
 delete();
 break;
 case 3: 
inorder(root);
 break;
case 4: 
 preorder(root);
 break;
 case 5: 
 postorder(root);
 break;
case 6: display(root,1);
 break;
 case 7: 
 replace(root);
 break;
case 8: 
exit(0);
 default :  
printf ("\n\t Please enter a Valid Choice(1/2/3/4/5)");
 break; 
 }
 }
}

void insert()
{
create();
 if (root == NULL) 
 root = temp;
 else 
search(root); 
}


void create()
{
 int data;

 printf("Enter the value: ");
 scanf("%d", &data);
 temp = (struct node *)malloc(5*sizeof(struct node));
 temp->value = data;
temp->left = temp->right = NULL;
}


void search(struct node *t)
{
 if ((temp->value > t->value) && (t->right != NULL)) /* value more than root node inserted at right side */
 search(t->right);
 else if ((temp->value > t->value) && (t->right == NULL))
 t->right = temp;
 else if ((temp->value < t->value) && (t->left != NULL)) /* value less than root node inserted at left side */
search(t->left);
 else if ((temp->value < t->value) && (t->left == NULL))
 t->left = temp;
}


/* check for the deleted node */
void delete()
{
int data;
 if (root == NULL)
 {
 printf("No elements in a tree to delete");
 return;
}
 printf("Enter the elements to be deleted : ");
 scanf("%d", &data);
 temp1 = root;
 temp2 = root;
 search1(root, data);
}


void preorder(struct node *t)
{
 if (root == NULL)
 {
 printf("tree is empty");
 return;
 }
 printf("%d -> ", t->value);
 if (t->left != NULL) 
 preorder(t->left);
 if (t->right != NULL) 
 preorder(t->right);
}

void inorder(struct node *t)
{
 if (root == NULL)
 {
printf("No elements in a tree to display");
 return;
 }
if (t->left != NULL) 
 inorder(t->left);
printf("%d -> ", t->value);
 if (t->right != NULL) 
 inorder(t->right);
}


void postorder(struct node *t)
{
 if (root == NULL)
 {
 printf("the tree is empty");
return;
}
 if (t->left != NULL) 
 postorder(t->left);
 if (t->right != NULL) 
 postorder(t->right);
 printf("%d -> ", t->value);
}

void search1(struct node *t, int item)
{
 if ((item>t->value))
 {
 temp1 = t;
 search1(t->right, item);
 }
 else if ((item < t->value))
 {
 temp1 = t;
 search1(t->left, item);
}
 else if ((item==t->value))
 {
 delete1(t);
 }
}

void delete1(struct node *t)
{
 int k;

/* To delete leaf node */
 if ((t->left == NULL) && (t->right == NULL))
 {
 if (temp1->left == t)
 {
 temp1->left = NULL;
 }
 else
 {
 temp1->right = NULL;
 }
 t = NULL;
 free(t);
 return;
 }

 /* To delete node having one left hand child */
 else if ((t->right == NULL))
 {
 if (temp1 == t)
 {
 root = t->left;
 temp1 = root;
 }
else if (temp1->left == t)
 {
temp1->left = t->left;

 }
 else
 {
 temp1->right = t->left;
 }
 t = NULL;
 free(t);
 return;
}

 /* To delete node having right hand child */
 else if (t->left == NULL)
 {
 if (temp1 == t)
 {
 root = t->right;
 temp1 = root;
 }
 else if (temp1->right == t)
 temp1->right = t->right;
 else
 temp1->left = t->right;
 t == NULL;
 free(t);
 return;
 }

 /* To delete node having two child */
else if ((t->left != NULL) && (t->right != NULL)) 
 {
 temp2 = root;
 if (t->right != NULL)
 {
 k = smallest(t->right);
 flag = 1;
 }
 else
 {
 k =largest(t->left);
 flag = 2;
 }
 search1(root, k);
 t->value = k;
 }

}

/* To find the smallest element in the right sub tree */
int smallest(struct node *temp)
{
 temp2 = temp;
if (temp->left != NULL)
 {
 temp2 = temp;
 return(smallest(temp->left));
 }
 else 
 return (temp->value);
}

/* To find the largest element in the left sub tree */
int largest(struct node *temp)
{
 if (temp->right != NULL)
 {
 temp2 = temp;
 return(largest(temp->right));
 }
 else 
 return(temp->value);
}

void display(struct node* t,int level)
{
 int i;
 if(!t)
 return ;
 display(t->right,level+1);
 for(i=1;i<level;i++)
 printf(" ");
 printf("%d\n",t->value);
 display(t->left,level+1);
}

void replace(struct node *t)
{

 int rep;
 printf("Enter the value to be replaced: ");
 scanf("%d", &rep);
 if (root == NULL)
 {
 printf("No elements in");
 return;
 }
 if (t->left != NULL) 
 replace(t->left);
 if(t->value %3==0)
 t->value =rep;

if (t->right != NULL) 
 replace(t->right);

}