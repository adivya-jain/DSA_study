class MedianFinder {
private:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

public:
    MedianFinder() {}

    void addNum(int num) {
        if (maxheap.empty() || num <= maxheap.top())
            maxheap.push(num);
        else
            minheap.push(num);

        if (maxheap.size() > minheap.size() + 1) {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if (minheap.size() > maxheap.size()) {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }

    double findMedian() {
        int h1 = maxheap.size();
        int h2 = minheap.size();
        if ((h1 + h2) % 2 == 0) {
            return (maxheap.top() + minheap.top()) / 2.0;
        }
        return maxheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */