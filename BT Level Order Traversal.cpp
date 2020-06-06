class Solution {
public:
   
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if(root) q.push(root);
        vector<vector<int>> res;
        while(!q.empty()){
            int t=q.size();
            vector<int> vec;
            while(t--){
                TreeNode* s=q.front();
                q.pop();
                if(s->left) q.push(s->left);
                if(s->right) q.push(s->right);
                vec.push_back(s->val);
            }
            res.push_back(vec);
        }
        return res;
    }
};