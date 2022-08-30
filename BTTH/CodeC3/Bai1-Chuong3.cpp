//Bai 1- Chuong 3: Xep thu tu & Tim kiem
#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;
//1.1 Thu tuc khai bao danh sach co 100 phan tu
#define MAX 5000
int a[MAX];
int n;

//1.2 Thu tuc nhap danh sach
void input (int a[],int &n)
{

	cout << "Nhap vao so luong phan tu cua DS: ";
	cin >> n;
	for(int i= 0; i<n; i++)
	{
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
}

//1.2 Khoi tao danh sach tu dong
void init(int a[], int&n )
{
	cout << "Nhap vao so luong phan tu cua DS: ";
	cin >> n;
	for(int i=0; i<n; i++)
	{
		a[i] = rand() % 10000 + 1;
	}
	cout << "Danh sach ngau nhien la: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}
}
//1.3 Thu tuc xuat danh sach
void output(int a[],int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i]<<"   ";
	}
	cout << endl;
}

//copy array
void copyArray(int a[],int b[], int n)
{
	for(int i=0; i<n; i++)
	{
		b[i] = a[i];
	}
}
//1.4 Sap xep danh sach tang dan dung insertion sort
void Insertionsort(int a[], int n )
{
	int x, i, j;
	for(int i=0; i<n; i++)//(thay ghi i=1)
	{
		x = a[i];
		j = i - 1;//thay ghi j=i+1
		while(0<=j && x<a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}


//swap
void swap(int &a, int&b)
{
	int t;
	t = a;
	a = b; 
	b = t;
}
//1.5 Sap xep danh sach tang dan dung selection sort
void Selectionsort(int a[], int n)
{
	int min_pos, i, j;
	for( i=0; i<n-1;i++)
	{
		min_pos = i;
		for(j=i+1; j<n;j++)
		{
			if(a[j]<a[min_pos])
			{
				min_pos = j;
			}
		}
			swap(a[i], a[min_pos]);
     }
}


	//1.6 Sap xep tang dan dung Interchange Sort
void Interchangesort(int a[], int n)
	{
		for(int i=0; i<n-1; i++)
			for(int j=i+1;j<n;j++)
			    if(a[i]>a[j])
			       swap(a[i], a[j]);
	}

//1.7 Sap xep tang dan dung bubble sort
void bubblesort(int a[], int n)
{
	for (int i = 0; i <  n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])
	             swap(a[j], a[j - 1]);
}
//1.8 Sap xep tang dan dung quick sort
void quicksort(int a[],int l,int r)
{
	int x = a[(l + r) / 2];
	int i = l;
	int j = r;
	while(i<j)
	{
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
	 	if (i <= j)
	     {
		     swap(a[i], a[j]);
			i++; 
			j--;
	     }
	}
	if (l < j)
	{
		quicksort(a, l, j);
	}
	if (i < r)
	{
		quicksort(a, i, r);
	}
}
//1.9 Sap xep tang dan dung heap sort
void shift(int a[],int i,int n)
{
	int j = 2 * i + 1;
	if (j >= n) 
		return;
	if (j + 1 < n)
	{
		if (a[j] < a[j + 1])
			j++;
	}
	if (a[i] >= a[j])
		return;
	else
	{
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(a, j, n);
	}
}
void Heapsort(int a[],int n)
{
	int i = (n / 2) - 1; 
	while (i >= 0)
	{
		shift(a, i, n-1);//thay ghi n
		i--;
	}
	int r = n - 1;
	while(r>0) 
	{
		swap(a[0], a[r]);
		r--;
		if (r > 0)
			shift(a, 0, r);
	}
}

//main
	int main()
	{
		int b[MAX];
		clock_t start;
		double duration;
		int choice,x,i;
		system("cls");
		cout << "-------------Bai1-Chuong3-TH---------------\n";
		cout << "1.Khoi tao danh sach ngau nhien\n";
		cout << "2.Thu tuc nhap danh sach\n";
		cout << "3.Thu tuc xuat danh sach\n";
		cout << "4.Sap xep tang dan dung insertion sort\n";
		cout << "5.Sap xep tang dan dung selection sort\n";
		cout << "6.Sap xep tang dan dung interchange sort\n";
		cout << "7.Sap xep tang dan dung bubble sort\n";
		cout << "8.Sap xep tang dan dung quick sort\n";
		cout << "9.Sap xep tang dan dung heap sort\n";
		cout << "10.Ket thuc\n";
		do 
		{
			cout << "\n---Moi ban chon chuong trinh de thuc thi---";
			cin >> choice;
			switch (choice)
			{
			case 1: init(a,n);
				break;
			case 2: 
				input(a, n);
					cout << "Danh sach da duoc nhap xong ! \n";
					break;
			case 3:cout << "Danh sach dang co la:  \n";
				output(a, n);
				break;
			case 4: copyArray(a, b, n);
				start = clock();
				Insertionsort(b, n);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "Danh sach sau khi sap xep voi Insetion sort la:  \n";
					output(b, n);
				}
				if (duration > 0)
				{
					cout << "Thoi gian chay Insertion sort la:  " << duration * 1000000 << " miliseconds" << endl;
				}
				break;
			case 5: copyArray(a,b,n);
				start = clock();
				Selectionsort(b, n);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				if(n<100)
				{
				cout << "Danh sach sau khi sap xep voi Selection sort la:  \n";
				output(b, n);
				}
				if(duration>0)
				{
					cout << "Thoi gian chay selection sort la:  " << duration * 1000000 << " miliseconds" << endl;
				}
				break;
			case 6: copyArray(a, b, n);
				start = clock();
				Interchangesort(b, n);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "Danh sach sau khi sap xep voi Interchange sort la:  \n";
					output(b, n);
				}
				if (duration > 0)
				{
					cout << "Thoi gian chay Interchange sort la:  " << duration * 1000000 << " miliseconds" << endl;
				}
				break;
			case 7: copyArray(a, b, n);
				start = clock();
				bubblesort(b, n);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "Danh sach sau khi sap xep voi Bubble Selection sort la:  \n";
					output(b, n);
				}
				if (duration > 0)
				{
					cout << "Thoi gian chay Bubble sort la:  " << duration * 1000000 << " miliseconds" << endl;
				}
				break;
			case 8: copyArray(a, b, n);
				start = clock();
				quicksort(b, 0, n - 1);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "Danh sach sau khi sap xep voi Quick sort la:  \n";
					output(b, n);
				}
				if (duration > 0)
				{
					cout << "Thoi gian chay Quick sort la:  " << duration * 1000000 << " miliseconds" << endl;
				}
				break;
			case 9: copyArray(a, b, n);
				start = clock();
				Heapsort(b, n);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "Danh sach sau khi sap xep voi Heap sort la:  \n";
					output(b, n);
				}
				if (duration > 0)
				{
					cout << "Thoi gian chay Heap sort la:  " << duration * 1000000 << " miliseconds" << endl;
				}
				break;
			case 10: cout << "----------GOOD BYE !!!-----------\n";
				break;
			}
		}
		while (choice != 10);
		return 0;
	}
		