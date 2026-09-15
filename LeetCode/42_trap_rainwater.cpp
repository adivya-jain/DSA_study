// M1 USING O(2n) space complexity
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        prefix[0]= height[0];
        for(int i=1;i<n;i++)
        {
            prefix[i] = max(height[i],prefix[i-1]);
        }

        suffix[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffix[i] = max(height[i],suffix[i+1]);
        }


        int total=0;
        for(int i=0;i<height.size();i++)
        {
            int leftmax = prefix[i];
            int rightmax =suffix[i];
            if(leftmax > height[i] && rightmax>height[i])
            {
                total = min(leftmax,rightmax) - height[i];
            }
        }

        return total;


    }
};

// M2 USING O(n) space complexity

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> suffix(n);
        int leftmax =height[0];
        suffix[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffix[i] = max(height[i],suffix[i+1]);
        }


        int total=0;
        for(int i=0;i<height.size();i++)
        {
            int leftmax = max(leftmax,height[i]);
            int rightmax =suffix[i];
            if(leftmax > height[i] && rightmax>height[i])
            {
                total += min(leftmax,rightmax) - height[i];
            }
        }

        return total;


    }
};