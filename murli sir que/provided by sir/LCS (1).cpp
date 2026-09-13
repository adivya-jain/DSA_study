#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class LongestCommonSubstring {
private:
	const long long d = 256;
	const long long q = 1000000007;

	bool hasCommonSubstring(string s1, string s2, int len, string &answer) {
		if (len == 0) {
			answer = "";
			return true;
		}

		int n = s1.length();
		int m = s2.length();

		if (len > n || len > m) {
			return false;
		}

		unordered_map<long long, vector<int>> hashMap;

		long long h = 1;

		// h = d^len % q
		for (int i = 0; i < len; i++) {
			h = (h * d) % q;
		}

		long long hash1 = 0;

		// Calculate hash of first substring of length len in s1
		for (int i = 0; i < len; i++) {
			hash1 = (d * hash1 + (unsigned char)s1[i]) % q;
		}

		// Store hash and starting index in hashMap
		hashMap[hash1].push_back(0);

		// Build rolling hash for all substrings of length len in s1
		for (int i = 1; i <= n - len; i++) {
			hash1 = (d * hash1
			         - (unsigned char)s1[i - 1] * h
			         + (unsigned char)s1[i + len - 1]) % q;

			if (hash1 < 0) {
				hash1 += q;
			}

			hashMap[hash1].push_back(i);
		}

		long long hash2 = 0;

		// Calculate hash of first substring of length len in s2
		for (int i = 0; i < len; i++) {
			hash2 = (d * hash2 + (unsigned char)s2[i]) % q;
		}

		// Check first substring of s2 in hashMap
		if (hashMap.find(hash2) != hashMap.end()) {
			for (int index : hashMap[hash2]) {
				if (s1.substr(index, len) == s2.substr(0, len)) {
					answer = s2.substr(0, len);
					return true;
				}
			}
		}

		// Compute rolling hash for all substrings of length len in s2
		for (int i = 1; i <= m - len; i++) {
			hash2 = (d * hash2
			         - (unsigned char)s2[i - 1] * h
			         + (unsigned char)s2[i + len - 1]) % q;

			if (hash2 < 0) {
				hash2 += q;
			}

			// If hash value exists in hashMap, compare actual substrings
			if (hashMap.find(hash2) != hashMap.end()) {
				for (int index : hashMap[hash2]) {
					if (s1.substr(index, len) == s2.substr(i, len)) {
						answer = s2.substr(i, len);
						return true;
					}
				}
			}
		}

		return false;
	}

public:
	string findLCS(string s1, string s2) {
		int n = s1.length();
		int m = s2.length();

		int low = 0;
		int high = min(n, m);

		string longest = "";

		while (low <= high) {
			int mid = (low + high) / 2;

			string current = "";

			if (hasCommonSubstring(s1, s2, mid, current)) {
				longest = current;

				// Common substring of length mid exists,
				// so search for a longer substring
				low = mid + 1;
			} else {
				// Common substring of length mid does not exist,
				// so search for a smaller substring
				high = mid - 1;
			}
		}

		return longest;
	}
};

int main() {
	string s1, s2;

	cout << "Enter first string: ";
	getline(cin, s1);

	cout << "Enter second string: ";
	getline(cin, s2);

	LongestCommonSubstring obj;

	string result = obj.findLCS(s1, s2);

	if (result.empty()) {
		cout << "No common substring found." << endl;
	} else {
		cout << "Longest common substring: " << result << endl;
		cout << "Length: " << result.length() << endl;
	}

	return 0;
}