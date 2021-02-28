#include <iostream>

using namespace std;
typedef struct Node{//Dinh nghia 1 Node
	int data;
	Node* next;
	Node* prev;
}node;

typedef struct DoubleList{//Dinh nghia Danh sach Liet ket doi
	Node* head;
	Node* tail;
}DL;

DL* CreateAList(int value);//Tao List Liet Ket doi
DL* AddHead(DL* L,int value);//Them vao dau danh sach
DL* AddTail(DL* L,int value);//Them vao cuoi danh sach
DL* AddAt(DL* L,int value,int pos);//Them phan tu vao vi tri theo yeu cau
DL* DeleteHead(DL* L);//Xoa phan tu dau tien cua danh sach
DL* DeleteTail(DL* L);//Xoa phan tu cuoi cung cua danh sach
DL* DeleteAt(DL* L,int pos);//Xoa phan tu o vi tri yeu cau
void preList(DL* L);//Duyen Danh Sach tu truoc ra sau
void EndList(DL* L);//Duyen Danh sach tu sau ra truoc
void printList(DL* L);//In Danh Sach theo 2 cach dueyt
int LengthList(DL* List);//In do dai hien tai cua List


int LengthList(DL* List)
{
    int length = 0;
    for (node* p = List->head;p != NULL;p = p->next)
        length++;
    return length;
}

DL* CreateAList(int value)
{
	DL* L = new DL;
	L->head = new node;
	L->head->data = value;
	L->head->next = NULL;
	L->head->prev = NULL;
	L->tail = L->head;
    return L;
}

DL* AddHead(DL *L,int value)
{
    node* temp = new node;
   	temp->data = value;
   	temp->next = L->head;
   	temp->prev = NULL;
   	L->head->prev = temp;
   	L->head = temp;
   	return L;
}

DL* AddTail(DL *L,int value)
{
	node* temp = new node;
	temp->data = value;
	temp->next = NULL;
	temp->prev = L->tail;
	L->tail->next = temp;
	L->tail = temp;
	return L;
}

DL* AddAt(DL *L,int value,int pos)
{
	if (pos == 0) return AddHead(L,value);
	else if (pos == LengthList(L)) return AddTail(L,value);
	else
	{
		node* p = L->head;
		for (int k = 0;k < pos -1;k++)
			p = p->next;
		node* temp = new node;
		temp->data = value;
		temp->prev = p;
		temp->next = p->next;
		p->next->prev = temp;
		p->next = temp;
		return L;
	}
}

DL* DeleteHead(DL* L)
{
	node* p = L->head->next;
	node* temp = L->head;
	p->prev = NULL;
	L->head = p;
	delete(temp);
	return L;
}

DL* DeleteTail(DL* L)
{
	node* p = L->tail->prev;
	node* temp = L->tail;
	p->next = NULL;
	L->tail = p;
	delete(temp);
	return L;
}

DL* DeleteAt(DL* L,int pos)
{
    if (pos == 0) return DeleteHead(L);
    else if (pos == LengthList(L)) return DeleteTail(L);
    else
    {
        node* p = L->head;
        for (int k = 0;k < pos-1;k++)
            p = p->next;
        node* temp = p->next;
        node* p2 = temp->next;
        p2->prev = p;
        p->next = p2;
        delete(temp);
        return L;
    }
}

void preList(DL* L)
{
	for (node* p = L->head;p != NULL;p = p->next)
		cout<<p->data<<" ";
}

void EndList(DL* L)
{
	for (node* p = L->tail;p != NULL;p = p->prev)
		cout<<p->data<<" ";
}

void printList(DL* List)
{
	cout<<"\n\nDuyen Danh sach Lien Ket Doi tu truoc ra sau: "<<endl;
	preList(List);
	cout<<"\n\nDuyen Danh sach Lien Ket Doi tu sau ra truoc: "<<endl;
	EndList(List);
}

int main()
{
	int n,x,k,index=1,choice,pos,value;
	DL* List;
	cout<<"Nhap so phan tu cua List: ";
	cin>>n;
	cout<<"\n\nSo Phan tu cua List La: "<<n;
	cout<<"\n\nNhap Gia tri cua phan tu thu "<<index++<<": ";
	cin>>x;
	List = CreateAList(x);
	for (int i = 1;i < n;i++)
	{
		cout<<"\n\nNhap Gia tri cua phan tu thu "<<index++<<": ";
		cin>>x;
		List = AddTail(List,x);
	}
	do{
	printList(List);
	cout<<"\n\nBan muon lam gi ";
	cout<<"\n\n1.Them phan tu vao List. ";
	cout<<"\n\n2.Xoa Phan tu Khoi List. ";
	cout<<"\n\n3.In ra do dai cua List ";
	cout<<"\n\n4.Thoat Chuong trinh ";
	cout<<"\n\nNhap Lua chon: ";
	cin>>choice;
	cout<<"\n\nLua chon cua ban la : ";
	Choice:
	switch (choice){
            case 1:
            cout<<"Them Phan Tu vao List";
            cout<<"\n\nNhap Phan Tu muon them: ";
            cin>>value;
            cout<<"\n\nNhap Vi tri muon them vao List: ";
            cin>>pos;
            while (pos < 0 || pos > LengthList(List)){
            cout<<"\n\nVi tri khong hop le vui long nhap lai ";
            cin>>pos;
            }
            cout<<"\n\nPhan tu muon them va vi tri them vao la: "<<value<<" "<<pos;
            List = AddAt(List,value,pos);
            break;
            case 2:
            cout<<"Xoa Phan tu Khoi List";
            cout<<"\n\nNhap Vi tri muon xoa khoi List: ";
            cin>>pos;
            while (pos < 0 || pos > LengthList(List)){
            cout<<"\n\nVi tri khong hop le vui long nhap lai ";
            cin>>pos;
            }
            cout<<"\n\nVi tri muon xoa la: "<<pos;
            List = DeleteAt(List,pos);
            break;
            case 3:
            cout<<"In ra do dai cua List ";
            cout<<"\n\nDo dai cua List la: "<<LengthList(List);
            break;
            case 4:
            cout<<"Ban da chon thoat khoi chuong trinh.Cam on vi da su dung chuong trinh";
            break;
            default:
            cout<<"Ban da nhap sai lua chon vui long nhap lai.";
            cin>>choice;
            goto Choice;
            }
	}while(choice != 4);
	delete(List);
}
