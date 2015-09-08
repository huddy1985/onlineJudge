class Solution {
private:
    vector<string> res;
public:
    vector<string> restoreIpAddresses(string s) {
        int len = s.size();
        for(int i=0; i<len-3; i++){
            string ip1 = s.substr(0,i+1);
            if(ip1[0]=='0' && ip1.size()>1)
                break;
			if(ip1.size() > 8)
				break;
            if(stoi(ip1)>255)
                break;
            for(int j=i+1; j<len-2; j++){
                string ip2 = s.substr(i+1,j-i);
                if(ip2[0]=='0' && ip2.size()>1)
                        break;
				if(ip2.size() > 8)
						break;
                if(stoi(ip2)>255)
                    break;
                for(int k=j+1; k<len-1; k++){
                    string ip3 = s.substr(j+1,k-j);
                    if(ip3[0]=='0' && ip3.size()>1)
                        break;
					if(ip3.size() > 8)
						break;
                    if(stoi(ip3)>255)
                        break;
                    
                    string ip4 = s.substr(k+1,len-k);
                    if(ip4[0]=='0' && ip4.size()>1)
                        continue;
					if(ip4.size() > 8)
						continue;
                    if(stoi(ip4)>255)
                        continue;
                    res.push_back(ip1+"."+ip2+"."+ip3+"."+ip4);
                }
            }
        }
        return res;
    }
};