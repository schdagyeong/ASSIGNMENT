#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* link;
}Node;

Node* graph[100001];

int parent[100001];
int visited[100001];

void insert(int u, int v)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = v;
    newNode->link = graph[u];
    graph[u] = newNode;
}

void dfs(int v)
{
    visited[v] = 1;

    Node* p = graph[v];

    while (p != NULL)
    {
        int next = p->data;

        if (visited[next] == 0)
        {
            parent[next] = v;
            dfs(next);
        }

        p = p->link;
    }
}

int main(void)
{
    int N;

    scanf("%d", &N);

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;

        scanf("%d %d", &a, &b);

        insert(a, b);
        insert(b, a);
    }

    dfs(1);

    for (int i = 2; i <= N; i++)
    {
        printf("%d\n", parent[i]);
    }

    return 0;
}