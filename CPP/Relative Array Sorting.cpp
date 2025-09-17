class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> umap;
        for(int i=0;i<arr1.size();i++)
            umap[arr1[i]]++;
        vector<int> vec;
        for(int i=0;i<arr2.size();i++){
            for(int j=0;j<umap[arr2[i]];j++) vec.push_back(arr2[i]);
            umap.erase(arr2[i]);
        }
        for(auto x : umap){
            for(int i=0; i<x.second;i++) vec.push_back(x.first);
        }
        return vec;
    }
};