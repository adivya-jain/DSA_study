class Solution {

int removestring(string pair,int point,string& s)
{
    int bonus=0;
    stack<char> store;
    char firstchar = pair[0];
    char secondchar = pair[1];
    for(auto c : s)
    {
        if(c!=secondchar)
        {
            store.push(c);
        }
        else{
            if(!store.empty() && store.top() == firstchar)
            {
                bonus+=point;
                store.pop();
            }
            else{
                store.push(c);
            }
        }
    }
string temp="";
while(!store.empty())
{
    temp+=store.top();
    store.pop();
}
::reverse(temp.begin(),temp.end());

s = temp;
    return bonus;
}
public:
    int maximumGain(string s, int x, int y) {
    
// x:ab    y:ba
    string firstpair = (x>y)?"ab":"ba";
    string secondpair=(firstpair=="ab")?"ba":"ab";

    
    int score = 0;

    // 2 pass
    score = removestring(firstpair,max(x,y),s);

    score+=removestring(secondpair,min(x,y),s);
    return score;
    }
};