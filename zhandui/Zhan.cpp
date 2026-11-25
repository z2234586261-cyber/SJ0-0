#include<stdio.h>
#include<stdlib.h>
#define MAX 100
//栈基本操作
typedef struct {
	int data[MAX];
	int top[2];

}*stk;
typedef struct LinkNode{
	int data;
	LinkNode* next;
}ListStack;
typedef struct LinkNode4 {
	char data;
	LinkNode4* next;
}ListStack4;
typedef struct {
	int data[MAX];
	int top;
}SqStack;
void InitStack(SqStack &S) {
	S.top = -1;
}
bool StackEmpty(SqStack s) {
	if (s.top == -1) {
		return true;
	}
	else {
		return false;
	}
}
bool Push(SqStack &S,int x) {
	if (S.top == MAX - 1) {
		return false;
	}
	else{
		S.top++;
		S.data[S.top] = x;
		return true;
	}
}
bool Pop(SqStack& S,int &x) {
	if (S.top == -1) {
		return false;
	}
	else {
		x = S.data[S.top];
		S.top--;
		return true;
	}
}
bool GetTop(SqStack &S,int &x){
	if (S.top == -1) {
		return false;
	}
	x = S.data[S.top];
	return true;
}
int dc(ListStack L,int n) {


}
int push5(stk &s,int i,int e){
	if (i < 0 || i>1) {
		exit(0);
	}
	if (s->top[0] + 1 == s->top[1]) {
		exit(0);
	}
	switch (i) {
	case 0:s->top[0]++;s->data[s->top[0]] = e;return 1;break;
	case 1:s->top[1]--;s->data[s->top[1]] = e;return 0;break;

	}
}
//队列基本操作
typedef struct {
	int data[MAX];
	int front, rear;
}*SqQueue;
void InitQueue1(SqQueue &Q) {
	Q->front = 0;
	Q->rear = 0;
}
void EnQueue(SqQueue &Q,int x){
	if (Q->rear > MAX) {

	}else{
		Q->data[Q->rear] = x;
		Q->rear++;
	}
}
//循环队列
void InitQueue(SqQueue &Q) {
	Q->rear = Q->front = 0;
}
bool QueueEmpty(SqQueue Q) {
	if (Q->front == Q->rear) {
		return true;
	}
	else return false;
}
bool EnQueue1(SqQueue &Q,int x){
	if ((Q->rear + 1) % MAX == Q->front) {
		return false;
	}
	else {
		Q->data[Q->rear] = x;
		Q->rear = (Q->rear + 1) % MAX;
		return true;
	}
}
bool DeQueue(SqQueue& Q, int& x) {
	if (Q->front == Q->rear) {
		return false;
	}
	else {
		x = Q->data[Q->front];
		Q->front = (Q->front + 1) % MAX;
	}
}
//链式队列
typedef struct LinkNode {
	int data;
	struct LinkNode* next;
};
typedef struct {
	LinkNode* front, * rear;
}LinkQueue;
void InitQueue(LinkQueue &Q) {
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));


}
bool QueueEmpty(LinkQueue Q) {
	if (Q.front == Q.rear) {
		return true;
	}
	else return false;
}
void EnQueue(LinkQueue& Q, int x) {
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
	p->data = x;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
}
bool DeQueue(LinkQueue& Q, int& x) {
	if (Q.front == Q.rear) {
		return false;
	}
	else {
		LinkNode* p = Q.front->next;
		x = p->data;
		Q.front->next = p->next;
		if (Q.rear == p) {
			Q.rear = Q.front;
		}
		free(p);
		return true;
	}
}
//87页
/*int EnQueue87(SqQueue &Q,int x){
	if (Q->rear == Q->front && Q->tag == 1 ){
		//队满
	}
	else {
		Q->data[Q->rear] = x;
		Q->rear = (Q->rear + 1) % MAX;
		Q->tag = 1;
	}
}
int DeQueue87(SqQueue& Q, int& x) {
	if (Q->rear == Q->front && Q->tag == 0) {
		//队空
	}
	else {
		x = Q->data[Q->front];
		Q->front = (Q->front + 1) % MAX;
		Q->tag = 0;
	}
	}
*/
//出对入栈和入队出栈逆置
int enqueue(SqStack& S1, SqStack& S2, int x) {
	if ( /* S1未满*/ ) {
		//x入栈
	}
	if (/* S1满，S2非空 */) {
		//dui列满
	}
	else {
		//S1为满，S2空
		while (/* S1非空 */) {
			//S1入栈S2
		}
	
	}
	push(S1, x);
}
void Dequeue(SqStack& S1, SqStack& S2, int& x) {
	if (/* S2非空 */) {
		//S2出栈
	}
	else if (/* S1空*/) {
		//都空了，队空
	}
	else {
		while (/* S1非空 */) {
			//S1入栈S2
		}
		//S2出栈
	}
}

int main()
{
}	