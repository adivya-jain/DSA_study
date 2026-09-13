#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class RankSet {
private:
	vector<pair<long long, long long>> intervals;
	vector<long long> suffixCount;

public:
	RankSet(vector<pair<long long, long long>> input) {
		if (input.empty()) {
			return;
		}

		// Sort intervals by left endpoint
		sort(input.begin(), input.end());

		// Merge overlapping intervals
		for (auto interval : input) {
			long long l = interval.first;
			long long r = interval.second;

			if (intervals.empty() || l > intervals.back().second + 1) {
				intervals.push_back({l, r});
			} else {
				intervals.back().second = max(intervals.back().second, r);
			}
		}

		int n = intervals.size();
		suffixCount.assign(n, 0);

		// suffixCount[i] stores number of elements from interval i to end
		for (int i = n - 1; i >= 0; i--) {
			long long length = intervals[i].second - intervals[i].first + 1;

			if (i == n - 1) {
				suffixCount[i] = length;
			} else {
				suffixCount[i] = length + suffixCount[i + 1];
			}
		}
	}

	long long getRank(long long x) {
		int n = intervals.size();

		if (n == 0) {
			return 1;
		}

		long long greaterCount = 0;

		for (int i = 0; i < n; i++) {
			long long l = intervals[i].first;
			long long r = intervals[i].second;

			if (x < l) {
				// All elements from this interval onward are greater than x
				greaterCount += suffixCount[i];
				break;
			} else if (x >= l && x <= r) {
				// Elements greater than x inside this interval
				greaterCount += r - x;

				// Add all elements in intervals after this
				if (i + 1 < n) {
					greaterCount += suffixCount[i + 1];
				}

				break;
			}
		}

		return greaterCount + 1;
	}

	long long findElementWithRank(long long k) {
		int n = intervals.size();

		if (n == 0) {
			return -1;
		}

		long long totalElements = suffixCount[0];

		if (k < 1 || k > totalElements) {
			return -1;
		}

		// Rank 1 means largest element.
		// Rank k means kth largest element.
		long long remaining = k;

		for (int i = n - 1; i >= 0; i--) {
			long long l = intervals[i].first;
			long long r = intervals[i].second;

			long long length = r - l + 1;

			if (remaining <= length) {
				return r - remaining + 1;
			} else {
				remaining -= length;
			}
		}

		return -1;
	}

	void printIntervals() {
		cout << "Merged intervals: ";
		for (auto interval : intervals) {
			cout << "[" << interval.first << ", " << interval.second << "] ";
		}
		cout << endl;
	}
};

int main() {
	int n;

	cout << "Enter number of intervals: ";
	cin >> n;

	vector<pair<long long, long long>> input;

	cout << "Enter intervals:" << endl;
	for (int i = 0; i < n; i++) {
		long long l, r;
		cin >> l >> r;

		if (l > r) {
			swap(l, r);
		}

		input.push_back({l, r});
	}

	RankSet rs(input);

	rs.printIntervals();

	long long x;
	cout << "Enter x to find rank: ";
	cin >> x;

	cout << "Rank of " << x << " is: " << rs.getRank(x) << endl;

	long long k;
	cout << "Enter k to find element with rank k: ";
	cin >> k;

	long long element = rs.findElementWithRank(k);

	if (element == -1) {
		cout << "No element exists with rank " << k << endl;
	} else {
		cout << "Element with rank " << k << " is: " << element << endl;
	}

	return 0;
}