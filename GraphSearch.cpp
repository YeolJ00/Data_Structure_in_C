/*#include <stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 10
#define FALSE 0
#define TRUE 1
void dfs(int v);
void bfs(int v);
short int visited[MAX_VERTICES];
int queue[10] = { 0 };
void addq(int * front, int* rear, int v);
int deleteq(int* front, int* rear);
typedef struct node nodePointer;
typedef struct node {
	int vertex;
	nodePointer* link;
};
nodePointer *graph[MAX_VERTICES];
int main() {
	nodePointer *temp1 = (nodePointer*)malloc(sizeof(nodePointer));
	nodePointer *temp2 = (nodePointer*)malloc(sizeof(nodePointer));
	*temp1 = { 2, NULL };
	*temp2 = { 1, temp1 };
	graph[0] = temp2;
	temp1 = (nodePointer*)malloc(sizeof(nodePointer));
	temp2 = (nodePointer*)malloc(sizeof(nodePointer));
	*temp1 = { 4, NULL };
	*temp2 = { 3, temp1 };
	temp1 = (nodePointer*)malloc(sizeof(nodePointer));
	*temp1 = { 0, temp2 };
	graph[1] = temp1;
	temp1 = (nodePointer*)malloc(sizeof(nodePointer));
	temp2 = (nodePointer*)malloc(sizeof(nodePointer));
	*temp1 = { 6, NULL };
	*temp2 = { 5, temp1 };
	temp1 = (nodePointer*)malloc(sizeof(nodePointer));
	*temp1 = {0, temp2};
	graph[2] = temp1;
	temp1 = (nodePointer*)malloc(sizeof(nodePointer));
	temp2 = (nodePointer*)malloc(sizeof(nodePointer));
	*temp1 = { 7, NULL };
	*temp2 = { 1, temp1 };
	graph[3] = temp2;
	temp1 = (nodePointer*)malloc(sizeof(nodePointer));
	temp2 = (nodePointer*)malloc(sizeof(nodePointer));
	*temp1 = { 7, NULL };
	*temp2 = { 1, temp1};
	graph[4] = temp2;
	temp1 = (nodePointer*)malloc(sizeof(nodePointer));
	temp2 = (nodePointer*)malloc(sizeof(nodePointer));
	*temp1 = { 7, NULL };
	*temp2 = { 2, temp1 };
	graph[5] = temp2;
	temp1 = (nodePointer*)malloc(sizeof(nodePointer));
	temp2 = (nodePointer*)malloc(sizeof(nodePointer));
	*temp1 = { 6, NULL};
	*temp2 = { 5, temp1 };
	temp1 = (nodePointer*)malloc(sizeof(nodePointer));
	*temp1 = { 4, temp2 };
	temp2 = (nodePointer*)malloc(sizeof(nodePointer));
	*temp2 = { 3, temp1 };
	graph[7] = temp2;
	dfs(0);
	printf("\n");
	for (int i = 0; i < 10; i++) visited[i] = FALSE;
	bfs(0);
	return 0;
}
void dfs(int v) {
	nodePointer *w;
	visited[v] = TRUE;
	printf("v%d ", v);
	for (w = graph[v]; w; w = w->link) {
		if (!visited[w->vertex]) dfs(w->vertex);
	}
 }
void bfs(int v) {
	nodePointer *w;
	int *front = (int*)malloc(sizeof(int*));
	int *rear = (int*)malloc(sizeof(int));
	*front = *rear = 0;
	printf("v%d ", v);
	visited[v] = TRUE;
	addq(front, rear, v);
	while (v != -1) {
		v = deleteq(front, rear);
		for (w = graph[v]; w != NULL; w = w->link) {
			if (!visited[w->vertex]) {
				printf("v%d ", w->vertex);
				addq(front, rear, w->vertex);
				visited[w->vertex] = TRUE;
			}
		}
	}
}
void addq(int* front, int* rear, int v) {
	if (*rear == 10) return;
	queue[(*rear)++] = v;
}
int deleteq(int* front, int*rear) {
	if (*front == *rear) return -1;
	else return queue[(*front)++];
}*/