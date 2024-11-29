#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
int dynamic_programming(string& s, vector<string>& vects,unordered_map<string,int>& mind)
{
    if(mind.count(s)) return mind[s];
    int adivya = 0;
    for(auto&xy : vects)
    {
        size_t posi = s.find(xy);
        if(posi!=string::npos)
        {
            string newStr = s.substr(0,posi) + s.substr(posi+xy.size());
            adivya = max(adivya,1+dynamic_programming(newStr,vects,mind));
        }
    }
    return mind[s] = adivya;
}
int main()
{
    int num;
    cin >> num;
    vector<string> subs(num); 
    int j=0;
    while(j<num)
    {
        cin >> subs[j];
        ++j;
    }
    string m_str;
    cin >> m_str;
    unordered_map<string,int> mind;
    cout << dynamic_programming(m_str,subs, mind) << endl;
    return 0;
}