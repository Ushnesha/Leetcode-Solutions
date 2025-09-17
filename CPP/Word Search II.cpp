class Trie{
    public:
    /** Initialize your data structure here. */\
    bool isEndOfWord;
    Trie *children[26];
    Trie() {
        this->isEndOfWord = false;
        for(int i=0;i<26;i++){
            this->children[i]=nullptr;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *ptr = this;
        
        for(int i=0;i<word.length();i++){
            int index=word[i]-'a';
            if(ptr->children[index]==nullptr)
                ptr->children[index]=new Trie();
            ptr=ptr->children[index];
        }
        ptr->isEndOfWord=true;
    }
};




class Solution {
public:
    void wordChecker(vector<vector<char>>& board, string s, int p, int q, Trie *t, set<string>& res){
        if(p<0 || q<0 || q>=board[0].size() || p>=board.size() || board[p][q]=='$')
            return;
        
        char c = board[p][q];
        board[p][q]='$';
        Trie *tr=t->children[c-'a'];
        
        if(tr){
            string ss = s+c;
            if(tr->isEndOfWord) res.insert(ss);
            wordChecker(board, ss, p-1, q, tr, res);
            wordChecker(board, ss, p+1, q, tr, res);
            wordChecker(board, ss, p, q-1, tr, res);
            wordChecker(board, ss, p, q+1, tr, res);
        }
        board[p][q]=c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie root;
        set<string> res;
        for(string word : words){
            root.insert(word);
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                    wordChecker(board,"",i,j,&root, res);
            }
        }
        vector<string> ans(res.size());
        copy(res.begin(), res.end(), ans.begin());
        return ans;
    }
};