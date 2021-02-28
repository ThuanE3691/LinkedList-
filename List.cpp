#include <iostream>
using namespace std;
typedef struct Node{//Dinh nghia 1 Node
	int data;
	Node* next;
}node;

Node* CreateAList(int value);//Tao List Liet Ket doi
Node* AddHead(Node* L,int value);//Them vao dau danh sach
Node* AddTail(Node* L,int value);//Them vao cuoi danh sach
Node* AddAt(Node* L,int value,int pos);//Them phan tu vao vi tri theo yeu cau
Node* DeleteHead(Node* L);//Xoa phan tu dau tien cua danh sach
Node* DeleteTail(Node* L);//Xoa phan tu cuoi cung cua danh sach
Node* DeleteAt(Node* L,int pos);//Xoa phan tu o vi tri yeu cau
void printList(Node* L);//Duyen Danh Sach tu truoc ra sau
int LengthList(Node* List);//In do dai hien tai cua List


int LengthList(Node* List)
{
    int length = 0;
    for (node* p = List;p != NULL;p = p->next)
        length++;
    return length;
}

Node* CreateAList(int value)
{
    Node* temp = new node;
    temp->data = value;
    temp->next = NULL;
    return temp;
}

Node* AddHead(Node* L,int value)
{
    node* temp = new node;
    temp->data = value;
    temp->next = L;
    L = temp;
    return L;
}

Node* AddTail(Node* L,int value)
{
	node* temp = new node;
	node* p = L;
	while (p->next != NULL)
		p = p->next;
	temp->data = value;
	temp->next = NULL;
	p->next = temp;
	return L;
}

Node* AddAt(Node* L,int value,int pos)
{
	if (pos == 0) return AddHead(L,value);
	else if (pos == LengthList(L)) return AddTail(L,value);
	else
	{
		node* p = L;
		for (int k = 0;k < pos - 1;k++)
			p = p->next;
		node* temp = new node;
		temp->data = value;
		temp->next = p->next->next;
		p->next = temp;
		return L;
	}
}

Node* DeleteHead(Node* L)
{
	node* p = L;
	p = p->next;
	delete(L);
	return p;
}

Node* DeleteTail(Node* L)
{
	node* p = L;
	while (p->next->next != NULL)
		p = p->next;
	delete(p->next);
	p->next = NULL;
	return L;
}

Node* DeleteAt(Node* L,int pos)
{
	if (pos == 0) return DeleteHead(L);
	else if (pos == LengthList(L)) return DeleteTail(L);
	else
	{
		node* p = L;
		for (int k = 0;k < pos-1;k++)
			p = p->next;
		node* temp = p->next;
		p->next = p->next->next;
		delete(temp);
		return L;
	}
}

void printList(Node* List)
{
	cout<<"\n\nDuyen Danh sach Lien Ket Don : "<<endl;
	for (node* p = L;p != NULL;p = p->next)
		cout<<p->data<<" ";
}

int main()
{
	int n,x,k,index=1,choice,pos,value;
	Node* List;
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
