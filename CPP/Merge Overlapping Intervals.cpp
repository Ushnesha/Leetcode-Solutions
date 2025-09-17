class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0 || intervals[0].size()==0) return intervals;
        vector<vector<int>> res;
        auto cmp=[](vector<int>&a, vector<int>&b){
            if(a[0]==b[0]) return a[1]<b[1];
            return a[0]<b[0];
        };
        sort(intervals.begin(), intervals.end(), cmp);
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=res[res.size()-1][1]){
                if(intervals[i][1]>=res[res.size()-1][1])
                res[res.size()-1][1]=intervals[i][1];
                else continue;
            }
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};