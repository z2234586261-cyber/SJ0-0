#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct MyStruct
{
	int a[MAX];
	int len;


}S;
int max(int a,int b,int c){
}
//二章（1）题
/*typedef struct
{
	int data[MAX];
	int length;
} SqList;
//删除最小值
void Compare(SqList &L) {
	int min = L.data[0];
	int j = 0;
	for (int i = 1;i < L.length;i++) {
		if (L.data[i] < min) {
			min = L.data[i];
			j = i;
		}


		
	}
	L.data[j] = L.data[L.length - 1];
	L.length--;
	}
int main() {
	SqList L;
	scanf("%d", &L.length);
	for(int i = 0; i < L.length; i++) {
		scanf("%d", &L.data[i]);
	}
	Compare(L);
	for (int i = 0; i < L.length; i++) {
		printf("%d ", L.data[i]);
	}


	return 0;
}*/

//二章（2）题
/*
对给定的顺序链表进行逆置操作，第一次循环首尾调换位置以此类推，但长度是偶数时候，虽然整除了，但数组下标从0开始，所以i还是能够指到一半的位置
对于基数则向下取整同时此数不取，那从0开始也相当于遍历了一半-1
typedef struct MyStruct
{
	int a[MAX];
	int len;


}S;

void Init(S &L) {
//初始化
	scanf("%d", &L.len);
	for (int i = 0;i < L.len;i++) {
		scanf("%d", &L.a[i]);


	}

}

void Niz(S &L){
	int Temp;
	for (int i = 0;i < L.len/2;i++) {
		Temp=L.a[i];
		L.a[i] = L.a[L.len - i - 1];

		L.a[L.len - i - 1] = Temp;

	}

}

int main() {
	S L;

	Init(L);
	
	Niz(L);



}*/

//二章（3）题
/*
typedef struct MyStruct
{
	int a[MAX];
	int len;


}S;
void Del(S & L,int x) {
	int k=0;
	for (int i = 0;i < L.len;i++) {
		if (L.a[i] != x) {
			L.a[k]=L.a[i];
			k++;

		}



}
	L.len = k;


}

int main() {


}
*/

//二章（4）题
/*方法一相当于同一个顺序表，有一个k遇到满足条件的在对这个顺序表重新赋值，最后满足条件的都被复制到表前面，表长度变为k
void Del(S & L, int s, int t) {
	int k = 0;
	for (int i = 0;i < L.len;i++) {
		if (L.a[i] <= t && L.a[i] >= s) {


		}
		else {
			L.a[k] =L.a[i];
			k++;

		}

	}
	L.len = k;

}
方法二，有一个k专门用来记录不满足条件的个数，当遍历到i是它前面的k的是不满足条件的，于是让i跳到不满足条件的前面即L.a[i - k] = L.a[i];
这样i接着遍历如果遇到满足条件的就前插，不满子条件意味着需要前插的在靠后了
void Del2(S &L,int s,int t) {
	int k = 0;
	for (int i = 0;i < L.len;i++) {
		if (L.a[i] <= t && L.a[i] >= s) {
			k++;

		}
		else {
			L.a[i - k] = L.a[i];

		}


	}
	L.len -= k;



}

int main() {

}*/

//二章（5）题
/*先让i指向0，j指向1，只要是i和j所指值不同，那i就要自增之后把不同的值赋给自增后的i，只要相同就自增i指向的地方也不会改变,去重
void Delet(S &L){
	int i, j=1;
	for (i = 0;j < L.len;j++) {
		if (L.a[i] != L.a[j]) {
			L.a[++i] = L.a[j];

			
		}

	}
	L.len = i + 1;

}*/


//二章（6）题(默认升序)
/*
设置了两个指针分别指向有序队列，在while循环里每个指针所指的数比较，较小的数进入队列3，之后其指向下一个数，知道有一个列表被遍历结束，把还剩下的列表全部复制到队列3中

void Mix(S & L1 ,S & L2,S &L3) {
	L3.len = L1.len + L2.len;
	int i=0,j=0;
	int k=0;//计数
	while (i < L1.len && j < L2.len){
		if (L1.a[i] < L2.a[j]) {
			L3.a[k] = L1.a[i];
			k++;
			i++;
		}
		else {
			L3.a[k] = L2.a[j];
			k++;	
			j++;

		}
	}
	while (i < L1.len) {
		L3.a[k] = L1.a[i];
		k++;
		i++;

	}
	while (j < L2.len) {
		L3.a[k] = L2.a[j];
		k++;
		j++;
	}
	
	L3.len = k;

	

}*/

//（7）题
//x,y表示逆置的范围(x+y)/2表示范围的中间,(x+y)/2-x才表示需要执行交换的次数
/*void Change(S& L, int m, int n) {
	int mind = (m + n) / 2;
	int temp;
	for (int i = 0;i < mind-m;i++) {
		temp = L.a[m + i];
		L.a[m + i] = L.a[n - i];
		L.a[n - 1] = temp;
}
	}*/

//(8)题（折半查找）
//折半查找，在最后两个范围会变成相邻数
/*
void Half(S &L,int x){
	int Low = 0;
	int mind;
	int High = L.len - 1;
	while (Low <= High) {
		mind = (Low + High) / 2;
		if(L.a[mind]==x){
			break;
		}
		else if (x<L.a[mind]) {
			High = mind-1;

		}
		else
		{
			Low = mind+1;
		}
	}
	if (L.a[mind] == x && mind != L.len- 1) {//找到元素并求元素不在队尾
		int temp;
		temp = L.a[mind];
		L.a[mind] = L.a[mind + 1];
		L.a[mind + 1] = temp;

	}
	if (Low > High) {
		printf("查找失败");
		//在mind处插入x
	}
}*/

