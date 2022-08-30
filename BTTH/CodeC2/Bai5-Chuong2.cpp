
#include<iostream>
#include<conio.h>
using namespace std;
const int MAX =100;


void init(int a[], int &sp);
int Push(int a[], int &sp, int x);
int Pop(int a[], int &sp, int x);
int isFull(int a[], int sp);
int isEmpty(int a[], int sp);
void xuatStackTuDinh(int a[], int sp);



int main(){
    
    int a[MAX]; 
    int sp;  
    int chon, x, in = 0,np;
    do{
        system("cls");
        cout << "Menu\n1. Khoi tao stack\n"
            <<"2. Them 1 ptu vao  stack\n"
            <<"3. Lay 1 ptu trong  stack\n"
            <<"4. Kiem tra stack day\n"
            <<"5. Kiem tra stack rong\n"
            <<"6. Xuat stack tu dinh den day stack\n"
            <<"7. Thoat\n Ban chon: ";
            
        cin >> chon;
        switch(chon){
            case 1:
                 init(a, sp);
                 in =1;
                 cout <<"Khoi tao stack thanh cong\n";
                 break;
            case 2:
                if(in)// nếu đã khởi tạo rồi
                {
                    cout << "Nhap gia tri can them vao  stack: ";
                    cin >> x;
                    if(Push(a,sp,x))
                        cout << "Them vao stack thanh cong\n";
                    else
                        cout <<"Them vao stack khong thanh cong\n";

                }else
                    cout << " Vui long chon khoi tao stack\n";
                break;
            case 3:
                 if(in)// nếu đã khởi tạo rồi
                { 
                    if(Pop(a,sp,x))
                        cout <<"Phan tu vua lay ra khoi stack la: "<<x<<endl;
                    else
                        cout <<"Khong lay duoc phan tu tu dinh cua stack\n";

                }else
                    cout << " Vui long chon khoi tao stack\n";
                break;
            case 4:
                 if(in)// nếu đã khởi tạo rồi
                {
                      if(isFull(a,sp))
                         cout << "Stack day\n";
                      else
                         cout <<"Stack chua day\n";
                }else
                    cout << " Vui long chon khoi tao stack\n";
                break;
            case 5:
                 if(in)// nếu đã khởi tạo rồi
                {
                    if(isEmpty(a,sp))
                         cout << "Stack rong\n";
                      else
                         cout <<"Stack khong rong\n";

                }else
                    cout << " Vui long chon khoi tao stack\n";
                break;
            case 6: 
                if(in){
                    if(!isEmpty(a,sp)){
                        //xuất stack từ đỉnh
                        cout <<" Cac ptu trong stack tu dinh xuong la:\n";
                        xuatStackTuDinh(a,sp);
                    }
                    else
                       cout <<"Stack rong nen khong co ptu luu tru\n";
                }
                else
                   cout << "Stack chua duoc khoi tao\n";
                 break;
            
            default:
                 cout <<"Ban chon thoat\n"; 
                
        }
        _getch();
    }while(chon >=1 && chon <=6);
  return 0;

}
void init(int a[], int &sp){
    sp= -1;
}
int Push(int a[], int &sp, int x){
     if(sp <  MAX-1){
         a[++sp] = x;
         return 1;
     }
    return 0;
}
int Pop(int a[], int &sp, int x){
    if( sp !=-1){
        x = a[sp--];
        return 1;
    }
    return 0;
}
int isFull(int a[], int sp){
    if(sp == MAX -1){
        return 1;
    }
    return 0;
}
int isEmpty(int a[], int sp){
    if(sp == -1)
        return 1;
    return 0;
}
void xuatStackTuDinh(int a[], int sp){
    for(int i=sp; i >= 0; i--){
         cout << a[i]<<endl;
      cout << endl;
    }
}
