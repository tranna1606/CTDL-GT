#include<iostream>
using namespace std;

//Cau 3.1. Khai bao cau truc danh sach
struct Node {
    int info;
    Node *link;

};
Node *first;

//Cau 3.2.Khoi tao danh sach rong
void Init(){
    first = NULL;
}

//Cau 3.3.Xuat danh sach 
void Process_list(){
    Node *p = first;
    while(p != NULL){
        cout << p->info << "/t";
        p=p->link;
    }
    cout << endl;

}

//Cau 3.4.Tim ptu trong ds
Node *Search (int x){
    Node *p = first;
    while (p != NULL && p->info == x){
        p=p->link;
    }
    return p;
}

//Cau 3.5.Them dau danh sach
void Insert_first(int x){
    Node *p = new Node;
    p->info = x;
    p->link = first;
    first =p;
}

//Cau 3.6.Xoa ptu dau danh sach
int Delete_first(){
    if(first != NULL){
        Node *p= first;
        first= first ->link;
        delete p;
        return 1;
    }
    return 0;
}

//Cau 3.7.Them cuoi danh sach
void Insert_last(int x){
    Node *p= new Node;
    p->info =x;
    p->link =NULL;
    if(first = NULL){
        first = p;
    }else{
        Node * q= first;
        while( q->link != NULL){
            q=q->link;
        }
        q->link =p;
    }
}

//Cau 3.8.Xoa phan tu cuoi danh sach
int Delete_last(){
    if(first !=NULL){
        Node *p, *q;
        p=first, q=first;
        if( p!= NULL){
            while(p->link !=NULL){
                q=p; p=p->link;
            }
        }
        if(p != first){
            q->link = NULL;
        }
        else first = NULL;
        delete p;
        return 1;
    }
    return 0;
}

//Cau 3.9.Tim va Xoa
int SearchAndDelete(int x){
    if(first != NULL){
        Node *p,*q;
        p=first;
        q=first;
        while(p->info != x && p->link !=NULL){
            q=p;
            p=p->link;
        }
        if( p != first && p->link != NULL){
            //ptu giua ds
            if(p->link != NULL){
                q->link= p->link;
            }
            else{
                q->link =NULL;
            }
            delete p;
        }
        else if( p== first)
        {
            //ptu dau ds
            first = p->link;
            delete p;
        }
        else if(p->link == NULL && p->info ==x){
            //ptu cuoi ds
            q->link = NULL;
            delete p;
        }
        return 1;
    }
    return 0;
}

int main (){
    Node *p;
    int x, i, chon;
    
        
            cout << "------------BT3,Chuong 2-DSLK DON------------ "<< endl;
            cout << "1.Khoi tao DSLK rong"<< endl;
            cout << "2.Them ptu vao dau danh sach "<< endl;
            cout << "3.Them ptu vao cuoi danh sach "<< endl;
            cout << "4.Xoa ptu o dau danh sach "<< endl;
            cout << "5.Xoa ptu o cuoi danh sach "<< endl;
            cout << "6.Xuat DSLK don"<< endl;
            cout << "7.Tim ptu gia tri x trong DSLK don"<< endl;
            cout << "8.Tim va xoa"<< endl;
            cout << "9.KET THUC "<< endl;
    do{
        cout <<"Vui long chon so thuc hien : ";
        cin >> chon;
        switch(chon){
            case 1: 
                 Init();
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
                p=Search(x);
                if(p=NULL)
                   cout << "Khong tim thay x= "<<x<<"trong DSLK!!!!"<<endl;
                else{
                    cout <<"Tim thay x=" << x<< "trong DSLK!!!!!"<<endl;
                }
                break;
            case 8:
                cout << "Vui long nhap gt  can tim x= ";
                cin >> x;
                i= SearchAndDelete(x);
                if( i== 0){
                    cout <<" Khong tim thay x="<<x<<"trong DSLK !!!!!"<< endl;
                }else{
                    cout <<"Tim thay x="<< x<< " trong DSLK, va da xoa!!!"<< endl;
                    cout << "DS sau khi xoa la :"<< endl;
                    Process_list();
                }
                break;
            case 9:
                cout << "Ban chon ket thuc ";
                break;
            default : break;
        }

    }while(chon != 9);
    system("pause");
    return 0;
}
