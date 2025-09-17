class Solution {
public:
    
    void backTrack(string s, vector<string>& combination, string digits, map<int,string>& mp){
        if(digits.length()==0){
            combination.push_back(s);
            return;
        }else{
            string letters=mp[digits[0]-'0'];
            for(int i=0;i<letters.length(); i++)
                backTrack(s+letters[i], combination, digits.substr(1), mp);
        }
    }
    vector<string> letterCombinations(string digits) {
        map<int,string> mp={
            {2, "abc"},
            {3, "def"},
            {4,"ghi"},
            {5, "jkl"},
            {6,"mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}
        };
        vector<string> ans;
        if(digits.length()==0) return ans;
        backTrack("",ans,digits,mp);
        return ans;
    }
};