/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
       
       vector<vector<int>> final;
        if(root==nullptr)
            return final;
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        // run loop when q is not empty
        while(!pendingNodes.empty())
        {
            int size=pendingNodes.size();                                       /* time = O(n)
                                                                                     space =O(n)*/
            vector<int> local;
            for(int i=0;i<size;i++)  // size of queue 
            {
                TreeNode *f=pendingNodes.front();
                pendingNodes.pop();
                if(f->left!=nullptr)
                    pendingNodes.push(f->left);
                if(f->right!=nullptr)
                    pendingNodes.push(f->right);
                local.push_back(f->val);
            }
            final.push_back(local);
        }
        return final;
        
    }
};