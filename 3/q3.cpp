//balanced parenthesis
#include <iostream>
#include <string>
using namespace std;
void push(char st[], int &top, char ch)
 {
    top=top+1;
    st[top] = ch;
}
char pop(char st[], int &top)
 {
    char ch = st[top];
    top=top-1;
    return ch;
}
int balanced(string a) {
    char st[100];
    int top = -1;
    for (int i=0;i<a.length();i++) 
	{
        char ch=a[i];
        if (ch=='(' || ch=='{' || ch=='[') 
		{
            push(st,top,ch);
        }
		 else if (ch==')' || ch=='}' || ch==']')
		  {
            if (top == -1)
			 return 0;
            char max= pop(st, top);
            if ((ch==')' && max!='(') ||
                (ch=='}' && max!='{') ||
                (ch==']' && max!='[')) {
                return 0;
            }
        }
    }
    return top == -1;
}

int main() {
    string name;
    cout<<"Enter the brackets";
    cin >>name;
    if (balanced(name)==1)
    {
        cout<<"Balanced";
    }
    else
    {
	    cout<<"Not Balanced";
	}
}

