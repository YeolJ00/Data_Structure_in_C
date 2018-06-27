/*#include <stdio.h>
#define COMPARE(x, y) ((x > y) ? 1 : ((x == y) ? 0 : -1))

typedef struct {
	double coef;
	int deg;
}poly;
void addPoly(int starta, int finisha, int startb, int finishb);
void printPoly(poly a[], int starta, int enda);
void attach(double coef, int deg);
int avail = 0;
poly terms[]= { { 8,3 },{ 7, 1 },{ 1, 0 },  {10,3}, {3, 2}, {1, 0} };
poly result[100];

int main() {
	printf("A(x) = ");
	printPoly(terms, 0, 2);
	printf("B(x) = ");
	printPoly(terms, 3, 5);
	addPoly(0, 2, 3, 5);
	printf("D(x) = ");
	printPoly(result, 0, avail-1);
	return 0;
}

void addPoly(int starta, int finisha, int startb, int finishb) {
	double coefficient;
	while (starta <= finisha && startb <= finishb) {
		switch (COMPARE(terms[starta].deg, terms[startb].deg)) {
			case -1:
				attach(terms[startb].coef, terms[startb].deg);
				startb++;
				break;
			case 0:
				coefficient = terms[starta].coef + terms[startb].coef;
				if (coefficient)
					attach(coefficient, terms[starta].deg);
				starta++;
				startb++;
				break;
			case 1:
				attach(terms[starta].coef, terms[starta].deg);
				starta++;
				break;
		}
		avail++;
	}
}

void attach(double coef, int deg) {
	result[avail].coef = coef;
	result[avail].deg = deg;
}

void printPoly(poly a[], int start, int end) {
	for (; start <= end;start++) {
		if (a[start].deg == 0) printf("%.2f", a[start].coef);
		else	printf("%.2f X^%d", a[start].coef, a[start].deg);
		if (start != end)	printf(" + ");
		else	printf("\n");
	}
}*/