#include<string>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {

        string temp="";
        string ans="";

//left and right pointer pointing to 1st & last non-space character respectively
        int left=0;
        while(s[left]==' ')
        {
            left++;
        } 
        int right=s.length()-1;
        while(s[right]==' ')
        {
            right--;
        }


        while(left<=right)
        {
            if(s[left]!=' ')
            {
                temp=temp+s[left];
            }
            else{
                if(s[left-1]==' ')
                {
                    left++;
                    continue;
                }
                else{
                    ans=temp+" "+ans;
                    temp="";

                }
            }
            left++;
        }

        ans=temp+" "+ans;
        ans.erase(ans.begin()+ans.length()-1);
        return ans;


        
    }
};