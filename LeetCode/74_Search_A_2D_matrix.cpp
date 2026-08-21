class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int totalrow = matrix.size();
        int totalcol = matrix[0].size();
        int totalelements = totalrow * totalcol;

        int left = 0;
        int right = totalelements - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int row = mid / totalcol;
            int col = mid % totalcol;

            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};