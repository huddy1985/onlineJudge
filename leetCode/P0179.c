class Solution {
public:
    static bool greater(int a,int b){
        char str_a[12]={0},str_b[12]={0};
        sprintf(str_a,"%d",a);
        sprintf(str_b,"%d",b);
        return string(str_a)+string(str_b) > string(str_b)+string(str_a);
    }
    string largestNumber(vector<int>& nums) {
        if(nums.empty())
            return NULL;
        sort(nums.begin(),nums.end(),greater);
        int i;
        string res;
        for(i=0; i<nums.size(); i++){
            char str[10]={0};
            sprintf(str,"%d",nums[i]);
            res += string(str);
        }
        while(res.size()>1){
            if(res[0] == '0'){
                res.erase(res.begin());
                continue;
            }else
                break;
        }
        return res;
    }
};