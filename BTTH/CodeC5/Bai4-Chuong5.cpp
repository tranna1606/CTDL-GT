#include<iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
#define MAX 20
int A[MAX][MAX];
int n;//so dinh cua do thi
char vertex[MAX];//ten dinh

                               //danh sach lien ket su dung cho stack va queue
struct Node {
	int info;
	Node* link;
};
Node* sp;
Node*front, *rear;


///STACK
void Initstack()
{
	sp = NULL;
}
int isEmptyS()
{
	if (sp == NULL)
		return 1;
	return 0;
}
void PushS(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}

int PopS(int x)
{
	if (sp != NULL) {
		Node* p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}

//end STACK


//QUEUE
void Initqueue()
{
	front = NULL;
	rear = NULL;
}
int isEmptyQ()
{
	if (front == NULL)return 1;
	return 0;
}
void PushQ(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;

	rear = p;
}
int PopQ(int x)
{
	if (front != NULL) {
		Node* p = front;
		front = p->link;
		x = p->info;
		if (front == NULL)
		{
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}
//End QUEUE



void InitGraph()
{
	n = 0;
}
//Cau 4.1 Nhap ma tran ke bang tay
void inputGraph()
{
	cout << "Nhap so dinh do thi n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap ten dinh:  ";
		cin >> vertex[i];
		cout << "Nhap vao donh thu " << i + 1 << ": ";
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	}
}
//Cau 4.1 Nhap ma tran ke tu file txt
void inputGraphFromText()
{
	string line;
	ifstream myfile("mtk1.txt");
	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i < n; i++)
			myfile >> vertex[i];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				myfile >> A[i][j];
		}
	}
}

//4.2 Xuat ma tran ke
void outputGraph()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << A[i][j] << " ";
			cout << endl;
		}
	}
 }

void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << vertex[a[i]] << " ";
}

//4.3 Duyet theo chieu rong(BFS)
int C[100];
int bfs[100];
int nbfs = 0;
void InitC()
{
	for (int i = 0; i < n; i++)
		C[i] = 1;
}
void BFS(int v)
{
	int w, p;
	PushQ(v);
	C[v] = 0;
	while (front != NULL)
	{
		PopQ(p);
		bfs[nbfs] = p;
		nbfs++;
		for (w = 0; w < n; w++)
			if (C[w] && A[p][w] == 1)
			{
				PushQ(w);
				C[w] = 0;
			}
	}
}


//4.4 Duyet theo chieu sau

int dfs[100];
int ndfs = 0;
int u;
void DFS(int s)
{
	PushS(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v = 1;
	u = s;
	while(!isEmptyS())
	{
		if (v == n)
			PopS(u);
		for(v=0;v<n;v++)
			if(A[u][v]!=0 && C[v]==1)
			{
				PushS(u);
				PushS(v);
				dfs[ndfs] = v;
				ndfs++;
				C[v] = 0;
				u = v;
				break;
			}
			}
	}

//Cau 4.5 Tim su dung BFS
void Search_by_BFS(int x, int v)//v la dinh bat dau
{
	int w, p;
	PushQ(v);
	C[v] = 0;
	while (front != NULL)
	{
		PopQ(p);
		if (x == p)
		{
			cout << "Tim thay x= " << x << endl;
			return;
		}
		for(w=0;w<n;w++)
			if (C[w] && A[p][w] == 1)
			{
				PushQ(w);
				C[w] = 0;
			}
	}
}

int main()
{
	int a[MAX];
	int b[MAX];
	int choice;
	int select,sp,sp_b,x,i;
	system("cls");
	cout << "-----------------------Bai4,Chuong5, Do thi---------------------------\n";
	cout << "1. Khoi tao ma tran ke rong\n";
	cout << "2.Nhap ma tran ke tu file\n";
	cout << "3. Nhap ma tran ke thu cong \n";
	cout << "4.Xuat ma tran ke cua do thi\n";
	cout << "5.Duyet do thi theo chieu rong (BFS-DSLK)\n";
	cout << "6.Duyet do thi theo chieu sau(DFS-DSLK)\n";
	cout << "7.Tim dinh co gia tri x (dung BFS)\n";
	cout << "8.Ket thuc\n";
	do {
		cout << "---------Ban chon vao chuong trinh de thuc thi\n";
		cin >> choice;
		switch (choice)
		{
		case 1: InitGraph();
			cout << "Ma tran ke rong vua duoc khoi tao\n";
			break;
		case 2:
				inputGraphFromText();
				cout << "Ban vua nhap danh sach ke tu file\n";
				break;
		case 3:
			inputGraph();
			break;
		case 4: 
			outputGraph();
			break;
		case 5:
			Initqueue();
			InitC();
			cout << "Vui long nhap vao dinh xuat phat: ";
			cin >> x;
			BFS(x);
			cout << "Thu tu dinh sau khi duyet BFS: \n";
			output(bfs, n);
			break;	
		case 6:
			Initstack();
			InitC();
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			ndfs = 0;
			DFS(x);
			cout << "Thu tu dinh sau khi duyet DFS:  \n";
			output(dfs, n);
			break;
		case 7:
			Initqueue();
			InitC();
			nbfs = 0;
			cout << "Vui long nhap vao gia tri can tim : ";
			cin >> x;
			Search_by_BFS(x, 0);
			break;
		case 8:
			cout << "----------------GOOD BYE!!!-----------------\n";
			break;
		default:
			break;
		}
	} while (choice != 8);
	system("pause");
	return 0;
}