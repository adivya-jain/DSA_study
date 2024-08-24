class Solution {
    long solve(long firstHalf, bool isodd) {
        long res = firstHalf;
        if (isodd)
            firstHalf /= 10; // remove middle digit if odd
        
        while (firstHalf) {
            res = res * 10 + firstHalf % 10;
            firstHalf /= 10;
        }
        return res;
    }

public:
    string nearestPalindromic(string n) {
        vector<long> possibilities;
        int len = n.length();
        bool odd = (len % 2 != 0);
        int mid = (len % 2 == 0) ? (len / 2) : (len / 2 + 1);
        string firstHalfstring = n.substr(0, mid);
        long firstHalf;
        stringstream ss;
        ss << firstHalfstring;
        ss >> firstHalf;

        // Debugging Output
        cout << "First Half: " << firstHalf << ", Odd: " << odd << endl;

        possibilities.push_back(solve(firstHalf, odd));
        possibilities.push_back(solve(firstHalf + 1, odd));
        possibilities.push_back(solve(firstHalf - 1, odd));
        possibilities.push_back(pow(10, len - 1) - 1); // 9,99,999
        possibilities.push_back(pow(10, len) + 1);     // 101,1001,10001

        // Debugging Output
        cout << "Generated Possibilities: ";
        for (auto p : possibilities) {
            cout << p << " ";
        }
        cout << endl;

        stringstream ss2;
        ss2 << n;
        long num;
        ss2 >> num;
        long ans = 0;
        long mini = LONG_MAX;

        for (auto poss : possibilities) {
            cout << "Checking: " << poss << " ";
            if (poss == num)
                continue;
            else if (abs(num - poss) < mini) {
                ans = poss;
                mini = abs(num - poss);
            } else if (abs(num - poss) == mini)
                ans = min(ans, poss);
            cout << "Current Best: " << ans << " with Difference: " << mini << endl;
        }

        return to_string(ans);
    }
};
