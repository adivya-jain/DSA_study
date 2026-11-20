class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        priority_queue<pair<double,double>> pq;
        
        for(int i=0;i<val.size();i++)
        {
            pq.push({(double)(val[i])/wt[i],wt[i]});
        }
        double value=0;
        while(capacity>0 && !pq.empty())
        {
            auto item = pq.top();
            pq.pop();
            
            if(item.second<=capacity)
            {
                value+=(item.first * item.second);
                capacity -=item.second;
            }
            else{
                value += item.first*capacity;
                capacity=0;
            }
        }
        
        return value;
        
    }
};
