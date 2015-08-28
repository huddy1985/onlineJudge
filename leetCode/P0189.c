class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k%len;
        for(int i=len-k;i<len;i++){
            int num = nums[i];
            nums.erase(nums.begin()+i);
            nums.insert(nums.begin()+i-(len-k),num);
        }
    }
};