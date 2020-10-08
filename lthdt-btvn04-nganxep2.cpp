//Ho va ten: To Nam Truong
//MaSV:637960
//Lop: K63CNPMP
//De bai:
 
#include<iostream>
#include<stdio.h>

using namespace std;

//khai bao class
class Stack
{
    private:
	struct node
	{
	    int infor;
	    node *link;
	} *T;

    public:
	//Ham tao
	Stack();
	Stack(const Stack &s);
	//Ham huy
	~Stack();
	//Ham chong toan tu gan
	Stack operator=(const Stack &right);
	//Cac ham thanh vien cai dat phep toan
	void push(int x);
	int pop();
	bool isEmpty();

};

//===Chuong trinh chinh=== 
int main()
{
     //Tao doi tuong ngan xep 
    Stack s;

    //Khai bao bien
    int n, thuong;

    //Nhap gia tri
    cout<<"Nhập vào số nguyên dương: ";
    cin>>n;
    
    //Chuyen doi sang he 2
    thuong=n;
    while(thuong)
    {
	s.push(thuong%2);
	thuong/=2;
    }
    
    //Dua ra man hinh
    cout<<"\nSố nhị phân của "<<n<<" là: ";
    while(!s.isEmpty())
    {
	cout<<s.pop();
    }
    
    cout<<endl;
    return 0;
}

//===Dinh nghia ham===
Stack::Stack():T(NULL)
{
}
Stack::Stack(const Stack &s):T(NULL)
{
    node *P=s.T,*N,*Bottom;

    //tạo nut moi
    while(P)
    {
	N= new node;
	N->infor = P->infor;
	N->link = NULL;
	//Noi nut moi vao ngan xep
	if(T==NULL)
	{
	    T = Bottom = N;
	}
	else
	{
	    Bottom->link = N;
	    Bottom = N;
	}
    }
}
Stack::~Stack()
{
    node *P;
    while(T)
    {
	node *P=T;
	T=T->link;
	delete P;
    }
}
void Stack::push(int x)
{    
    //tạo nut moi
    node *N = new node;
    N->infor = x;
    N->link = NULL;

    if(T==NULL) T=N;
    else
    {
	//cho P trỏ tới nút cuối danh sach
	node *P = T;
	while(P->link)
	{
	    P = P->link;	
	}
	//nối nút mới vào cuối danh sách
	P->link = N;
    }
}
    
int Stack::pop()
{
    //Trường hợp năng xếp rỗng
    if(T==NULL) 
    {
	cout<<"Stack rỗng!";
	return -1;
    }
    //Trường hợp ngăn xếp chỉ có 1 phần tử
    else if(T->link==NULL)
    {
	int x = T->infor;//giữ lại giá trị trả về
	T = NULL;
	return x;
    }
    //Trường hợp còn lại: có từ 2 phần tử trở lên
    else
    {
	//Khai báo biến
	node *P = T, *Bottom = P->link;
	
	//Cho Bottom trỏ đến nút cuối của ngăn xếp
	while(Bottom->link)
	{
	    P = Bottom;
	    Bottom = Bottom->link;
	}
	int x = Bottom->infor;
	P->link = NULL;
	delete Bottom;
	return x;
    }
}

bool Stack::isEmpty()
{
    return (T==NULL);
}
//
Stack Stack::operator=(const Stack &right)
{       
    //khai bao bien
    node *P,*N,*Bottom;
    
    //xoa stack
    while(T)
    {
	P = T;
	T = T->link;
	delete P;
    }
    
    //sao chep
    P = right.T;
    while(P)
    {
	N = new node;
	N->infor = P->infor;
	N->link = NULL;
	//Noi nut moi vao ngan xep
	if(T==NULL)
	{
	    T = Bottom = N;
	}
	else
	{
	    Bottom->link = N;
	    Bottom = N;
	}
    }
}
