#include <stdio.h>

typedef struct element {
	int key;
};
void SWAP(element* a, element* b, element temp);
void quickSort(element a[], int left, int right);

int main() {
	element a[] = { 10, 21, 6, 11, 4, 7, 66, 44, 20, 3};
	for (int i = 0; i < 10; i++) printf("%d ", a[i].key);
	printf("\n");
	quickSort(a, 1, 10);
	for (int i = 0; i < 10; i++) printf("%d ", a[i].key);
}

void quickSort(element a[], int left, int right) {
	int pivot, i, j;
	element temp;
	temp.key = -1;
	if (left < right) {
		i = left;
		j = right-1;
		pivot = a[left-1].key;
		while (i < j) {
			while (a[i].key <= pivot)
				i++; // a[pivot] 보다큰값찾기
			while (a[j].key > pivot)
				j--; // a[pivot] 보다작은값찾기
			if (i < j) 
				SWAP(&a[i++], &a[j--], temp);
		}
		SWAP(&a[left-1], &a[j], temp);
		quickSort(a, left, j );
		quickSort(a, j+2, right);
	}
}
void SWAP(element* a, element* b, element temp) {
	temp = *a;
	*a = *b;
	*b = temp;
}