class Solution {
public:
    int numDistinct(string s, string t) {
        int len_s = s.size(),len_t = t.size();
        int dp[len_t+1][len_s+1] = {0};
        int i=0,j=0;
        for(i=0; i<=len_s; i++)
            dp[0][i] = 1;
        for(i=1; i<=len_t; i++){
            for(j=1; j<=len_s; j++){
                if(t[i-1] == s[j-1])
                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
        return dp[len_t][len_s];
    }
};