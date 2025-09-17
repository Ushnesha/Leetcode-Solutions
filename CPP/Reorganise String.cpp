class Solution {
public:
    string reorganizeString(string S) {
        vector<pair<char,int>> vec;
        map<char,int> mp;
        for(char c : S) mp[c]++;
        copy(mp.begin(), mp.end(), back_inserter<vector<pair<char, int>>>(vec));
        auto cmp=[](pair<char,int>&a, pair<char,int>&b){
            return a.second>b.second;
        };
        sort(vec.begin(), vec.end(), cmp);
        string s="", ans="";
        for(auto p:vec) for(int i=0;i<p.second;i++) s+=p.first;
        int n=S.length();
        if(s[0]==s[(n+1)/2]) return "";
        for(int i=0, j=(n+1)/2; i<(n+1)/2; j++, i++){
            ans+=s[i];
            if(j<n) ans+=s[j];
        }
        return ans;
    }
};