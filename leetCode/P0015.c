class Solution {
private:
    vector<vector<int>> res;
    vector<int> vec0;
    vector<int> vec;
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        for(int i=0;i<len;i++){
            if(i>0 && nums[i]==nums[i-1])
				continue;
            int s = i+1,t = len-1;
            while(s<t){
                if(nums[s]+nums[t]+nums[i] == 0){
                    vec.push_back(nums[i]);
                    vec.push_back(nums[s]);
                    vec.push_back(nums[t]);
                    if(!isRepeat(vec0,vec)){
                        res.push_back(vec);
                        vec0.resize(3);
                        copy(vec.begin(),vec.end(),vec0.begin());
                    }
                    vec.clear();
                    s ++;
                    t --;
                }else if(nums[s]+nums[t]+nums[i] > 0){
                    t --;
                }else
                    s ++;
            }
        }
        return res;
    }
    bool isRepeat(vector<int> &v1,vector<int> &v2){
        if(!v1.empty() && !v2.empty()){
            if(v1[0]==v2[0] && v1[1]==v2[1] && v1[2]==v2[2])
                return true;
        }
        return false;
    }
};