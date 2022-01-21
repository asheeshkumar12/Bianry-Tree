int hieght(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        return 0;
    return 
     1+  max(hieght(root->left),hieght(root->right));
}

//balanceAndHieght
pair<int,bool> balanceAndHieght(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        pair<int,bool> p;
        p.first=0;
        p.second=true;
        return p;
    }
     pair<int,bool> p;
     p.first=hieght(root);
     p.second=true;
    pair<int,bool> leftAns=balanceAndHieght(root->left);
    pair<int,bool> rightAns=balanceAndHieght(root->right);
    /* pair<int,bool> p;
   p.first=hieght(root);
    p.second=true;*/
    int lh=1+max(leftAns.first,rightAns.first);
    bool tF;
    if(abs(leftAns.first-rightAns.first)<=1)
    {
        tF= leftAns.second && rightAns.second; 
    }
    else
        tF=false;
   
        
    pair<int,bool> f;
    f.first=lh;
    f.second=tF;
    return f;
}
bool isBalanced(BinaryTreeNode<int> *root) {
	// Write your code here
    
    pair<int,bool> w=balanceAndHieght(root);
    return w.second;
   /* if(root==NULL)
        return true;
    pair<int,bool> p;
    p.first=hieght(root);
    p.second=true;
    pair<int,bool> leftNode=
     isBalanced(root->left);
    isBalanced(root->right);
    int lh=hieght(root->left);
    int rh=hieght(root->right);
   
    if(abs(lh-rh)<=1)
        return true;
    return false;*/
}