// Find Servers That Handled Most Number of Requests
#include <bits/stdc++.h> 
vector<int> busiestServer (int n, vector<int> &requestTime, vector<int> &processTime, int k)
{
    // Write your code here.
    // n dedicated servers      k is the processTime

    vector<int> count(n,0);
    vector<int> freeTime(n,0);

   
        for (int i = 0; i < k; i++) {
            int server = i%n;
            int start = server;
            while(freeTime[server] > requestTime[i])
            {
                server = (server+1)%n;
                if(server == start)
                {
                    break;
                }
            }
            if (freeTime[server] <= requestTime[i]) {
                freeTime[server] = requestTime[i] + processTime[i];
                count[server]++;
                ;
            }
        
        }
    
    int maxi = *max_element(count.begin(),count.end());
    vector<int> ans;
        for(int i = 0 ; i < n ;i ++)
        {
            if(maxi == count[i])
            {
                ans.push_back(i);
            }
        }

        return ans;
    
}