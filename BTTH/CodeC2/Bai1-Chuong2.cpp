#include<iostream>
 using namespace std;
#define MAX 100
//Cau 1.1
int a[MAX];
int n;
//Cau 1.2
void input(int a[], int& n)
{
cout << " Nhap vao so luong phan tu cua danh sach";
cin >> n;
for (int i = 0; i < n; i++)
{
cout << "a[" << i << "]=";
cin >> a[i];
}
}
//Cau 1.3
void output(int a[], int n)
{
for (int i = 0; i < n; i++)
{
cout << a[i] << "\t";
}
cout << endl;
}
//cau 1.4
int search(int a[], int n, int &x)
{
cout << "Nhap x can tim:";
cin >> x;
for (int i = 0; i < n; i++)
{
if (a[i] == x)return 1;
}
return 0;
}
//cau 1.5
int add(int a[], int& n, int x)
{
if (n < MAX)
{
a[n] = x;
n++;
return 1;
}
else
return 0;
}
//cau 1.6
int xoaptucuoi(int a[], int& n)
{
if (n > 0)
{
n--;
return 1;
}
return 0;
}
//cau 1.7
int xoaptutaivitri(int a[], int& n, int x)
{
cout << " Nhap vi tri can xoa";
cin >> x;
if (x >= 0 && x< n)
{
for (int j = 1; j < n; j++)
{
a[j] = a[j + 1];
}
n--;
return 1;
}
return 0;
}
//cau1.8
int timvaxoa(int a[], int& n, int x)
{
cout << " Nhap phan tu can tim va xoa ";
cin >> x;
for (int j = 0; j < n; j++)
{
if (a[j] == x)
{
xoaptutaivitri(a, n, j);
return 1;
}
}
return 0;
}
int main()
{
int choice = 0;
int x, n;
bool inp = false;
do {
cout << "1.Nhap danh sach" << endl
<< "2.Xuat danh sach" << endl
<< "3.Tim mot phan tu trong danh sach" << endl
<< "4.Them mot phan tu vao cuoi danh sach" << endl
<< "5.Xoa phan tu o cuoi danh sach" << endl
<< "6.Xoa phan tu tai vi tri i" << endl
<< "7.Tim mot phan tu trong danh sach va xoa" << endl
<< "8.Thoat" << endl;
cout << " Chon tinh nang:";
cin >> choice;
switch (choice)
{
case 1:
input(a, n);
inp = true;
break;
case 2:
if (inp == true)
{
cout << " danh sach da nhap la:";
output(a, n);
}
else
cout << "Nhap du lieu truoc" << endl;
break;
case 3:
if (inp == true)
{
if (search(a,n,x )== 1)
cout << " Tim thay " << x << "trong danh sach" << endl;
else
cout << " khong tim thay" << x << "trong danh sach" << endl;
}
else
cout << "Nhap du lieu truoc" << endl;
break;
case 4:
if (inp == true)
{
add(a, n, x);
}
else
cout << " Nhap du lieu truoc" << endl;
break;
case 5:
if (inp == true)
{
xoaptucuoi(a, n);
}
else
cout << " Nhap du lieu truoc" << endl;
break;
case 6:
if (inp == true)
{
xoaptutaivitri(a, n, x);
}
else
cout << " Nhap du lieu truoc" << endl;
break;
case 7:
if (inp == true)
{
timvaxoa(a, n, x);
}
else
cout << " Nhap du lieu truoc" << endl;
break;
}
} while (choice != 8);
return 0;
}


