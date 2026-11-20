class Solution {
	public:
	int minPlatform(vector<int>& arr, vector<int>& dep) {
		// code here
		priority_queue<int, vector<int>, greater<int>> pq;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq1;
		
		for (int i = 0; i<arr.size(); i++)
			{
			pq1.push({arr[i], dep[i]});
		}
		while (!pq1.empty())
			{
			pair<int, int> a = pq1.top();
			pq1.pop();
			
			if (!pq.empty() && pq.top() < a.first)
				{
				pq.pop();
			}
			pq.push(a.second);
		}
		return pq.size();
	}
};
