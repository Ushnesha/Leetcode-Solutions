class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int median= arr[(arr.size()-1)/2];
        auto comp=[median](int &a, int &b){
            if(abs(a-median)==abs(b-median)) return a>b;
            return abs(a-median)>abs(b-median);
        };
        sort(arr.begin(), arr.end(), comp);
        vector<int> res;
        for(int i=0;i<k;i++) res.push_back(arr[i]);
        return res;
    }
};