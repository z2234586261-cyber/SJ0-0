#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct DNode {
	DNode* prior;
	int data;
	DNode* next;

}*DLinkList,DNode;
typedef struct DNode13 {
	DNode13 * prior;
	int data;
	DNode13* next;
	int freq=0;
}*DLinkList13, DNode13;
typedef struct LNode17 {
	int data;
	LNode17* link;

}LNode17,*LinkList17;
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode,*LinkList;
typedef struct node {
	int data;
	struct node* link;
}NODE,*PNODE;
bool InitList(LinkList &L) {
	L = (LNode *)malloc(sizeof(LNode));
	L->next = NULL;
	return true;
}
int Lenth(LinkList L) {
	int len = 0;
	LNode * p = L;
	while (p->next != NULL) {
		p = p->next;
		len++;
	}
	return len;
}
LNode* GetElem(LinkList L, int i) {
	LNode* p = L;
	int j = 0;
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	return p;
}
LNode* LocateElem(LinkList L,int e) {
	LNode * p=L->next;
	while(p!=NULL && p->data!=e){
		p = p->next;
		}
	return p;
}
bool LinkInsert(LinkList &L,int i,int e) {
	LNode * p = L;
	int j = 0;
	while (p != NULL && j<i-1) {//j的值最终就为p的位置，希望最后一次结束后p在i-1,所以最后一次循环体执行完j=i-1;所以j=i-1时是临界条件
		p = p->next;
		j++;
	}
	if (p == NULL) {
		return false;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;//在进行前插操作时，可以后插操作之后交换数据域
	p->next = s;
	return true;
}
bool ListDelete(LinkList &L,int i,int &e ) {
	LNode* p = L;
	int j = 0;
	while (p->next != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p->next==NULL || j>i-1) {
		return false;
	}
	else
	{
		LNode* q;
		q = p->next;
		e=p->next->data;
		p->next = p->next->next;
		free(q);

	}
	return true;
}
LinkList List_HeadInsert(LinkList &L) {//无头
	LNode* s;
	int x;
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	scanf("%d", &x);
	while (x!=9999) {

		 s = (LNode*)malloc(sizeof(LNode));
		 s->data = x;
		 s->next=L->next;
		 L->next = s;
		 scanf("%d", &x);
	}
	return L;

}
LinkList List_TailInsert(LinkList &L) {
	int x;
	LNode * r=L,*s;
	scanf("%d", & x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
	scanf("%d", &x);
	}
	r->next = NULL;
	return L;
}
void Del_X_1(LinkList & L,int x) {
	LNode* pre,*p=L->next,*q;
	pre = L;
	while (p!=NULL) {
		if(p->data==x){
			q = p;
			p = p->next;
			pre->next = p;
			free(q);
		}
		else
		{
			pre = p;
			p = p->next;	}
			}
}
void Print1(LinkList L) {
	LNode* p = L->next;
	while (p != NULL) {
		printf("%d", p->data);
		p = p->next;
	}
}
LinkList Delete_Min(LinkList &L) {
	LNode* pre = L, * p = pre->next;
	LNode* minpre =pre, * minp = p;
	while (p!=NULL) {
		if (p->data < minp->data) {
			minp = p;
			minpre = pre;

		}
		pre = p;//每次都会移动，只不过minpre和minp只有在找到更小的值时才会移动
		p = p->next;
	}	
	minpre->next = minp->next;
	free(minp);
	return L;

}
LinkList Reverse_1(LinkList& L) {
	LNode* p = L->next,*r;
	L->next = NULL;
	while (p != NULL) {//从第一个节点开始，每次都将p插入到头结点之后
		r = p->next;
		p->next = L->next;
		L->next = p;
		p = r;
	}
	return L;
}
LinkList Reverse_2(LinkList& L) {
	//需要三个指针，一个用于找前驱一个用于链接前驱，一个用于保存后继
	LNode * pre, *p, *r;
	p = L->next;
	r = p->next;
	p->next = NULL;
	pre = p;
	while (r != NULL) {//p指向当前节点，r指向当前节点的后继，pre指向当前节点的前驱，每次循环都将p的next指向pre，然后三个指针共同往前移动
		pre = p;
		p = r;
		r = r->next;//三个指针共同往前
		p->next = pre;
	}
	L->next = p;
	return L;
}
void RangeDelete(LinkList & L,int f,int t) {
	LNode* pre, * p=L->next;
	pre = L;
	while (p != NULL) {

		if (p->data<t && p->data>f) {
		
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		pre = p;
		p = p->next;
	}

}
LinkList DisCreat_2(LinkList& A) {
	LinkList B = (LinkList)malloc(sizeof(LNode));
	B->next = NULL;
	LNode* p = A->next,*q;
	LNode* ra = A;
	while (p!=NULL) {//每一次循环差入一奇一偶
		ra->next = p;//尾插法
		ra = p;
		p = p->next;//p指到奇数
		if (p != NULL) {

			q = p->next;
			p->next = B->next;//头插法
			B->next = p;
			p = q;

		}

	}


}
void Del_same(LinkList& L) {
	LNode* p, * q;
	p = L->next;
	if (p ==NULL) {
		return;
	}
	while (p->next != NULL) {
		q = p->next;
		if (q->data == p->data) {
			p->next = q->next;
			free(q);
		}
		else
		{
			p = p->next;
		}
	}
}
LinkList Get_common(LinkList A,LinkList B) {
	LinkList C = (LinkList)malloc(sizeof(LNode));
	LNode* r;
	r = C->next;
	LNode* p = A->next, * q = B->next;
	while (p != NULL && q != NULL) {
		if (p->data == q->data) {
			LNode * s = (LNode *)malloc(sizeof(LNode));
			s->data = p->data;
			r->next = s;
			r = s;
			p = p->next;
			q = q->next;

		}
		else if(p->data>q->data)
		{
			q = q->next;

		}
		else
		{
			p = p->next;
		}

	}
	r->next = NULL;
	return C;

}
LinkList Union(LinkList la,LinkList lb) {
	LNode* pa = la->next, * pb = lb->next;
	LNode *u,*pc=la;
	while (pa && pb) {
		if (pa->data == pb->data) {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
			u = pb;
			pb = pb->next;
			free(u);
		}
		else if(pa->data<pb->data)
		{	
			u = pa;
			pa = pa->next;
			free(u);
		}
		else
		{
			u = pb;
			pb = pb->next;
			free(u);

		}
		while (pa) {
			u = pa;
			pa = pa->next;
			free(u);
		}
		while (pb) {
			u = pb;
			pb = pb->next;
			free(u);
		}

	}
}
int Pattern(LinkList A,LinkList B) {
	LNode* p = A->next,*pre =p;
	LNode* q = B;
	while (p && q) {//朴素算法
		if (p->data == q->data) {
			p = p->next;
			q = q->next;
		}
		else{
			pre = pre->next;
			p = pre;
			q = B->next;
		}
	}
	if (q == NULL) {
		return 1;
	}
	else
	{
		return 0;
	}

}
int Symmetry(DLinkList L){
	DNode* p = L->next,*q=L->prior;
	while (p != q  &&  q->next!=p) {//如果写成p->next!=q则会在偶数的时候少比较一次
		if (p->data == q->data) {
			p = p->next;
			q = q->prior;
		}

	}
}
LinkList Link(LinkList & h1,LinkList & h2) {
	LNode* p = h1;
	LNode* q = h2;
	while (p->next!=h1) {
		p = p->next;
	}
	while (q->next != h2) {
		q = q->next;
	}
	p->next = h2;
	q->next = h1;
	return h1;

}
DLinkList13 Locate(DLinkList13 &L,int x) {
	DNode13* p = L->next,*q;
	while(p && p->data != x) {
		p = p->next;//查找元素x
	}
	if(!p) {
		exit(0);//如果没有找到元素x则退出程序
	}
	else {
		p->freq++;//如果找到了元素x则将其频率加1

		if (p->prior == L || p->freq > p->prior->freq) {
			return p;//如果p的前驱是头结点或者p的频率大于其前驱的频率，则不需要调整位置，直接返回p
		}
		if (p->prior != NULL) {//如果p的前驱不为空，则需要调整位置

			p->next->prior = p->prior;p->prior->next = p->next;
			q = p->prior;//取下p节点后，q指向p的前驱节点
			while (q != L && q->freq <= p->freq) {
				q = q->prior;
			}//找到第一个频率大于p的节点q
			p->next = q->next;
			q->next->prior = p;
			q->next = p;
			p->prior = q;//将p插入到q的后面

		}
	}
}
LNode* Converse(LNode * L,int k) {
	int n = 1;//计算链表长度
	LNode* p = L;//p指向头结点
	while (p->next != NULL) {
		p = p->next;
		n++;
	}
	p->next = L;//将链表首尾相连
	for (int i = 1;i <= n - k;i++) {
		p = p->next;//p指向第n-k个节点,p指向新的表尾
	}
	L = p->next;//L指向新的表头
	p->next = NULL;//将新的表尾的next置为NULL
	return L;	
}
LNode* FindLoopStart(LNode *hade) {//看传入的链表是否包含环
	LNode* fast = hade, * slow = hade;//设置快慢两个指针，如果两个指针最终相遇了，那就证明含有环，
	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) {
			break;//找到slow和fast相遇的位置
		}
	}
	if (fast == NULL || fast->next == NULL) {
		return NULL;//fast最终指向空了代表未形成环
	}
	//fast的速度是slow的2倍，所以最终fast比slow多走了一个slow，而slow不可能走完一个完整的环，甚至不会走超过半个环，令头到环起点为，环起到相遇为x,环长为r，2（a+x）=n*r+a+x,即为a=nr-x;由此可见
	//head到环起点距离=n倍环长-x，（n-1）r+(r-x)=a,所以让p2从slow开始先走完(n-1)个环长再走（r-x）的长度就可以找到环起点了
	LNode * p1 = hade,*p2=slow;
	while (p1 != p2) {
		p1 = p1->next;
		p2 = p2->next;

	}
	return p1;

}
int Search_K(LinkList17 list,int k) {//找到倒数第k个元素
	LNode17* p = list->link, * q = list->link;//设置两个指针，当p指向第k个元素时，q才开始一栋，pq现在开始共同移动距离为k当p指向最后一个时q指向倒数第k个
	int count = 0;
	while (p) {
		if (count < k) {
			count++;
		}
		else {
			q = q->link;
		}
		p = p->link;
	}
	if (count < k) {
		return 0;
	}
	else {
		printf("%d", q->data);
		return 1;
	}
}
LNode* find_lisr(LinkList A,LinkList B) {//给了两个含有公共尾的字符串链表，并且公共尾接在同一链表上，找到那个同一链表得到开始节点并返回；
	int m = Lenth(A);
	int n = Lenth(B);
	LNode* p, * q;
	for (p = A;m > n;m--) {//指向开始重合的前一个节点
		p = p->next;
	}
	for (q = B;m < n;n--) {
		q = q->next;
	}
	while (p->next != NULL && p->next != q->next) {
		p = p->next;
		q = q->next;
	}
	return p->next;



}
void func(PNODE h,int n){//空间换时间，一次循环
	PNODE p = h, r;//p指向头结点，r用于释放重复节点,p指针是工作指针，用于遍历链表
	int* q, m;
	q = (int*)malloc(sizeof(int) * (n+1));//新生成一个数组，下标专门用于代表原先链表的值
	for (int i = 0;i < n + 1;i++) {
		*(q + i) = 0;//初始化数组
	}
	while (p->link != NULL) {//都是对p的下一个节点进行判断，p指针始终指向当前节点的前驱节点
		m = p->link->data > 0 ? p->link->data : -p->link->data;//m为链表中节点的绝对值
		if ((*(q + m)) == 0) {//解指针数组中下标为m的值，如果为0则说明该节点是第一次出现，若不为0则说明该节点已经出现过了
			*(q + m) = 1;
			p = p->link;
		}
		else
		{//如果该节点已经出现过了，则将该节点删除
			r = p->link;
			p->link = p->link->link;
			free(r);
		}
	}
	free(q);


}
void change_list(NODE* h) {
	NODE* p=h, * q=h,*r,*s;
	while (q->link!=NULL) {
		p = p->link;
		q = q->link;
		if (q->link != NULL) {
			q = q->link;
		}
	}//p指向中间节点，q指向最后一个节点
	q = p->link;
	p->link = NULL;
	while (q != NULL) {
		r = q->link;//头部头插法，将后半部分的链表逆置
		q->link = p->link;
		p->link = q;
		q = r;
	}
	s = h->link;
	q = p->link;
	while (q != NULL) {
		r = q->link;
		q->link = s->link;
		s->link = q;
		s = q->link;
		q = r;
	}
}
int main() {
	
	


}