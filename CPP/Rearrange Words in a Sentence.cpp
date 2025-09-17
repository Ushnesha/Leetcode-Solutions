class Solution {
public:
    string arrangeWords(string text) {
        map<int,string> mp;
        text[0]=tolower(text[0]);
        stringstream ss(text), rs;
        string word;
        while(ss >> word) mp[word.size()]+=word+' ';
        for(auto m : mp) rs << m.second;
        string s=rs.str();
        s.pop_back();
        s[0]=toupper(s[0]);
        return s;
    }
};