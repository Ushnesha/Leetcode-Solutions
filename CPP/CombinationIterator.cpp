class CombinationIterator {
public:
    vector<string> combs;
    int index;
    void combination(string str, int comb, string s, int j){
        if(s.length()==comb){
            combs.push_back(s);
            return;
        }
        for(int i=j;i<str.length();i++){
            combination(str, comb, s+str[i], i+1);
        }
    }
    CombinationIterator(string characters, int combinationLength) {
        combination(characters, combinationLength, "", 0);
        index=0;
    }
    
    string next() {
        return combs[index++];
    }
    
    bool hasNext() {
        return !(index==combs.size());
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */