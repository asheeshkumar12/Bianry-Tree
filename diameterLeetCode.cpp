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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        Diameter(root,diameter);
        return diameter;
    }
    private:
    int Diameter(TreeNode *root,int &diameter)
    {
        if(root==NULL)
            return 0;
       int lh=Diameter(root->left,diameter);
        int rh=Diameter(root->right,diameter);
        diameter=max(lh+rh,diameter);
        return 1+max(lh,rh);
        
        
    }
};
