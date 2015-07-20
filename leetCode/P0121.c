class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len <= 1)
            return 0;
        else if(len == 2){
            if(prices[1] > prices[0])
                return prices[1]-prices[0];
            else
                return 0;
        }
        int min = 0;
        int res = 0;
        for(int i=2;i<len;i++){
            if(prices[i-2]<=prices[i-1] && prices[i-1]>prices[i]){
                int nums = prices[i-1]-prices[min];
                res = res>nums?res:nums;
            }else if(prices[i-2]>=prices[i-1] && prices[i-1]<prices[i]){
                min = prices[min]<prices[i-1]?min:(i-1);
            }
        }
        if(prices[len-1] >= prices[len-2]){
            int nums = prices[len-1]-prices[min];
            res = res>nums?res:nums;
        }
        return res;
    }
};