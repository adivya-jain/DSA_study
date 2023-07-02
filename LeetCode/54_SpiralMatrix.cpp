#include<string>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans;

        int row=matrix.size();
        int col=matrix[0].size();


        int startingRow=0;
        int startingCol=0;
        int endingRow=row-1;
        int endingCol=col-1;

        int total=row*col;
        int count=0;

        while(count<total)
        {
            //starting row
            for(int index=startingCol;index<=endingCol && count<total;index++)
            {
                ans.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++;


            //ending col
            for(int index=startingRow;index<=endingRow && count<total;index++)
            {
                ans.push_back(matrix[index][endingCol]);
                count++;
            }

            endingCol--;

            //ending row
               for(int index=endingCol;index>=startingCol && count<total;index--)
            {
                ans.push_back(matrix[endingRow][index]);
                count++;
            }
            
            endingRow--;

            //starting col
               for(int index=endingRow;index>=startingRow && count<total;index--)
            {
                ans.push_back(matrix[index][startingCol]);
                count++;
            }

            startingCol++;
        }

        return ans;




        
    }
};