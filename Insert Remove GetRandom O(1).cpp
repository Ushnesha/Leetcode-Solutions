class RandomizedSet {
public:
    /** Initialize your data structure here. */
    vector<int> vec;
    unordered_map<int,int> umap;
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(umap.find(val)!=umap.end()) return false;
        else{
            vec.emplace_back(val);
            umap[val]=vec.size()-1;
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(umap.find(val)==umap.end()) return false;
        else{
            int last=vec.back();
            umap[last]=umap[val];
            vec[umap[last]]=last;
            vec.pop_back();
            umap.erase(val);
            return true;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return vec[rand()%vec.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */