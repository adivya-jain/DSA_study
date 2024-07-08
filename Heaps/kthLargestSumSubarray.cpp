#include<algorithm>


int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.

	vector<int> sums;
int n =arr.size();
	for(int i =0;i<n;i++)
	{
		int sum = 0;
		for(int j=i;j<n;j++)
		{
			sum+=arr[j];
			sums.push_back(sum);
		}
		
	}

	sort(sums.begin(),sums.end());

	return sums[sums.size()-k];
	
}