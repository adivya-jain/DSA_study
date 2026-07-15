1
0 1
1 0 1
0 1 0 1
1 0 1 0 1
patter striver


#include <iostream>
using namespace std;
int main()
{

    for(int i=0;i<6;i++)
    {
        int c = i%2==0? 1:0;
        for(int j=0;j<=i;j++)
        {
          cout<<c;
          c= 1 - c;
            
        }
        
        cout<<"\n";
    }
}
