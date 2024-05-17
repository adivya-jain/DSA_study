#include<iostream>
#include<stack>

using namespace std;

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    
    
    
    
    s.pop();
    cout<<"Top element is: "<<s.top()<<endl;

    if(s.empty())
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        cout<<"Stack is not empty"<<endl;
    }
    cout<<"Size of stack is: "<<s.size()<<endl;


}