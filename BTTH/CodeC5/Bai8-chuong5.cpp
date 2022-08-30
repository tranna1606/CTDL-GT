//Bài 8 - chýõng 5
#include<iostream>
#include<fstream>
#include<sstream>
#include<stdio.h>
using namespace std;
#define MAX 20
int a[MAX][MAX];
int n, C[MAX], bfs[100], nbfs = 0, dfs[100], ndfs = 0;
char vertex[MAX];
struct Node
{
	int info;
	Node* link;
};
Node* front, * rear;
Node* sp;
Node* First[MAX];
/*bool Doc_File(string fileName)
{
	ifstream ifs;
	ifs.open("fileName");
	if (!ifs.is_open())
	{
		cout << "Error";
		return false;
	}
	string temp;
	getline(ifs, temp, '\n');
	n = atoi(temp.c_str());

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			getline(ifs, temp, ' ');
			a[i][j] = atoi(temp.c_str());
		}
		getline(ifs, temp, '\n');
		a[i][n - 1] = atoi(temp.c_str());
	}
	ifs.close();
}*/
void InsertLast(Node*& first, Node* p)
{
	if (first == NULL)
		first = p;
	else
	{
		Node* q = first;
		while (q->link != NULL)
		{
			q = q->link;
		}
		q->link = p;
	}
}
void inputGraphFromText()
{
	string line;
	ifstream myfile("dothi1.txt");
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
				/// Dinh u
				Node* p = new Node;
				p->info = u;
				p->link = NULL;
				InsertLast(First[i - 1], p);
			}
			i++;
		}
	}
}
void input()
{
	cout << "Nhap so dinh cua do thi: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap dong thu " << i + 1 << ": ";
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
}
void output()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}
void initQ()
{
	front = rear = NULL;
}
int isEmptyQ()
{
	if (front == NULL)
		return 1;
	return 0;
}
int PushQ(int x)
{
	Node* p = new Node;
	p->info = x;

	p->link = front;
	if (front == NULL)
		front = rear = p;
	else
		front = p;

	return 1;
}
int PopQ(int& x)
{
	if (front != NULL)
	{
		Node* p = front;
		x = p->info;
		front = p->link;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}
void khoitaochuaxet()
{
	for (int i = 0; i < n; i++)
		C[i] = 1;
}
void output_bfs()
{
	for (int i = 0; i < nbfs; i++)
		cout << char(bfs[i] + 'A') << "  ";
}
void initS()
{
	sp = NULL;
}
int isEmptyS()
{
	if (sp == NULL)
		return 1;
	return 0;
}
int PushS(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = NULL;
	if (sp == NULL)
		sp = p;
	else
	{
		Node* q = sp;
		while (q->link != NULL)
			q = q->link;
		q->link = p;
	}
	return 1;
}
int PopS(int& x)
{

	if (sp != NULL)
	{
		Node* p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
void DFS(int s)
{
	PushQ(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v = -1, u = s;
	while (front != NULL)
	{
		if (v == n)
			PopQ(u);
		for (v = 0; v < n; v++)
		{
			if (a[u][v] != 0 && C[v] == 1)
			{
				PushQ(v);
				dfs[ndfs] = v;
				ndfs++;
				C[v] = 0;
				u = v;
				break;
			}
		}
	}
}
void outputGraph()
{
	for (int i = 0; i < n; i++)
	{
		cout << "Dinh " << i << " (" << vertex[i] << "): ";
		Node* p = First[i];
		while (p != NULL)
		{
			cout << p->info << " ";
			p = p->link;
		}
		cout << endl;
	}
}
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << vertex[a[i]] << " ";
}
void output_dfs()
{
	for (int i = 0; i < ndfs; i++)
	{
		cout << char(dfs[i] + 'A') << "  ";
	}
}
void BFS(int v)
{
	int w, p;
	PushS(v);
	C[v] = 0;
	while (sp != NULL)
	{
		PopS(p);
		bfs[nbfs] = p;
		nbfs++;
		for (w = 0; w < n; w++)
		{
			if (C[w] && a[p][w] == 1)
			{
				PushS(w);
				C[w] = 0;
			}
		}
	}
}
void BFS_DQ(int u)
{
	C[u] = 0;
	bfs[nbfs++] = u;
	for (int v = 0; v < n; v++)
	{
		if (a[u][v] != 0 && C[v] == 1)
			BFS_DQ(v);
	}
}
void search_BFS(int x, int v)
{
	int w, p;
	PushS(v);
	C[v] = 0;
	while (sp != NULL)
	{
		PopS(p);
		if (x == p)
		{
			cout << "\nx la dinh cua do thi";
			return;
		}
		for (w = 0; w < n; w++)
		{
			if (C[w] && a[p][w] == 1)
			{
				PushS(w);
				C[w] = 0;
			}
		}
	}
	cout << "\nx khong phai la dinh cua do thi";
}
int main()
{
	string fileName = "do_thi_1.txt";
	int choice, ndfs = 0;
	system("cls");
	cout << "------------------------- BAI TAP 8 - CHUONG 5 -------------------------" << endl;
	cout << "1.Doc file tu do thi 1" << endl;
	cout << "2.Duyet dinh do thi theo chieu rong DFS (theo Queue bang DSLKD)" << endl;
	cout << "3.Duyet dinh do thi theo chieu sau BFS (theo Stack bang DSLKD)" << endl;
	cout << "4.Duyet dinh do thi theo BFS bang de qui" << endl;
	cout << "5.Kiem tra X co phai la dinh cua do thi hay khong" << endl;
	cout << "6.Thoat" << endl;
	do
	{
		cout << "\nLua chon cua ban: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			inputGraphFromText();
			cout << "Ban vua nhap DANH SACH KE tu file: \n";
			outputGraph();
			break;
		case 2:
			cout << "\nKet qua duyet DFS theo Queue (voi dinh xuat phat la A):\n";
			initQ();
			khoitaochuaxet();
			DFS(0);
			output_dfs();
			break;
		case 3:
			cout << "\nKet qua duyet theo BFS theo Stack (voi dinh xuat phat la A):\n";
			initS();
			khoitaochuaxet();
			BFS(0);
			output_bfs();
			break;
		case 4:
			cout << "\nKet qua duyet BFS theo de qui (voi dinh xuat phat la A):\n";
			khoitaochuaxet();
			BFS_DQ(0);
			output_bfs();
			break;
		case 5:
			int x;
			cout << "Nhap dinh can tim voi dinh bat dau la A: ";
			cin >> x;
			initS();
			khoitaochuaxet();
			search_BFS(x, 0);
			break;
		default: choice = 6;
		}
	} while (choice != 6);
	system("pause");
	return 0;
}