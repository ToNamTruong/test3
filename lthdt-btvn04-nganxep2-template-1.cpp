//Ho va ten: To Nam Truong
//MaSV:637960
//Lop: K63CNPMP
//De bai:
 
#include<iostream>
#include<stdio.h>

using namespace std;

//khai bao class
template <class Type>
class Stack
{
    private:
	struct node
	{
	    Type infor;
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
	void push(Type x);
	Type pop();
	bool isEmpty();

};

//===Chuong trinh chinh=== 
int main()
{
    //Tao một đối tượng ngăn xếp có phần tử là số nguyên
    Stack<int> s;
    
    //Tao một đối tượng ngăn xếp có phần tử là ký tự
    Stack<char> s2;

    //Khai báo biến
    int n,thuong,du;

    //Nhập giá trị
    cout<<"Nhập vào số nguyên dương: ";
    cin>>n;

    //Chuyển đổi sang hệ 2
    thuong=n;
    while(thuong)
    {
	s.push(thuong%2);
	thuong/=2;
    }

    //Chuyen doi sang he 16
    thuong=n;
    while(thuong)
    {
	du = thuong%16;
	
	//Chuyen so du thanh chu so he 16
	if(du<10) s2.push(du+48);
	else s2.push(du+55);
	
	//Thuong bang thuong moi
	thuong/=16;
    }

    //hiện thị kết quả ra màn hình
    cout<<"\nSố nhị phân của "<<n<<" là: ";
    while(!s.isEmpty())
    {
	cout<<s.pop();
    }
    
    cout<<"\n\nSố hex của "<<n<<" là: ";
    while(!s2.isEmpty())
    {
	cout<<s2.pop();
    }
    
    cout<<endl;
    return 0;
}

//===Dinh nghia ham===
template <class Type>
Stack<Type>::Stack():T(NULL)
{
}

template <class Type>
Stack<Type>::Stack(const Stack &s):T(NULL)
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

template <class Type>
Stack<Type>::~Stack()
{
    node *P;
    while(T)
    {
	node *P=T;
	T=T->link;
	delete P;
    }
}

template <class Type>
void Stack<Type>::push(Type x)
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

template <class Type>   
Type Stack<Type>::pop()
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
    //Trường hợp có từ 2 phần tử trở lên
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

template <class Type>
bool Stack<Type>::isEmpty()
{

    return T==NULL;
}

template <class Type>
Stack<Type> Stack<Type>::operator=(const Stack &right)
{    
    
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
