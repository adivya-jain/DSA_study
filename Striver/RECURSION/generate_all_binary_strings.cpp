#include <bits/stdc++.h>
using namespace std;

void generate(int n, string curr, vector<string>& result) {
    // Base case: if length is n, add to result
    if (curr.length() == n) {
        result.push_back(curr);
        return;
    }

    // Always try adding '0'
    generate(n, curr + "0", result);

    // Add '1' only if previous char is not '1'
    if (curr.empty() || curr.back() != '1') {
        generate(n, curr + "1", result);
    }
}

int main() {
    // Input length n
    int n = 3;

    // Vector to store results
    vector<string> result;

    // Start recursion with empty string
    generate(n, "", result);

    // Print results
    for (string& s : result) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}