#include<iostream>
#define MAXSIZE 100
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define OVERFLOW 0
#define ERROR 0
using namespace std;
typedef char SElemType;
typedef int Status;
typedef struct SqStack{
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;

Status InitStack(SqStack& S) {
	S.base = new SElemType[MAXSIZE];
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
Status Push(SqStack &S,int e) {
	if (S.top - S.base == S.stacksize)return ERROR;
	*S.top++ = e;
}
Status Pop(SqStack& S, int& e) {
	if (S.top == S.base)return ERROR;
		e = *--S.top;
		cout << e;
}
int main() {
	int binary, num;
	SqStack S;
	cout << "请输入进制：";
	cin >> binary;
	cout << "请输入数据：";
	cin >> num;
	InitStack(S);
	while (num) {
		Push(S, num % binary);
		num = num / binary;
	}
	while(S.base!=S.top)
	Pop(S, num);
	system("pause");
}