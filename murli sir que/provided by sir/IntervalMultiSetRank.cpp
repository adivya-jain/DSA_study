#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Segment {
    long long l, r;
    long long count;
};

class MultiSetRank {
private:
    vector<Segment> seg;

public:
    MultiSetRank(vector<pair<long long, long long>> intervals) {
        vector<long long> L, R;

        for (auto p : intervals) {
            long long l = p.first;
            long long r = p.second;

            if (l > r) {
                swap(l, r);
            }

            L.push_back(l);
            R.push_back(r + 1);   // because interval is closed [l, r]
        }

        sort(L.begin(), L.end());
        sort(R.begin(), R.end());

        int n = intervals.size();

        int i = 0, j = 0;
        long long count = 0;
        long long prev = 0;
        bool first = true;

        while (i < n || j < n) {
            long long point;

            if (j == n || (i < n && L[i] < R[j])) {
                point = L[i];
            } else {
                point = R[j];
            }

            // From prev to point - 1, count remains same
            if (!first && count > 0 && prev <= point - 1) {
                seg.push_back({prev, point - 1, count});
            }

            // Increase count for all intervals starting at point
            while (i < n && L[i] == point) {
                count++;
                i++;
            }

            // Decrease count for all intervals ending before point
            while (j < n && R[j] == point) {
                count--;
                j++;
            }

            prev = point;
            first = false;
        }
    }

    long long rankOfX(long long x) {
        long long greater = 0;

        for (auto s : seg) {
            if (x < s.l) {
                // Entire segment is greater than x
                greater += (s.r - s.l + 1) * s.count;
            } else if (x >= s.l && x < s.r) {
                // Part of this segment is greater than x
                greater += (s.r - x) * s.count;
            }
        }

        return greater + 1;
    }

    long long elementWithRank(long long k) {
        // Rank 1 means largest element
        // So scan segments from right to left

        for (int i = seg.size() - 1; i >= 0; i--) {
            long long l = seg[i].l;
            long long r = seg[i].r;
            long long count = seg[i].count;

            long long total = (r - l + 1) * count;

            if (k > total) {
                k -= total;
            } else {
                // kth element lies in this segment
                long long steps = (k - 1) / count;
                if(k%count==1)
                return r - steps;
                else return -1;
            }
        }

        return -1; // rank k does not exist
    }

    void printSegments() {
        cout << "Segments with multiplicity:" << endl;

        for (auto s : seg) {
            cout << "[" << s.l << ", " << s.r << "] count = "
                 << s.count << endl;
        }
    }
};

int main() {
    int n;

    cout << "Enter number of intervals: ";
    cin >> n;

    vector<pair<long long, long long>> intervals;

    cout << "Enter intervals:" << endl;

    for (int i = 0; i < n; i++) {
        long long l, r;
        cin >> l >> r;
        intervals.push_back({l, r});
    }

    MultiSetRank ms(intervals);

    ms.printSegments();

    long long x;
    cout << "Enter x to find rank: ";
    cin >> x;

    cout << "Rank of " << x << " is: "
         << ms.rankOfX(x) << endl;

    long long k;
    cout << "Enter k to find element with rank k: ";
    cin >> k;

    long long ans = ms.elementWithRank(k);

    if (ans == -1) {
        cout << "No element exists with rank " << k << endl;
    } else {
        cout << "Element with rank " << k << " is: "
             << ans << endl;
    }

    return 0;
}