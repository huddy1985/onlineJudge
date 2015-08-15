class Solution {
private:
    vector<string> vec;
    string res;
public:
    string simplifyPath(string path) {
        if(path.empty())
            return path;
        int len = path.size();
        int i = 0;
        while(i < len){
            if(path[i] == '/')
                i ++;
            string str;
            while(path[i] != '/' && i<len)
                str.append(1,path[i++]);
            i ++;
            if(str.compare("..") == 0){
                if(!vec.empty())
                    vec.erase(vec.end()-1);
                else
                    continue;
            }
            else if(str.compare(".") == 0)
                continue;
            else if(!str.empty())
                vec.push_back(str);
        }

        vector<string>::iterator it = vec.begin();
        while(it != vec.end()){
            res += "/";
            res += *it;
            it ++;
        }
        if(res.empty())
            res += "/";
        return res;
    }
};