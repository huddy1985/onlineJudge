class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap;
        int i = 0;
        for(;i<nums.size(); i++)
            heap.push(nums[i]);
        i = k;
        while(--k)
            heap.pop();
        return heap.top();
    }
};