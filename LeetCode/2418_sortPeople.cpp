typedef struct node
{
    string s;
    int a;
}node;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string>ans;
        vector<node>temp(names.size());
        for(int i=0;i<names.size();i++)
        {
            temp[i].s=names[i];
            temp[i].a=heights[i];
        }
         sort(temp.begin(), temp.end(), [](const node& l, const node& r) {
        return l.a > r.a;
    });
    for( int i=0;i<names.size();i++)
    {
        ans.push_back(temp[i].s);
    }
    return ans;
    }
};