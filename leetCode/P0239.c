class Solution {
private:
    vector<int> res;
public:
    int getMax(vector<int>& nums){
        int i = 0,max=nums[0];
        for(i=1; i<nums.size(); i++){
            if(nums[i] > max){
                max = nums[i];
            }
        }
        return max;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k<1 || k>nums.size())
            return res;
        if(1 == k)
            return nums;
        int i = 0;
        vector<int> heap;
        for(i=0; i<k; i++){
            heap.push_back(nums[i]);
        }
        res.push_back(getMax(heap));
        for(i=1; i<=nums.size()-k; i++){
            heap.erase(heap.begin());
            heap.push_back(nums[i+k-1]);
            res.push_back(getMax(heap));
        }
        return res;
    }
};