class Solution {
private:
    string str;
public:
    string convertToTitle(int n) {
        while(n){
            str.insert(str.begin(),(char)((n-1)%26)+'A');
            n = (n-1)/26;
        }
        return str;
    }
};