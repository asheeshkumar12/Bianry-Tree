#include <cmath>

int height(BinaryTreeNode<int> *root)
{   if(root==NULL)
       return 0;
 
    return 1+max(height(root->left),height(root->right));
}
bool isBalanced(BinaryTreeNode<int> *root) {
      if (root == NULL) 
        return 1; 
    int l=height(root->left);
	int r=height(root->right);	
   
     if (  abs(l- r)<=1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;
    
   return 0;
	
}
