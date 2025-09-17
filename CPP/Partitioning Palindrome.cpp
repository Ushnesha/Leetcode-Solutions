class Solution {
public:
    bool isPalindrome(string s){
        int i=0, j=s.length()-1;
        for(;i<j;i++, j--){
            if(s[i]!=s[j]) return false;
        }
        return true;
    }
    void partitionPalindrome(vector<vector<string>>& val, vector<string>& temp, string s, int index){
        vector<string> cur=temp;
        string str;
        if(index==0) temp.clear();
        for(int i=index;i<s.length();i++){
            str+=s[i];
            if(isPalindrome(str)){
                temp.push_back(str);
                if((i+1)<s.length()) partitionPalindrome(val, temp, s, i+1);
                else val.push_back(temp);
                temp=cur;
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> vec;
        if(s.empty()) return {{}};
        vector<string> temp;
        partitionPalindrome(vec, temp, s, 0);
        return vec;
    }
};