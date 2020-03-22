/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* rt = root;
        while(!s.empty() || rt != nullptr)
        {
            while(rt != nullptr)
            {
                res.push_back(rt->val);
                
                s.push(rt->right);
                rt = rt->left;
            }
            rt = s.top();
            s.pop();
        }
        return res;
    }
};