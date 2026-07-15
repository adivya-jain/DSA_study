1 _ _ _ _ _ _ 1
1 2 _ _ _ _ 2 1
1 2 3 _ _ 3 2 1
1 2 3 4 4 3 2 1


#include <iostream>
using namespace std;
int main()
{
    int n = 4;
    for(int i=1;i<=n;i++)
    {
       for(int j=1;j<=i;j++)
       {
           cout<<j<<" ";
       }
       int spaces = n-i;
       for(int k = 0;k < spaces;k++)
       {
           cout<<"+ "<<"+ ";
       }
       
       for(int j = i ; j >= 1 ; j--)
       {
           cout<<j<<" ";
       }
       
       
       
       
       
        
        cout<<"\n";
    }
}



# striver 13

1 
2 3 
4 5 6 
7 8 9 10 
11 12 13 14 15




#include <iostream>
using namespace std;
int main()
{
        int cnt = 1;
       for(int i=0;i<5;i++)
       {
           for(int j=0;j<=i;j++)
           {
               cout << cnt << " ";
               cnt++;
           }
           cout << "\n";
       }
}
