class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> numRank;
        vector<int> sortedArr(arr);
        sort(sortedArr.begin(), sortedArr.end());
        int rank = 1;
         for (int i = 0; i < sortedArr.size(); i++) {
            if (i > 0 && sortedArr[i] > sortedArr[i - 1]) {
                rank++;
            }
            numRank[sortedArr[i]] = rank;
        }


        for(int i=0;i<arr.size();i++)
        {
            arr[i] = numRank[arr[i]];
        }

        return arr;
    }
};