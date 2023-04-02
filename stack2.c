#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK 30
#define MAX_INPUT 30
typedef enum { false, true } bool;
typedef int Data;

typedef struct {
	Data items[MAX_STACK];
	int top;
} stack;

void InitStack(stack* pstack);
bool IsFull(stack* pstack);
bool IsEmpty(stack* pstack);

Data Peek(stack* pstack);
void Push(stack* pstack, Data item);
void Pop(stack* pstack);

int IsOpen(char a);
int IsClose(char a);
int IsMatch(char a, char b);

int main() {
	char s2[MAX_INPUT];
	int val[MAX_INPUT] = { 0, };
	int i = 0;
	stack paren;
	InitStack(&paren);
	printf("Problem2 \n문자열을 입력하세요:\n");
	scanf("%s", s2);

	if (IsClose(s2[i])) {
		printf("0");
		return 0;
	}
	
	Push(&paren, s2[i]);
	++i;
	while (s2[i] != '\0') {
		if (IsOpen(s2[i])) {
			Push(&paren, s2[i]);
		}
		else if (IsClose(s2[i])) {
			if (IsMatch(Peek(&paren), s2[i]) != 0) {
				if (val[paren.top + 1] != 0) {
					val[paren.top] += IsMatch(Peek(&paren), s2[i]) * val[paren.top + 1];
					val[paren.top + 1] = 0;
				}
				else
					val[paren.top] += IsMatch(Peek(&paren), s2[i]);

				Pop(&paren);

			}
			else {
				printf("0");
				return 0;
			}
		}
		else {
			printf("잘못된 입력이 포함되어 있습니다.\n");
			printf("0");
			return 0;
		}
		i++;
	}
	printf("%d\n", val[0]);
	system("pause");
}

void InitStack(stack* pstack) {
	pstack->top = -1;
}

bool IsFull(stack* pstack) {
	return pstack->top == MAX_STACK - 1;
}

bool IsEmpty(stack* pstack) {
	return pstack->top == -1;
}

Data Peek(stack* pstack) {
	if (IsEmpty(pstack))
		exit(1);// stack is empty
	return pstack->items[pstack->top];
}
void Push(stack* pstack, Data item) {
	if (IsFull(pstack))
		exit(1);// stack is full
	pstack->items[++(pstack->top)] = item;
}

void Pop(stack* pstack) {
	if (IsEmpty(pstack))
		exit(1);// stack is full
	--(pstack->top);
}

int IsOpen(char a) {
	if ((a == '(') || (a == '{') || (a == '['))
		return 1;
	else
		return 0;
}

int IsClose(char a) {
	if ((a == ')') || (a == '}') || (a == ']'))
		return 1;
	else
		return 0;
}

int IsMatch(char a, char b) {
	if (a == '(') {
		if (b == ')')
			return 2;
		else
			return 0;
	}
	else if (a == '{') {
		if (b == '}')
			return -2;
		else
			return 0;
	}
	else if (a == '['); {
		if (b == ']')
			return 4;
		else
			return 0;
	}
}