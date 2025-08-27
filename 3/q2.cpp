#include <iostream>
#include <string>
using namespace std;
void push(int &top, char ch, char st[], int size) 
{
    if (top<size - 1) {
        top=top+1;
        st[top]=ch;
    }
}
char pull(int &top,char st[]) 
{
    if (top>=0) {
        char ch=st[top];
        top=top-1;
        return ch;
    }
}
int main() {
    string name = "Datastructures";
    char st[100];
    int top=-1;
    int d=name.length();
    for (int i=0;i<d;i++) 
	{
        push(top,name[i],st,d);
    }

      string p="";
    for (int i=0;i<d;i++)
	 {
        p=p+pull(top,st);
    }

    cout <<"initial "<<name<<endl;
    cout <<"reverse "<<p<<endl;

}

