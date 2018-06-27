/*#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100
typedef struct node treePointer;
typedef struct node {
	char data;
	treePointer *leftChild;
	treePointer *rightChild;
};
void inorder(treePointer* ptr);
void preorder(treePointer* ptr);
void postorder(treePointer* ptr);
void levelOrder(treePointer* ptr);
treePointer* copy(treePointer *original);
void addq(treePointer *ptr);
treePointer *deleteq(int *front, int rear);
int rear = 0;
treePointer queue[MAX_QUEUE_SIZE];

int main() {
	treePointer H = { 'H', NULL, NULL };
	treePointer I = { 'I', NULL, NULL };
	treePointer D = { 'D', &H, &I };
	treePointer J = { 'J', NULL, NULL };
	treePointer E = { 'E', &J, NULL };
	treePointer B = { 'B', &D, &E };
	treePointer K = { 'K', NULL, NULL };
	treePointer F = { 'F', NULL, &K };
	treePointer L = { 'L', NULL, NULL };
	treePointer M = { 'M', NULL, NULL };
	treePointer G = { 'G', &L, &M };
	treePointer C = { 'C', &F, &G };
	treePointer A = { 'A', &B, &C };
	treePointer* root = &A;
	treePointer* root1 = NULL;
	int choice = 0;
	bool on = true;
	while (on) {
		printf("Menu\n1. Preorder\n2. Inorder\n3. Postorder\n4. Levelorder\n5. Copy\nchoice: ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			preorder(root);
			printf("\n");
			break;
		case 2:
			inorder(root);
			printf("\n");
			break;
		case 3:
			postorder(root);
			printf("\n");
			break;
		case 4:
			levelOrder(root);
			printf("\n");
			break;
		case 5:
			root1 = copy(root);
			inorder(root1);
			printf("\n");
			break;
		case -1 :
			on = false;
		}
	}
}

void inorder(treePointer *ptr) {
	if (ptr) { 
		inorder(ptr->leftChild); 
		printf("%c ", ptr->data);
		inorder(ptr->rightChild); 
	} 
}
void preorder(treePointer *ptr) {
	if (ptr) {
		printf("%c ", ptr->data);
		preorder(ptr->leftChild); 
		preorder(ptr->rightChild);
	} 
}
void postorder(treePointer *ptr) { 
	if (ptr) {
		postorder(ptr->leftChild);
		postorder(ptr->rightChild); 
		printf("%c ", ptr->data);
	} 
}
void levelOrder(treePointer *ptr) { 
	int front= rear = 0;
	if ( !ptr ) return; // 공백 트리  
	addq( ptr ); 
	for ( ; ; ) {
		ptr = deleteq(&front, rear);
		if ( ptr ) {
			printf("%c ", ptr->data);
			if ( ptr->leftChild ) addq(ptr->leftChild); 
			if ( ptr->rightChild ) addq(ptr->rightChild); 
		} else break; 
	} 
}

void addq(treePointer *ptr) {
	if (rear == MAX_QUEUE_SIZE) return;
	queue[rear++] = *ptr;
}
treePointer *deleteq(int* front, int rear) {
	if (*front == rear) return NULL;
	else return &queue[(*front)++];
}
treePointer* copy(treePointer *original) { // 주어진 트리를 복사하고 복사된 트리의 treePointer를 반환함
	treePointer *temp; 
	if ( original ) {
		temp = (treePointer*) malloc ( sizeof(treePointer) );
		temp -> leftChild = copy(original -> leftChild); 
		temp -> rightChild = copy(original -> rightChild); 
		temp -> data = original -> data; 
		return temp; 
	} 
	return 0; 
}*/