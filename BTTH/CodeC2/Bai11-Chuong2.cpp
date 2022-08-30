#include<iostream>
#include<conio.h>
using namespace std;
//Khai báo cấu trúc 
struct node {
    int info;
    node *link;
};
node *front,*rear;//front vi tri xoa, rear vi tri them

void init();
void Push(int x);
int Pop(int &x);
int isEmpty();
void deleteAllQueue();

int main(){
    int chon, x, in =0;
    do{
        system("cls");
        cout <<"Menu\n1. Khoi tao hang doi\n"
             <<"2. Them 1 ptu vao hang doi\n"
             <<"3. Lay 1 ptu ra khoi hang doi\n"
             <<"4. Kiem tra hang doi rong\n"
             <<"5. Xoa toan bo hang doi\n"
             <<"6. Thoat\nBan chon: ";
        cin >> chon;
        switch(chon){
            case 1: {
                init ();
                in =1;
                cout <<"Khoi tao hang doi thanh cong\n";
                break;
            }
            case 2:{
                if(in){
                    cout <<"Nhap gt can them: ";
                    cin >> x;
                    Push(x);
                    cout<<"Them vao hang doi thanh cong\n";
                }else{
                     cout<<" Vui long khoi tao hang doi\n";
                }
                break;
            }
            case 3:{
                if(in){
                    if(Pop(x))
                      cout <<"Gia tri dc lay ra la: "<< x <<endl;
                    else
                      cout <<"Khong the lay ra!!!\n";
                }else{
                      cout <<
                      "Vui long khoi tao hang doi\n";
                }
                break;
            }
            case 4:{
                if(in){
                   if(isEmpty)
                      cout <<"Hang doi rong\n";
                    else 
                       cout <<"Hang doi khong rong\n";
                }else{
                   cout <<"Vui long chon khoi tao hang doi\n";
                }
                break;
            }
            case 5:{
                if(in){
                    deleteAllQueue();
                    cout <<"Xoa thanh cong toan bo hang doi\n";
                }else{
                    cout <<"Hang doi khong co phan tu nen kh the xoa\n";
                }
                break;
            }
            default: 
                cout <<"Thoat\n";
        }
        _getch();
    }while( chon >=1 && chon <= 5);
    system("pause");
    return 0;
}
//Khoi tao queue rong
void init(){
    front =NULL;
    rear =NULL;
}

//Them ptu vao queue
void Push(int x){
    node *p= new node;
    p->info = x;
    p->link = NULL;
    if(rear == NULL)
       front = p;
    else 
       rear->link =p;
    rear = p;
}

//Lay ptu cua queue
int Pop( int &x){
    if(front != NULL){
        node *p = front;
        x = p->info;
        front =front ->link;
        if(front == NULL){
           rear =NULL; 
        }
        delete p;
        return 1;
    }
    return 0;
}

//Kiem tra queue rong
int isEmpty(){
    if(front == NULL){
        return 1;
    }
    return 0;
}

//Xoa het toan bo hang doi ket thuc/khong su dung
void deleteAllQueue(){
   if(front  != NULL) {
       while( front != NULL){
           //Xoa mot ptu dau danh sach
           node *p=front;
           front =front ->link;
           delete p;
        }
        cout << "Xoa toan bo hang doi thanh cong\n";
   }
}
