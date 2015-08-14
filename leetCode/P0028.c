class Solution {
public:
    int strStr(string haystack, string needle) {
        int res;
        if((res=haystack.find(needle)) == string::npos)
            return -1;
        else 
            return res;
    }
};