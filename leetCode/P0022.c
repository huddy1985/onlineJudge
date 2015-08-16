class Solution {
private:
    vector<string> res;
    string str;
public:
    void _generateParenthesis(int left,int right,string str){
        if(left==0 && right==0){
            res.push_back(str);
            return ;
        }
        if(left>0)
            _generateParenthesis(left-1,right,str+'(');
        if(right>left)
             _generateParenthesis(left,right-1,str+')');
    }
    vector<string> generateParenthesis(int n) {
        if(0 == n)
            return res;
        str = "";
        _generateParenthesis(n,n,str);
        return res;
    }
};