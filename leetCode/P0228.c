class Solution {
private:
    vector<string> res;
    string res_str;
public:
    string int2str(int num){
        char str[12] = {0};
        sprintf(str,"%d",num);
        res_str = str;
        return res_str;
    }
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty())    return res;
        int len = nums.size();
        string str = "";
        int flag = 0;
        for(int i=0; i<len; i++){
            if(str.empty()){
                str += int2str(nums[i]);
                flag = i;
            }
            else{
                if(nums[i] != nums[i-1]+1){
                    if(flag != i-1){
                        str += "->";
                        str += int2str(nums[i-1]);
                    }
                    res.push_back(str);
                    str = int2str(nums[i]); 
                    flag = i;
                }
            }
        }
        if(flag != len-1){
            str += "->";
            str += int2str(nums[len-1]);
        }
        res.push_back(str);
        return res;
    }
};