//（9）
//长度一致,且升序，因为都是递增的，在不相等的时候只有较小的数的下表加一才可能相等
/*void Findsame(S L1, S L2, S L3) {
	int i = 0, j = 0, k = 0;
	while (i < L1.len - 1 &&j < L2.len - 1&&k < L3.len - 1) {
		if (L1.a[i] == L2.a[j] && L2.a[j] == L3.a[k]) {
			printf("%d", L1.a[i]);
			i++;j++;k++;
		}
		else {
			
			int Max = max(L1.a[i], L2.a[j], L3.a[k]);
			if (L1.a[i] < Max) { i++; }

			if (L2.a[j] < Max) { j++; }
			if (L3.a[k] < Max) { k++; }
		}

	}

}*/

//（10）
//两次逆置,实现数组偏移
/*
void Reverse(int R[], int from, int to) {
	int i, temp;
	for (i = 0;i < (to - from + 1)/2;i++) {
		{
			//元素交换
			temp = R[from + i];
			R[from + i] = R[to - i];
			R[to - i] = temp;

		}

	}

}*/

//（11）
//循环找中位数，（数列长度一致），
/*void Doubmind(int a[], int b[], int len) {
	int s1, d1, m1;
	d1 = len - 1;
	int s2, d2, m2;
	d2 = len - 1;
	while (s1 != d1 && s2 != d2) {
		m1 = (s1 + d1) / 2;      //无论奇数偶数，对于找中位数无影响
		m2 = (s2 + d2) / 2;
		if (a[m1] == a[m2]) {
			printf("%d", a[m1]);
		}
		else if(a[m1]<a[m2])
		{
			if ((s1 + d1) % 2 == 0) {//如果(s1+d1)/2为偶数,

				s1 = m1;
				d2 = m2;

			}
			else
			{
				s1 = m1 + 1;
				d2 = m2;
			}
				}
		else
		{
			if ((s1 + d1) % 2 == 0) {
				d1 = m1;
				s2 = m2;

			}
			else
			{
				s2 = m2 + 1;
				d1 = m1;
			}
		}





	}
	a[s1] < b[s2] ? a[s1] : a[s2];


}*/

//(12)
//boyer投票法找众数,众数要求个数大于n/2
/*void Boyerpoll(int a[], int n) {
	int i, c, count = 1;
	c = a[0];
	for (i = 1;i < n;i++) {
		if (a[i] == c) {
			count++;
		}
		else {
			if (count > 0) {
				count--;//就目前情况看count依旧，只要count未清零，就依旧可能是众数
			}
			else
			{
				c = a[i];
				count = 1;
				//c为什么直接跳到a[i]?因为count记为0此时刚才的c到现在的a[i]中间的数目前来看已经对其当中位数没有贡献了，
			}

		}


	}
	if (count > 0) {

		
	}*/

	//最后选出来的元素候选元素只是可能比如1，2，3，4，5，6这种或者2，2，3，3，4，这种前面的抵消完又多出来这样一个元素
	//所以最后拿候选元素遍历

//（13）
/*void findMissMin(int a[], int n) {
	int i, * b; 
	b = (int*)malloc(sizeof(int) * n);//因为有n个数所以直接设置n为b的大小让数最多都能存进去
	//之后将b的值都复为0
	for (i = 0;i < n;i++) {
		if (a[i] > 0 && a[i] < n) {
			b[a[i] - 1] = 1;

		}

	}
	for (i = 0;i < n;i++) {

		if (b[i] == 0) break;
	}

return i=1;

}*/

//(14)三个队列个从中取一个数醉成三元组，求路径最短长度，就是这三个数差距最小的时候
/*
int abs_(int a) {
	if (a < 0) return -a;
	else
	{
		return a;
	}

}
bool compare3(int a,int b,int c){
	if (a <= b && a <= c) {
		return true;
}

}
int findMinofTrip(int a[],int n,int b[],int m,int c[],int p) {
	int i = 0, j = 0, k = 0;
	int result = 100;
	int d;
	while (i<n&&j<m&&k<p) {//分别便利三个数组
		d = abs_(a[i] - b[j]) + abs_(a[i] - c[k]) + abs_(b[j] - c[k]);//求路径长度
		if (d < result) {
			result = d;
		}
		if (compare3(a[i], b[j], c[k])) {
			i++;
		}
		else if(compare3(b[j],a[i],c[k]))
		{
			j++;
		}
		else


		{//找出三个书
		
中最小的数使其指向下一个属，这样才哟有可能找到最短路径
			k++;
		}
		return result;

	}



}*/

//（15）
/*
void find(int a[], int n, int res[]) {
	int max = a[n - 1], min = a[n - 1];


	for (int i = n - 1;i >= 0;i--) {
		if (a[i] > max) {
			max = a[i];
		}
		if (a[i] < min) {
			min = a[i];
		}
		if (a[i] > 0) {
			res[i] = a[i] * max;
		}
		else
		{
			res[i] = a[i] * min;
		}



	}


}
*/