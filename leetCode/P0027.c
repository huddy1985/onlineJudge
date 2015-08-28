class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty())
            return 0;
        vector<int> vec;
        int len = nums.size();
        for(int i=0;i<len;i++){
            if(nums[i] == val)
                vec.push_back(i);
        }
        len = vec.size();
        for(int i=len-1;i>=0;i--){
            nums.erase(nums.begin()+vec[i]);
        }
        return nums.size();
    }
};