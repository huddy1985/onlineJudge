class Solution {
public:
    int get_max(int a,int b){
        return a>b?a:b;
    }
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        sort(nums.begin(),nums.end());
        int i;
        int max = 0;
        for(i=1; i<nums.size(); i++){
            max = get_max(max,nums[i]-nums[i-1]);
        }
        return max;
    }
};