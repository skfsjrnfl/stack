#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK 1000
#define MAX_INPUT 1000
typedef enum {false,true} bool;
typedef int Data;

typedef struct {
	Data items[MAX_STACK];
	int top;
} stack;

void InitStack(stack* pstack);
bool IsFull(stack* pstack);
bool IsEmpty(stack* pstack);

Data Peek(stack* pstack);
void Push(stack* pstack,Data item);
void Pop(stack* pstack);

int main() {
	char s1[MAX_INPUT];
	int i = 0;
	int wro = 0;
	int count = 0;
	stack sit;
	InitStack(&sit);
	printf("Problem1 \n문자열을 입력하세요:\n");
	scanf("%s", s1);
	
	Push(&sit, s1[i]);
	++i;

	while (s1[i] != '\0') {
		if (s1[i] == '#') {
			Pop(&sit);
			Push(&sit, s1[i]);
			wro = 0;
		}
		else {
			if (s1[i] == Peek(&sit)) {
				Push(&sit, s1[i]);
				if (wro == 1)
					count = count + 1;
				else
					count = count + 2;
				wro = 1;
			}
			else {
				Pop(&sit);
				Push(&sit, s1[i]);
				wro = 0;
			}
		}
		++i;
	}//스택 처리

	if (sit.top == 0)
		printf("0\n");
	else
		printf("%d\n", count);//붙어앉아있는 사람의 수
	system("pause");
	return sit.top;
}

void InitStack(stack* pstack){
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
void Push(stack* pstack,Data item) {
	if (IsFull(pstack))
		exit(1);// stack is full
	pstack->items[++(pstack->top)] = item;
}

void Pop(stack* pstack) {
	if (IsEmpty(pstack))
		exit(1);// stack is full
	--(pstack->top);
}