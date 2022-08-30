#include<iostream>
using namespace std;

//1.Khai bao cau truc danh sach
struct node {
    int info;
    node *next;
    node *pre;
};
node *first, *last;

//2.Khoi tao danh sach rong
void init(){
    first =NULL;
    last = NULL;
}

//3.Xuat cac ptu trong danh sach
void Process_list(){
    node *p= first;
    while( p != NULL){
        cout << p->info << endl;
        p=p->next;
    }
}

//4.Tim ptu trong danh sach
node *search(int x){
    node *p= first;
    while( (p != NULL) && (p->info !=x)){
        p=p->next;
    }
    return p;
}


//5.Them dau danh sach 
void Insert_first(int x){
    node *p=new node;
    p->info = x;
    p->next= first;
    p->pre= NULL;
    if(first != NULL){
        first->pre= p;
    }else{
        last =p;
    }
    first=p;
}


//6.Them cuoi danh sach 
void Insert_last(int x){
    node *p=new node;
    p->info = x;
    p->next= NULL;
    p->pre= last;
    if(last != NULL){
        last->next= p;
    }else{
        first =p;
    }
    last=p;
}

//7.Xoa dau danh sach
int Delete_first(){
    if(first != NULL){
        node *p=first;
        first = first->next;
        delete p;
        if(first != NULL){
            first ->pre =NULL;
        }else{
            last = NULL;
        }

        return 1;
    }
    return 0;
}

//8.Xoa cuoi danh sach 
int Delete_last(){
    if(last != NULL){
        node *p=last;
        last = last->pre;
        delete p;
        if(last != NULL){
            last ->next =NULL;
        }else{
            first= NULL;
        }

        return 1;
    }
    return 0;
}

int main (){
    node *p;
    int x, i, chon;
    
        
            cout << "------------BT3,Chuong 2-DSLK DOI------------ "<< endl;
            cout << "1.Khoi tao DSLK rong"<< endl;
            cout << "2.Them ptu o dau danh sach "<< endl;
            cout << "3.Them ptu vao cuoi danh sach "<< endl;
            cout << "4.Xoa ptu o dau danh sach "<< endl;
            cout << "5.Xoa ptu o cuoi danh sach "<< endl;
            cout << "6.Xuat DSLK doi"<< endl;
            cout << "7.Tim ptu gia tri x trong DSLK doi"<< endl;
            cout << "8.KET THUC "<< endl;
    do{
        cout <<"Vui long chon so thuc hien : ";
        cin >> chon;
        switch(chon){
            case 1: 
                 init();
                 cout <<" Ban vua khoi tao thanh cong DSLK don !!!!!!1";
                 break;
            case 2 : 
                cout << "Vui long nhap x=";
                cin >> x;
                Insert_first(x);
                cout << "Sau khi them dau ds voi gt x="<<x<<"la: ";
                Process_list();
                break;
            case 3 : 
                cout << "Vui long nhap x=";
                cin >> x;
                Insert_last(x);
                cout << "Sau khi them cuoi ds voi gt x="<<x<<"la: ";
                Process_list();
                break;
            case 4: 
                i=Delete_first();
                if( i==0){
                    cout << " Xoa khong thanh cong, DS rong !! "<<endl;
                }
                else{
                    cout <<"Xoa thanh cong ptu dau ds! DS sau khi xoa la : "<< endl;
                    Process_list();
                }
                break;
            case 5: 
                i=Delete_last();
                if( i==0){
                    cout << " Xoa khong thanh cong, DS rong !! "<<endl;
                }
                else{
                    cout <<"Xoa thanh cong ptu cuoi  ds! DS sau khi xoa la : "<< endl;
                    Process_list();
                }
                break;
            case 6:
                cout << "DSLK hien tai la: "<< endl;
                Process_list ();
                break;
            case 7:
                cout << "Vui long nhap gt can tim x= ";
                cin >> x;
                p=search(x);
                if(p==NULL)
                   cout << "Khong tim thay x= "<<x<<"trong DSLK!!!!"<<endl;
                else{
                    cout <<"Tim thay x=" << x<< "trong DSLK!!!!!"<<endl;
                }
                break;
            
            case 8:
                cout << "Ban chon ket thuc ";
                break;
            default : break;
        }

    }while(chon != 8);
    system("pause");
    return 0;
}
