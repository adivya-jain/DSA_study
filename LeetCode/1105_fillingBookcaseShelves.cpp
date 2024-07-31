class Solution {
    int maxWidth;
    int totalBooks;
    int solve(vector<vector<int>>& books, int currWidth, int index,
              int currHeight, vector<vector<int>>& dp) {
        int maxHeight = max(currHeight, books[index][1]);

        if (index == (totalBooks - 1)) {

            if (books[index][0] <= currWidth) // same shelf
            {
                return maxHeight;
            }

            return currHeight + books[index][1]; // nextshelf
        }
        if (dp[index][currWidth] != 0) {
            return dp[index][currWidth];
        }
        // 2 options we have
        // same shelf
        int sameshelf = INT_MAX;
        if (books[index][0] <= currWidth) {
            sameshelf = solve(books, currWidth - books[index][0], index + 1,
                              maxHeight, dp);
        }

        int nextshelf = currHeight + solve(books, maxWidth - books[index][0],
                                           index + 1, books[index][1], dp);

        // different shelf

        dp[index][currWidth] = min(sameshelf, nextshelf);
        return dp[index][currWidth];
    }

public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        maxWidth = shelfWidth;

        totalBooks = books.size();
        vector<vector<int>> dp(books.size(), vector<int>(shelfWidth + 1, 0));
        return solve(books, shelfWidth, 0, 0, dp);
    }
};