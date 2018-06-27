/*#include <stdio.h>
#define COMPARE(x, y) ((x > y) ? 1 : ((x == y) ? 0 : -1))
#define MAX_TERMS 100

typedef struct {
	float coef;
	int expon;
}polynomial;
void padd(int starta, int finisha, int startb, int finishb, int *startd, int *finishd);
void attach(float coef, int expon);
void printPoly(int start, int end);

polynomial terms[MAX_TERMS];
int avail = 0;

int main() {
	terms[0] = { 3,5 };terms[1] = { 2,2 };terms[2] = { 4,0 };
	terms[3] = {1,4}, terms[4] = { 10,3 }; terms[5] = { 3,2 }; terms[6] = { 1,0 };
	avail = 7;
	int startd = 1, finishd = 100;
	printf("A(x) = ");
	printPoly(0, 2);
	printf("B(x) = ");
	printPoly( 3, 6);
	padd(0, 2, 3, 6, &startd, &finishd);
	printf("D(x) = ");
	printPoly(startd, finishd);
}
void padd(int starta, int finisha, int startb, int finishb, int *startd, int *finishd) {
	float coefficient;
	*startd = avail;
	while (starta <= finisha && startb <= finishb) {
		switch (COMPARE(terms[starta].expon, terms[startb].expon)) {
		case -1: // a의 expon < b의 expon 
			attach(terms[startb].coef, terms[startb].expon);
			startb++;
			break;
		case 0: // a의 expon = b의 expon 
			coefficient = terms[starta].coef + terms[startb].coef;
			if (coefficient) attach(coefficient, terms[starta].expon);
			starta++;
			startb++;
			break;
		case 1: //a의 expon > b의 expon 
			attach(terms[starta].coef, terms[starta].expon);
			starta++;
		}
	}
	for (; starta <= finisha; starta++) // A(x)의 나머지 항들을 첨가
		attach(terms[starta].coef, terms[starta].expon);
	for (; startb <= finishb; startb++) // B(x)의 나머지 항들을 첨가 
		attach(terms[startb].coef, terms[startb].expon);
	*finishd = avail - 1;
}

void attach(float coef, int expon) {
	terms[avail].coef = coef;
	terms[avail++].expon = expon;
}
void printPoly(int start, int end) {
	for (; start <= end; start++) {
		if (terms[start].expon == 0) printf("%.2f", terms[start].coef);
		else	printf("%.2f X^%d", terms[start].coef, terms[start].expon);
		if (start != end)	printf(" + ");
		else	printf("\n");
	}
}*/