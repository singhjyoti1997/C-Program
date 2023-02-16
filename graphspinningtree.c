#include<stdio.h>
#include<stdlib.h>

struct node {
    int key;
    int weight;
    struct node* next;
};

struct node* newNode(int key, int weight) {
    struct node* temp = (struct node *)malloc(sizeof(struct node));
    temp->key = key;
    temp->weight = weight;
    temp->next = NULL;
    return temp;
}

struct node* addNode(struct node *head, int key, int weight) {
    struct node *temp = head;
    if(temp == NULL)
        return newNode(key, weight);
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newNode(key, weight);
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
    printf("%d(%d) ", head->key, head->weight);
    while(head->next != NULL) {
        printf("-> %d(%d) ", head->next->key, head->next->weight);
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

int min_key(int* key, int* inc, int size) {
    int min = 99999, index, i;
    for(i = 0; i < size; i++) {
        if(inc[i] == 0 && key[i] < min) {
            min = key[i];
            index = i;
        }
    }
    return index;
}

void printMST(int* parent, int* key, int size) {
    int i;
    for(i = 1; i < size; i++) {
        printf("%d - %d : %d\n", parent[i], i, key[i]);
    }
}

void prim_mat(int **mat, int size) {
    int i, u, v;
    int key[size];
    int parent[size];
    int included[size];

    for(i = 0; i < size; i++) {
        key[i] = 9999;
        included[i] = 0;
    }

    key[0] = 0;
    parent[0] =- 1;

    for(i = 0; i < size-1; i++) {
        u = min_key(key, included, size);
        included[u] = 1;
        for(v = 0; v < size; v++) {
            if(mat[u][v] != 0 && included[v] == 0 && mat[u][v] < key[v]) {
                parent[v] = u;
                key[v] = mat[u][v];
            }
        }
    }
    printMST(parent, key, size);
}

int find(int* parent, int i) {
    if(parent[i] == -1)
        return i;
    parent[i] = find(parent, parent[i]);
    return parent[i];
}

void unite(int* parent, int i, int j) {
    int pi = find(parent, i);
    int pj = find(parent, j);
    if(pi != pj)
        parent[pj] = pi;
}

void sort_edge(int **edges, int size) {
    int i, j, min, temp;
    for(i = 0; i < size-1; i++) {
        min = i;
        for(j = i+1; j < size; j++) {
            if(edges[j][0] < edges[min][0])
                min = j;
        }
        if(min != i) {
            temp = edges[min][0];
            edges[min][0] = edges[i][0];
            edges[i][0] = temp;

            temp = edges[min][1];
            edges[min][1] = edges[i][1];
            edges[i][1] = temp;

            temp = edges[min][2];
            edges[min][2] = edges[i][2];
            edges[i][2] = temp;
        }
    }
}

void kruskal_mat(int** mat, int size, int m) {
    int i, j, k=0;
    int **edges = (int **)malloc(m * sizeof(int *));
    for(i = 0; i < m; i++)
        edges[i] = (int *)malloc(3 * sizeof(int));
    int *parent = (int *)malloc(size * sizeof(int));
    for(i = 0; i < size; i++)
        parent[i] = -1;

    for(i = 0; i < size; i++) {
        for(j = i; j < size; j++) {
            if(mat[i][j] != 0) {
                edges[k][0] = mat[i][j];
                edges[k][1] = i;
                edges[k][2] = j;
                k++;
            }
        }
    }

    sort_edge(edges, m);

    for(i = 0; i < m; i++) {
        if(find(parent, edges[i][1]) != find(parent, edges[i][2])) {
            unite(parent, edges[i][1], edges[i][2]);
            printf("%d - %d : %d\n", edges[i][1], edges[i][2], edges[i][0]);
        }
    }
}

void prim_list(struct node **adj, int size) {
    int i, u, v;
    int key[size];
    int parent[size];
    int included[size];
    struct node *head;

    for(i = 0; i < size; i++) {
        key[i] = 9999;
        included[i] = 0;
    }

    key[0] = 0;
    parent[0] =- 1;

    for(i = 0; i < size-1; i++) {
        u = min_key(key, included, size);
        included[u] = 1;
        head = adj[u];
        while(head != NULL) {
            if(included[head->key] == 0 && head->weight < key[head->key]) {
                parent[head->key] = u;
                key[head->key] = head->weight;
            }
            head = head->next;
        }
    }
    printMST(parent, key, size);
}

void kruskal_list(int **edges, int size, int m) {
    int i, j, k=0;
    int *parent = (int *)malloc(size * sizeof(int));
    for(i = 0; i < size; i++)
        parent[i] = -1;

    sort_edge(edges, m);

    for(i = 0; i < m; i++) {
        if(find(parent, edges[i][1]) != find(parent, edges[i][2])) {
            unite(parent, edges[i][1], edges[i][2]);
            printf("%d - %d : %d\n", edges[i][1], edges[i][2], edges[i][0]);
        }
    }
}

int main(void) {
    int choice, n, m, i, j, start, end, root, weight;
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
            m = 0;
            for(i = 0; i < n; i++) {
                for(j = 0; j < n; j++) {
                    scanf("%d", &adj_mat[i][j]);
                    if(adj_mat[i][j] != 0)
                        m++;
                }
            }

            print_mat(adj_mat, n);
            printf("\nPrim MST: \n");
            prim_mat(adj_mat, n);
            printf("\nKruskal MST: \n");
            kruskal_mat(adj_mat, n, m/2);
        } else if(choice == 2) {
            adj_list = (struct node **)malloc(n * sizeof(struct node *));
            for(i = 0; i < n; i++)
                adj_list[i] = NULL;
            printf("Enter number of Edges: ");
            scanf("%d", &m);
            int **edges = (int **)malloc(m * sizeof(int *));
            for(i = 0; i < m; i++)
                edges[i] = (int *)malloc(3 * sizeof(int));
            printf("Enter %d node pairs and weights, representing edge enpoints\n", m);
            for(i = 0; i < m; i++) {
                scanf("%d%d%d", &start, &end, &weight);
                adj_list[start] = addNode(adj_list[start], end, weight);
                adj_list[end] = addNode(adj_list[end], start, weight);
                edges[i][0] = weight;
                edges[i][1] = start;
                edges[i][2] = end;
            }
            visited = (int *)malloc(n * sizeof(int));
            for(i = 0; i < n; i++)
                visited[i] = 0;
            print_adj(adj_list, n);
            printf("\nPrim MST: \n");
            prim_list(adj_list, n);
            printf("\nKruskal MST: \n");
            kruskal_list(edges, n, m);
        } else {
            break;
        }
    }
}
