#include<iostream>
#include<queue>

using namespace std;

int main()
{
queue<int> q;
q.push(11);
cout<<"Front element of queue "<<q.front()<<endl;
q.push(22);
cout<<"Front element of queue "<<q.front()<<endl;
q.push(33);
cout<<"Front element of queue "<<q.front()<<endl;
q.push(44);
cout<<"Size of queue: "<<q.size()<<endl;

q.pop();
cout<<"Size of queue: "<<q.size()<<endl;
cout<<"Front element of queue "<<q.front()<<endl;

}
