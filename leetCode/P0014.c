class Solution {
private:
    string res;
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return res;
        int len = strs.size();
        int str_len = strs[0].size();
        for(int i=1; i<len; i++){
            if(str_len > strs[i].size())
                str_len = strs[i].size();
        }
        int index = 0;
        while(index < str_len){
            bool flag[256] = {false};
            flag[strs[0][index]] = true;
            
            for(int i=0; i<len; i++){
                if(!flag[strs[i][index]])
                    return res;
            }
            res += strs[0][index++];
        }
        return res;
    }
};