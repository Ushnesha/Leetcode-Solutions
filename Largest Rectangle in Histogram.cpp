class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int i=0, maxA=0, curA=0;
        stack<int> stk;
        while(i<heights.size()){
            if(stk.empty() || heights[stk.top()]<=heights[i])
                stk.push(i++);
            else{
                while(!stk.empty() && heights[stk.top()]>heights[i]){
                    int top=stk.top();
                    stk.pop();
                    if(stk.empty())
                        curA=heights[top]*i;
                    else
                        curA=heights[top]*(i-stk.top()-1);
                    maxA=max(maxA,curA);
                }
            }
        }
        while(!stk.empty()){
            int top=stk.top();
            stk.pop();
            if(stk.empty())
                curA=heights[top]*i;
            else
                curA=heights[top]*(i-stk.top()-1);
            maxA=max(maxA,curA);
        }
        return maxA;
    }
};