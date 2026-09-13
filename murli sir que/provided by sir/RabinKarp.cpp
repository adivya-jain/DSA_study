#include <iostream>
#include <vector>
#include <string>
using namespace std;

class RabinKarp {
private:
	const long long d = 256;
	const long long q = 1000000007;   // Large prime number

public:
	vector<int> search(string text, string pattern) {
		vector<int> result;

		int n = text.length();
		int m = pattern.length();

		if (m > n) {
			return result;
		}

		long long p = 0;   // Hash value for pattern
		long long t = 0;   // Hash value for text window
		long long h = 1;   // h = d^m % q

		// Single loop to calculate h, pattern hash, and text hash
		for (int i = 0; i < m; i++) {
			h = (h * d) % q;

			p = (d * p + (unsigned char)pattern[i]) % q;
			t = (d * t + (unsigned char)text[i]) % q;
		}

		// Slide the pattern over text
		for (int i = 0; i <= n - m; i++) {

			// If hash values match, check characters one by one
			if (p == t) {
				bool match = true;

				for (int j = 0; j < m; j++) {
					if (text[i + j] != pattern[j]) {
						match = false;
						break;
					}
				}

				if (match) {
					result.push_back(i);
				}
			}

			// Calculate hash for next window
			if (i < n - m) {
				t = (d * t - ((unsigned char)text[i]) * h
				     + (unsigned char)text[i + m]) % q;

				// Convert negative hash value to positive
				if (t < 0) {
					t += q;
				}
			}
		}

		return result;
	}
};

int main() {
	string text, pattern;

	cout << "Enter text: ";
	getline(cin, text);

	cout << "Enter pattern: ";
	getline(cin, pattern);

	RabinKarp rk;
	vector<int> positions = rk.search(text, pattern);

	if (positions.empty()) {
		cout << "Pattern not found." << endl;
	} else {
		cout << "Pattern found at indices: ";
		for (int index : positions) {
			cout << index << " ";
		}
		cout << endl;
	}

	return 0;
}