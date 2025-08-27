//menu driven program
#include<iostream>
using namespace std;
void push(int &top,int st[],int n)
{		
cout<<"Enter number of  elements u want to insert in the stack "<<endl;
	int p;
	cin>>p;
	if(p>n)
	{
		cout<<"invalid";
		
	}
	else if(top==n-1)
	{
		cout<<"not possible";
	} 
	else
	{	for(int i=0;i<p;i++)
	{	int d=0;
		top=top+1;
		cout<<"Enter the element "<<endl;
		cin>>d;
		st[top]=d;
		
	}}

}
void pop(int &top,int st[],int n)
{
	cout<<"Enter elements u want to delete from the stack ";
	int p;
	cin>>p;
	if(top==-1)
	{
		cout<<"not possible";
	} 
	else
	{	for(int i=0;i<p;i++)
	{	
		top=top-1;
	}
}}
void isfull(int &top,int st[],int n)
{
	if(top==n-1)
	{
		cout<<"Stack Overflow";
		
	}
	else 
	{
		cout<<"You can enter"<<n-top<<"Elements"<<endl;
	}
}
void isempty(int &top,int st[],int n)
{
	if(top==-1)
	{
		cout<<"Stack Empty";
		
	}

}
void peek(int &top,int st[],int n)
{
	cout<<st[top];
}
void display(int &top,int st[],int n)
{	cout<<"HEre are ur stack elements"<<endl;
	for(int i=0;i<=top;i++)
	{
		cout<<st[i]<<endl;
	}
}

int main()
{
	cout<<"Enter the size of your stack"<<endl;
	int n;
	cin>>n;
	int stack[n];
	int top=-1;
	while (top>=-1)
	{
		cout<<"Here's your menu for performing operations"<<endl;
		cout<<"Enter the number of operation u want to perform"<<endl;
		cout<<"1. Push"<<endl;
		cout<<"2. Pop i.e. delete elements from your stack"<<endl;
		cout<<"3. check if stack is full"<<endl;
		cout<<"4.check if stack is empty"<<endl;
		cout<<"5.check the top most element"<<endl;
		cout<<"6.Display the elements"<<endl;
		cout<<"7.Exit the program"<<endl;
		int ch;
		cin>>ch;
		if(ch==1)
			{	push(top,stack,n);	}
	else if(ch==2)
			{	pop(top,stack,n); }
		else if(ch==3)
			{	isfull(top,stack,n); }
		else if(ch==4)
			{	isempty(top,stack,n); }
			else if(ch==5)
		{	 peek(top,stack,n);}
			else if(ch==6)
		{	display(top,stack,n); }
		else if(ch==7)
		{
			break;
		}
	}
}

