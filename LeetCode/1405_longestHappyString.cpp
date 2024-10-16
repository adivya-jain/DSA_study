class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> maxheap;
        if (a > 0)
            maxheap.push({a, 'a'});
        if (b > 0)
            maxheap.push({b, 'b'});
        if (c > 0)
            maxheap.push({c, 'c'});
        string ans = "";
        // bool flag = true;
        while (!maxheap.empty()) {
            pair<int, char> toinsert = maxheap.top();
            maxheap.pop();
            if (ans.size() >= 2 && ans[ans.size() - 1] == toinsert.second && ans[ans.size() - 2] == toinsert.second) {

                if (maxheap.empty())
                    break;
                pair<int, char> nextinsert = maxheap.top();
                maxheap.pop();
                ans += nextinsert.second;
                nextinsert.first--;
                if (nextinsert.first > 0)
                    maxheap.push(nextinsert);
                maxheap.push(toinsert);
            } else {
                ans += toinsert.second;
                toinsert.first--;
                if (toinsert.first > 0)
                    maxheap.push(toinsert);
            }
        }
        return ans;
    }
};