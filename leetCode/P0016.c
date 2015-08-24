class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        if(len < 3)
            return 0;
        int d = ABS(nums[0] + nums[1] + nums[2] - target);
        int res = nums[0] + nums[1] + nums[2];
        for(int i=0;i<len;i++){
            if(i>1 && nums[i]==nums[i-1])
                continue;
            int s=i+1,t=len-1;
            while(s<t){
                int tmp;
                if((tmp = ABS(nums[s]+nums[t]+nums[i]-target))<d){
                    d = tmp;
                    res = nums[s]+nums[t]+nums[i];
                }
				if(nums[s]+nums[t]+nums[i]-target == 0)
					return res;
				else if(nums[s]+nums[t]+nums[i]-target > 0){
                    t --;
                }else
                    s ++;
            }
        }
        return res;
    }
    int ABS(int a){
        if(a < 0)
            a = -a;
        return a;
    }
};