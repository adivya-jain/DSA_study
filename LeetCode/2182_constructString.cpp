class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<char,int>> pq;
        vector<int> arr(26,0);
        for(int i=0;i<s.length();i++)
        {
            arr[s[i]-'a']++;
        }
        for(int i=25;i>=0;--i)
        {
            if(arr[i]>0)
            {
                pq.push(make_pair((char)(i+'a'),arr[i]));
            }
        }
        string ans;
        while(!pq.empty())
        {
            auto [highChar,highFreq] = pq.top();
            pq.pop();
            int useCount = min(highFreq, repeatLimit);
            ans.append(useCount, highChar);
            highFreq -= useCount;
            if(highFreq > 0)
            {
                if(pq.empty()) break;
                pair<char,int> secondpri = pq.top();
                pq.pop();
                ans+=secondpri.first;
                secondpri.second--;
                if(secondpri.second>0) pq.push(secondpri);
                pq.push({highChar,highFreq});
            }
            
        }
        return ans;

    }
};