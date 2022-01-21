BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        return NULL;
    if(root->left==NULL &&root->right==NULL)
    {
     
        delete root;
        return NULL;
    }
     root->left = removeLeafNodes(root->left);
    root->right = removeLeafNodes(root->right);
  
}
