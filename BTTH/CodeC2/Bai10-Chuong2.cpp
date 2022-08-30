#include<iostream>
#include<conio.h>
using namespace std;
//10.1-Khai báo cấu trúc stack
struct node{
   int info;
   node *link;
};
node *sp;//dinh cua stack
void init();
void Push(int x);
int Pop(int &x);
int isEmpty();
void process_Stack();
void delete_Stack();
int convert10to2(int tp);

int main(){
    int chon, x, in= 0, n;
    do{
        system("cls");
        cout <<"Menu stack bang ds lk don\n"
             <<"1. Khoi tao stack\n"
             <<"2. Them 1 ptu vao stack\n"
             <<"3. Lay 1 ptu ra khoi stack\n"
             <<"4. Xuat cac ptu trong stack\n"
             <<"5. Kiem tra stack rong\n"
             <<"6. Chuyen he 10 sang he 2\n"
             <<"7. Thoat\nBan chon: ";
        cin >> chon;
        switch(chon){
            case 1:{
                init();
                cout <<" Khoi tao stack thanh cong\n";
                in =1;
                break;
            }
            case 2:{
                if(in){
                   cout <<"Nhap gt can them: ";
                   cin >> x;
                   Push(x);
                   cout  <<" Them vao stack thanh cong\n";
                   cout<<"DS sau khi them la: ";
                   process_Stack();
                }
                else{
                    cout <<"Vui long chon khoi tao stack\n";
                }
                break;
            }
            case 3:{
                 if(in){
                      if(Pop(x)==1){
                          cout <<"Gia tri vua lay ra khoi stack la:  "<< x << endl;
                          cout<<"DS sau khi lay la: ";
                          process_Stack();
                      }else{
                          cout <<"Qua trinh lay ptu that bai";
                      }
                }
                else{
                    cout <<"Vui long chon khoi tao stack\n";
                }
                break;
            }
            case 4:{
                if(in){
                     process_Stack();
                     cout << endl;
                }
                else{
                    cout <<"Vui long chon khoi tao stack\n";
                }
                break;
            }
            case 5:{
                if(in){
                      if(isEmpty()){
                          cout <<"Stack rong\n";
                      }else
                      cout <<"Stack khong rong\n";
                }
                else{
                    cout <<"Vui long chon khoi tao stack\n";
                }
                break;
            }
            case 6:{
                cout <<"Nhap gt he thap phan muon chuyen sang nhi phan: ";
                cin >> x;
                n = convert10to2(x);
                if(n != -1){
                    cout << "He nhi phan tuong ung la: "<< n << endl; 
                }else{
                    cout <<"Qua trinh chuyen khong thanh cong!!!";
                }
                
                break;

            }
            default : 
            {
                delete_Stack();
                cout <<"Thoat\n";
            }
        }
        _getch();
    }while(chon >=1 && chon <=6);
    return 0;
}



//10.2-Khởi tạo stack rỗng
void init(){
    sp = NULL;
}

//10.3-Kiểm tra stack rỗng
int isEmpty(){
    if(sp == NULL)
       return 1;
    return 0;
}

//10.5-Thêm một phần tử vào stack
void Push(int x){
    node *p= new node;
    p->info =x;
    p->link =sp;
    sp = p;
}

//10.6-Xóa một phần tử trong stack
int Pop(int &x){
    if(sp != NULL){
        node *p=sp;
        x= p->info;
        sp =sp->link;
        delete p;
        return 1;
    }
    return 0;
}

//10.7-Xuất ptu của stack
void process_Stack(){
    cout << " Cac ptu trong stack tu dinh la :\n ";
    node *p =sp;
    while( p!= NULL){
        cout << p->info << "<----";
        p = p->link;
    }
    cout<<endl;
}

void delete_Stack(){
    while( sp != NULL){
        node *p= sp;
        sp=sp->link;
        delete p;
    }
    cout <<" Xoa toan bo stack thanh cong!\n";
}

//10.8-Đổi thập phân sang nhị phân
int convert10to2(int tp){
    if( sp != NULL)
       delete_Stack();
    int np =0;
    while( tp != 0){
        int du = tp % 2;
        Push(du);
        tp /= 2;
    }
    int so;
    while( sp != NULL){
        if(!Pop(so)){
            return -1;
        }
        np= np *10 +so;
    }
    return np;
}

