class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> mp;
        vector<int> v;
        for(auto a : arr)
            mp[a]++;
        int ans=mp.size();
        for(auto a : mp)
            v.push_back(a.second);
        sort(v.begin(), v.end());
        for(int i=0;i<v.size();i++){
            if(k==0 || k<v[i]) return ans;
            k-=v[i];
            ans--;
        }
        return ans;
    }
};