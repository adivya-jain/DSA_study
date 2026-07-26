class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = LLONG_MIN;
        long long second=LLONG_MIN;
        long long third = LLONG_MIN;
        for(int s:nums)
        {
            if (s == first || s == second || s == third)
                continue;
            if(s > first)
            {
                third = second;
                second = first;
                first = s;
            }else if(s < first && s>second){
                third = second;
                second = s;
            }else if(s<second && s>third){
                third = s;
            }
        }

        return (third == LLONG_MIN) ? first : third;
    }
};