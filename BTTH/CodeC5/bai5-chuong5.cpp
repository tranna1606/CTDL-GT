//bai 5, chuong 5, do thi
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
using namespace std;
#define MAX 20

//danh sach lien ket su dung cho stack va queue
struct Node {
	int info;
	Node* link;
};
Node* sp;
Node* front, * rear;

Node* First[MAX];//DS cac DSK;
int n;
char vertex[MAX];//ten dinh

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
int PopS(int &x)
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
void InsertLast(Node*& first, Node* p)
{
	if (first == NULL)
		first = p;
	else {
		Node* q = first;
		while (q->link != NULL)
		{
			q = q->link;
		}
		q->link = p;
	}
}

//5.1 Nhap danh sach ke cua do thi
void inputGraph()
{
	cout << "Nhap so dinh cua do thi n:";
	cin >> n;
	cout << "Nhap ten dinh: ";
	for (int i = 0; i < n; i++)
		cin >> vertex[i];

	for (int i = 0; i < n; i++)
	{
		if (i > 0)
			cout << "Nhap dsk cua dinh thu " << i - 1 << " ( " << vertex[i - 1] << "):";
		int u;
		string str;
		while (getline(cin, str))
		{
			istringstream ss(str);
			while (ss >> u);
			{
				Node* p = new Node;
				p->info = u;
				p->link = NULL;
				InsertLast(First[i - 1], p);
				//cout<<u<<"-";
			}
			break;
		}
	}
}
//Nhap du lieu tu text
void inputGraphFromText()
{
	string line;
	ifstream myfile("dslk1.txt");
	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i < n; i++)
			myfile >> vertex[i];

		string str;
		int i = 0;
		while (getline(myfile, str))
		{
			istringstream ss(str);
			int u;
			while (ss >> u)
			{
				//Dinh u
				Node* p = new Node;
				p->info = u;
				p->link = NULL;
				InsertLast(First[i - 1], p);
			}
			i++;
		}
	}
}



//5.2 Xuat danh sach ke cua do thi
void outputGraph()
{
	for (int i = 0; i < n; i++)
	{
		cout << "Dinh" << i << " (" << vertex[i] << "):";
		Node* p = First[i];
		while (p != NULL)
		{
			cout << p->info << " ";
			p = p->link;
		}
		cout << endl;
	}
}
//5.3 Duyet do thi theo chieu rong (BFS)
int C[100];
int bfs[100];
int nbfs = 0;
void InitC()
{
	for (int i = 0; i < n; i++)//n la so dinh cua do thi
		C[i] = 1;
}
void BFS(int v)
{
	int p;
	Node* w;
	PushQ(v);
	C[v] = 0;
	while (front != NULL)
	{
		PopQ(p);
		bfs[nbfs] = p;
		w = First[p];
		nbfs++;
		while (w != NULL)
		{
			if (C[w->info])
			{
				PushQ(w->info);
				C[w->info] = 0;
			}
			w = w->link;
		}
	}
}

//5.4 Duyet do thi theo chieu sau(DFS)
int dfs[100];
int ndfs = 0;
void DFS(int s)
{
	PushS(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int u = s;
	Node* v = NULL;
	while (!isEmptyS()==0)
	{
		if (v == NULL)
			PopS(u);
		v = First[u];
		while (v != NULL)
		{
			if (C[v->info] == 1)
			{
				PushS(u);
				PushS(v->info);
				dfs[ndfs] = v->info;
				ndfs++;
				C[v->info] = 0;
				u = v->info;
				break;
			}
			v = v->link;
		}
	}
}

//Cau 4.5 Tim su dung BFS
void Search_by_BFS(int x, int v)//v la dinh bat dau
{
	int p;
	Node* w;
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
		w = First[p];
		while (w != NULL)
		{
			if (C[w->info])
			{
				PushQ(w->info);
				C[w->info] = 0;
			}
			w = w->link;
		}
	}
}

int main()
{
	int a[MAX];
	int b[MAX];
	int choice, x, i;
	system("cls");
	cout << "-----------------------Bai5,Chuong5, Do thi---------------------------\n";
	cout << "1. Khoi tao danh sach ke rong\n";
	cout << "2.Nhap danh sach ke tu file\n";
	cout << "3. Nhap danh sach ke thu cong \n";
	cout << "4.Xuat danh sach ke cua do thi\n";
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
			cout << "Danh sach ke rong vua duoc khoi tao\n";
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
			Initstack();
			InitC();
			cout << "Vui long nhap vao dinh xuat phat: ";
			cin >> x;
			nbfs = 0;
			BFS(x);
			cout << "Thu tu dinh sau khi duyet BFS: \n";
			output(bfs, n);
			break;
		case 6:
			Initqueue();
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
}