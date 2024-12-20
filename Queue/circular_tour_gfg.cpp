// Circular tour gfg Also see this question Interleave the first half of the queue with second half from GFG itself

//{ Driver Code Starts
// Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
// 1. The amount of petrol that every petrol pump has.
// 2. Distance from that petrol pump to the next petrol pump.
// Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
// Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int deficit = 0;
       int start = 0;
       int balance = 0 ;
       
       for(int i=0;i<n;i++)
       {
           balance = balance + p[i].petrol - p[i].distance;
       
           if(balance < 0)
           {
               deficit += balance;
               start = i+1;
               balance = 0;
           }
       }
       
       
       if(deficit + balance >= 0)
       {
           return start;
       }
       return -1;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends