class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt[3] = {0};
        vector<int>::iterator it;
        for(it=nums.begin(); it!=nums.end(); it++)
            cnt[*it] ++;
        nums.clear();
        int i = 0;
        for(i=0; i<3; i++)
            nums.insert(nums.end(),cnt[i],i);
    }
};