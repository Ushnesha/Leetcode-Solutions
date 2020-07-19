https://leetcode.com/problems/restore-ip-addresses/

class Solution {
public:
    void restore(vector<string>& res, string s, string ip, int index, int count){
        if(count==4){
            if(index == s.length()) res.push_back(ip);
            else return;
        }
        for(int i=1;i<=3;i++){
            if(index+i>s.length()) break;
            string a = s.substr(index, i);
            if((a[0]=='0' && a.length()>1) || (i==3 && stoi(a)>=256)) continue;
            restore(res, s, ip+a+(count==3?"":"."), index+i, count+1);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> vec;
        restore(vec, s, "", 0, 0);
        return vec;
    }
};