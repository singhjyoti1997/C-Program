#include<stdio.h>
#include<stdlib.h>

struct node {
    int key;
    struct node* next;
};

struct node* newNode(int data) {
    struct node* temp = (struct node *)malloc(sizeof(struct node));
    temp->key = data;
    temp->next = NULL;
    return temp;
}

struct node* addNode(struct node *head, int data) {
    struct node *temp = head;
    if(temp == NULL)
        return newNode(data);
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newNode(data);
    return head;
}

void print_mat(int **mat, int size) {
    int i, j;
    printf("Adjecency matrix \n");
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void print_list(struct node *head) {
    if(head == NULL)
        return;
    printf("%d ", head->key);
    while(head->next != NULL) {
        printf("-> %d ", head->next->key);
        head = head->next;
    }
}

void print_adj(struct node **list, int size) {
    int i;
    printf("Adjcency list \n");
    for(i = 0; i < size; i++){
        printf("%d : ", i);
        print_list(list[i]);
        printf("\n");
    }
}

void dfs_mat(int **mat, int size, int root, int* visited) {
    int i;
    visited[root] = 1;
    printf("%d ", root);
    for(i = 0; i < size; i++) {
        if(mat[root][i] == 1 && visited[i] == 0)
            dfs_mat(mat, size, i, visited);
    }
}

void bfs_mat(int **mat, int size, int root) {
    int i, front = -1, rear = -1, temp;
    int visited[size];
    int queue[size];
    for(i = 0; i < size; i++)
        visited[i] = 0;
    printf("%d ", root);
    visited[root] = 1;
    queue[++rear]=root; front++;
    while(front <= rear) {
        temp = queue[front++];
        for(i = 0; i < size; i++) {
            if(mat[temp][i] == 1 && visited[i] == 0) {
                printf("%d ", i);
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
    printf("\n");
}

void dfs_list(struct node **list, int size, int root, int* visited) {
    int i;
    struct node *head;
    visited[root] = 1;
    printf("%d ", root);
    head = list[root];
    while(head != NULL) {
        if(visited[head->key] == 0)
            dfs_list(list, size, head->key, visited);
        head = head->next;
    }
}

void bfs_list(struct node **list, int size, int root) {
    int i, front = -1, rear = -1, temp;
    struct node *head;
    int visited[size];
    int queue[size];
    for(i = 0; i < size; i++)
        visited[i] = 0;
    printf("%d ", root);
    visited[root] = 1;
    queue[++rear]=root; front++;
    while(front <= rear) {
        temp = queue[front++];
        head = list[temp];
        while(head != NULL) {
            if(visited[head->key] == 0) {
                printf("%d ", head->key);
                visited[head->key] = 1;
                queue[++rear] = head->key;
            }
            head = head->next;
        }
    }
    printf("\n");
}

int main(void) {
    int choice, n, m, i, j, start, end, root;
    int **adj_mat;
    int *visited;
    struct node **adj_list;
    while(1) {
        printf("Choose graph implementation type\n\t1. Adjecency matrix implementation\n\t2. Adjencency list implementation\n\t3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        printf("Enter number of nodes: ");
        scanf("%d", &n);
        if(choice == 1) {
            adj_mat = (int **)malloc(n * sizeof(int *));
            for(i = 0; i < n; i++)
                adj_mat[i] = (int *)malloc(n * sizeof(int));
            printf("Enter adjecency matrix:\n");
            for(i = 0; i < n; i++) {
                for(j = 0; j < n; j++)
                    scanf("%d", &adj_mat[i][j]);
            }
            visited = (int *)malloc(n * sizeof(int));
            for(i = 0; i < n; i++)
                visited[i] = 0;
            print_mat(adj_mat, n);
            printf("Enter root node: ");
            scanf("%d", &root);
            printf("\nDEF: ");
            dfs_mat(adj_mat, n, root, visited);
            printf("\nBFS: ");
            bfs_mat(adj_mat, n, root);
        } else if(choice == 2) {
            adj_list = (struct node **)malloc(n * sizeof(struct node *));
            for(i = 0; i < n; i++)
                adj_list[i] = NULL;
            printf("Enter number of Edges: ");
            scanf("%d", &m);
            printf("Enter %d node pairs, representing edge enpoints\n", m);
            for(i = 0; i < m; i++) {
                scanf("%d%d", &start, &end);
                adj_list[start] = addNode(adj_list[start], end);
                adj_list[end] = addNode(adj_list[end], start);
            }
            visited = (int *)malloc(n * sizeof(int));
            for(i = 0; i < n; i++)
                visited[i] = 0;
            print_adj(adj_list, n);
            printf("Enter root node: ");
            scanf("%d", &root);
            printf("\nDFS: ");
            dfs_list(adj_list, n, root, visited);
            printf("\nBFS: ");
            bfs_list(adj_list, n, root);
        } else {
            break;
        }
    }
}