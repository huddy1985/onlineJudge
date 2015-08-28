class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        vector<int> vec;
        int len = nums.size();
        int res = 1;
        for(int i=1;i<len;i++){
            if(nums[i]!=nums[i-1])
                res ++;
            else
                vec.push_back(i);
        }
        int l = vec.size();
        for(int i=l-1;i>=0;i--){
            nums.erase(nums.begin()+vec[i]);
        }
        return res;
    }
};