class Solution {
public:
    bool doMerge(char ch1,char ch2){
        if(ch1 == '1')
            return true;
        if(ch1 == '2' && ch2 <= '6')
            return true;
        return false;
    }
    int numDecodings(string s) {
        int len = s.size();
        if(len == 0)
            return 0;
        int dp[len+1] = {0};
        dp[0] = 1;
        if(s[0] == '0')
            return 0;
        dp[1] = 1;
        int i = 0;
        for(i=2; i<=len; i++){
            if(doMerge(s[i-2],s[i-1])){
                dp[i] = s[i-1]=='0'?dp[i-2]:(dp[i-1] + dp[i-2]);
            }
            else if(s[i-1] == '0')
                return 0;
            else
                dp[i] = dp[i-1];
        }
        return dp[len];
    }
};