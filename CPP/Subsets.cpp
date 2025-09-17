class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size();
        for(int i=(int) pow(2,n);i<(int) pow(2,n+1);i++){
             string bitmask = bitset<32>(i).to_string();
            bitmask=bitmask.substr(bitmask.find("1")+1);
            vector<int> vec;
            for(int j=0;j<bitmask.length();j++){
                if(bitmask[j]=='1') vec.push_back(nums[j]);
            }
            res.push_back(vec);
        }
        return res;
    }
};