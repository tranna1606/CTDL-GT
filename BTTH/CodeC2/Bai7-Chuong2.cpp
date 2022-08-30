//cai dat queue bang danh sach dac theo pp tinh tien
#include<iostream>
#include<conio.h>
using namespace std;
//7.1- Khai bao cau truc queue
#define MAX 100
int a[MAX];
int front, rear;

void init(int a[], int &front, int &rear);
int Push(int a[], int &front, int &rear, int x);
int Pop(int a[], int &front, int rear, int &x);
int isFull(int a[], int front, int rear);
int isEmpty(int a[], int front, int rear);

int main(){
    int chon, x, in =0;
    do{
        system("cls");
        cout <<"Menu hang doi queue\n"
             <<"1. Khoi tao hang doi\n"
             <<"2. Them 1 ptu vao hang doi\n"
             <<"3. Lay 1 ptu ra khoi hang doi\n"
             <<"4. Kiem tra queue rong\n"
             <<"5. Kiem tra queue day\n"
             <<"6. Thoat\nBan chon: ";
        cin >> chon;
        switch(chon){
            case 1: {
                init(a,front,rear);
                in =1;
                cout <<"Khoi tao hang doi thanh cong\n";
                break;
            }
            case 2: {
                if(in){
                   cout <<"Nhap gt can them vao hang doi: ";
                   cin >> x;
                   if(Push(a,front,rear,x))
                      cout <<"Them thanh cong\n";
                    else{
                        cout <<"Hang doi khong the them\n";
                    }
                }else{
                    cout <<" Vui long chon khoi tao hang doi!!!!\n";
                }
                break;
            }
            case 3: {
                if(in){
                    if(Pop(a,front,rear,x))
                       cout <<"Gia tri vua lay ra khoi hang doi la: "<< x << endl;
                    else{
                        cout <<"Qua trinh that bai!!!\n";
                    }
                }else{
                    cout <<" Vui long chon khoi tao hang doi!!!!\n";
                }
                break;
            }
            case 4:
                 if(in)// nếu đã khởi tạo rồi
                {
                      if(isFull(a,front,rear))
                         cout << "Stack day\n";
                      else
                         cout <<"Stack chua day\n";
                }else
                    cout << " Vui long chon khoi tao stack\n";
                break;
            case 5:
                 if(in)// nếu đã khởi tạo rồi
                {
                    if(isEmpty(a,front,rear))
                         cout << "Stack rong\n";
                      else
                         cout <<"Stack khong rong\n";

                }else
                    cout << " Vui long chon khoi tao stack\n";
                break;
            default :
                cout << "Thoat\n";

        }


     _getch();
    }while(chon >=1 && chon <=5);
    
    return 0;
}

//7.2-Khoi tao queue rong
void init(int a[], int &front, int &rear){
    front = rear =-1;
}

//7.3-Them 1 ptu vao queue
int Push(int a[], int &front, int &rear, int x){
    if(rear-front == MAX -1)
       return 0;
    if(front = -1 )
        front = 0;
    if(rear == MAX -1){
        for(int i=front; i <=rear; i++)
            a[i-front] = a[i];
        rear =MAX -1-front;
        front =0;
    }
    a[++ rear] =x;
    return 1;
}

//7.4-Xoa 1 ptu trong queue
int Pop(int a[], int &front, int rear, int &x){
    if(front != -1){
        x= a[front++];
        if(front > rear){// chua tran
            front =rear =-1;
        }
        return 1;
    }
    return 0;
}

//7.5-Kiem tra queue rong 
int isEmpty(int a[],int front, int rear){
    if(front == rear== -1)
       return 1;
    return 0;
}
//7.6-Kiem tra queue day chua
int isFull(int a[], int front, int rear){
   if((front ==0 && rear ==MAX -1) || (front -rear ==1))
        return 1;
    return 0;
    
}
