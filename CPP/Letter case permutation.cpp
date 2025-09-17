class Solution {
public:
    void backTracking(int i, string& S, vector<string>& res){
        if(i==S.size()){
            res.push_back(S);
            return;
        }
        backTracking(i+1, S, res);
        if(isalpha(S[i])){
            S[i]= isupper(S[i]) ? tolower(S[i]) : toupper(S[i]);
            backTracking(i+1, S, res);
        }
    }
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        backTracking(0,S,ans);
        return ans;
    }
};