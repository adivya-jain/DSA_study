#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
template <typename T>
class graph{
    public:
    unordered_map<T,list<T>> adj;
    
    void addEdge(T u,T v,bool directed)
    {
        adj[u].push_back(v);

        if(directed)
        {
            adj[v].push_back(u);
        }
    }
    void printEdge()
    {
        for(auto it:adj)
        {
            cout<<it.first<<"->";
            for(auto ele : it.second)
            {
                cout<<ele<<" ";
            }
            cout<<endl;
        }
    }

     
};

int main()
{

graph<char> S; //TYPE KUCH BI DE SHAKTE
S.addEdge('1','2',1);
S.addEdge('1','3',0);
S.addEdge('3','4',0);
S.addEdge('4','5',1);
S.addEdge('5','1',0);
S.printEdge();

}