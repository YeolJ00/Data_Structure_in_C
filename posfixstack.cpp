/*#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
typedef enum { 
	lparen, rparen, plus, minus, times, divide, mod, eos, operand 
} precedence;
static int isp[] = {0, 19, 12, 12, 13, 13, 13, 0};
static int icp[] = {20, 19, 12, 12, 13, 13, 13, 0};

void postfix();
bool IsFull();
bool IsEmpty();
void push(precedence item);
void push1(int num);
precedence pop();
int pop1();
precedence getToken(char* symbol, int* n);
void printToken(precedence tok, int i);
void printStack();
int eval();

precedence stack[MAX_STACK_SIZE];
int stack1[MAX_STACK_SIZE];
char list[20]; // 입력
int top = 0;
char result[sizeof(list)];
int main() {
	int i = 0;
	printf("infix input\t");
	scanf("%s", list);
	postfix();
	printf("postfix output\t");
	for (i=0; i < sizeof(result); i++)
		printf("%c ", result[i]);
	top = -1;
	printf("\nResult\t%d", eval());
}

void postfix() {
	char symbol;
	int n = 0;
	precedence token;
	stack[0] = eos;
	int i = 0;
	for (token = getToken(&symbol, &n); token != eos; token = getToken(&symbol,&n)) {
		if (token == operand)
			result[i++] = symbol;
		else if (token == rparen) {
			while (stack[top] != lparen)
				printToken(pop(),i++);
			pop();
		}else {//operator
			while (isp[stack[top]] >= icp[token])
				printToken(pop(),i++);
			push(token);
		}
	}
	while ((token = pop()) != eos) {
		printToken(token,i++);
	}
	printf("\n");
}
precedence getToken(char *symbol, int *n) {
	*symbol = list[(*n)++]; // 문자 배열에서의 현재 문자
	switch (*symbol)  {
		case '(' : return lparen;
		case ')' : return rparen;
		case '+' : return plus;
		case '-' : return minus;
		case '/' :  return divide;
		case '*' : return times;
		case '%' : return mod;
		case '\0': return eos;
		default : return operand; // returned token is represented by its enumerated value
	}
}
precedence getToken1(char *symbol, int *n) {
	*symbol = result[(*n)++]; // 문자 배열에서의 현재 문자
	switch (*symbol) {
	case '(': return lparen;
	case ')': return rparen;
	case '+': return plus;
	case '-': return minus;
	case '/':  return divide;
	case '*': return times;
	case '%': return mod;
	case '\0': return eos;
	default: return operand; // returned token is represented by its enumerated value
	}
}
void printToken(precedence tok, int i) {//print to result
	switch (tok) {
		case lparen :
			result[i] = '(';
			break;
		case rparen :
			result[i] = ')';
			break;
		case plus :
			result[i] = '+';
			break;
		case minus:
			result[i] = '-';
			break;
		case times:
			result[i] = '*';
			break;
		case divide :
			result[i] = '/';
			break;
		case mod :
			result[i] = '%';
			break;
		case eos :
			result[i] = '\0';
			break;
		}
}
int eval() {
	precedence token;
	char symbol;
	int op1, op2;
	int n = 0;
	token = getToken1(&symbol,&n);
	while (token != eos) {
		if (token == operand)
			push1(symbol - '0');
		else {
			op1 = pop1();
			op2 = pop1();
			switch (token) {
			case plus: push1(op1 + op2);
				break;
			case minus: push1(op2 - op1);
					break;
			case times: push1(op1*op2);
				break;
			case divide: push1(op2 / op1);
				break;
			case mod: push1(op1%op2);
				break;
			}
		}
		printStack();
		token = getToken1(&symbol,&n);
	}
	return pop1();
}
void printStack() {
	printf("\n********************Top = %d\nStack : ", top);
	for (int i = 0; i <= top; i++)
		printf("%d", stack1[i]);
}
bool IsEmpty() {
	if (top < 0) return true;
	else return false;
}
bool IsFull() {
	if (top >= MAX_STACK_SIZE - 1) return true;
	else return false;
}
void stackFull() {
	fprintf(stderr, "Stack is Full");
	exit(EXIT_FAILURE);
}
void stackEmpty() { 
	fprintf(stderr, ""); 
	exit(EXIT_FAILURE); 
}

void push(precedence item) {
	if (IsFull()) stackFull();
	stack[++top] = item;
}
void push1(int num) {
	if (IsFull()) stackFull();
	stack1[++top] = num;
}
precedence pop() {
	if (IsEmpty())	stackEmpty();
	return stack[top--];
}
int pop1() {
	if (IsEmpty())	stackEmpty();
	return stack1[top--];
}*/