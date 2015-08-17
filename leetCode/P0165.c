class Solution {
public:
    void isolation(string str,vector<int> &vec){
        int i,len = str.size();
        int num = 0;
        for(i=0; i<len; i++){
            if(str[i] == '.'){
                vec.push_back(num);
                num = 0;
            }else{
                num = num*10 + str[i] - '0';
            }
        }
        vec.push_back(num);
    }
    int compareVersion(string version1, string version2) {
        vector<int> vec1;
        vector<int> vec2;
        isolation(version1,vec1);
        isolation(version2,vec2);

        int len1 = vec1.size();
        int len2 = vec2.size(),i;
        for(i=0;i<len1&&i<len2;i++){
            if(vec1[i] > vec2[i])
                return 1;
            else if(vec1[i] < vec2[i])
                return -1;
        }
        if(len1 == len2)
            return 0;
        else if(len1==i){
            while(i<len2)
                if(vec2[i++]>0)
                    return -1;
            return 0;
        }else{
            while(i<len1)
                if(vec1[i++]>0)
                    return 1;
            return 0;
        }
    }
};