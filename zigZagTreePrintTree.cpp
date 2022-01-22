




#include<stack>
#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
#include "solution.h"

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    zigZagOrder(root);
}

void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL)
        return;
    stack<BinaryTreeNode<int>*> ms;
    stack<BinaryTreeNode<int>*> cs;
    ms.push(root);
   int  level=1;
    while(ms.size()!=0)
    { 
        int size=ms.size();
        for(int i=0;i<size;i++)
        {
            BinaryTreeNode<int>* f=ms.top();
            ms.pop();
            cout<<f->data<<" ";
            
                 if(level%2==1)
                      {
                         if(f->left!=NULL) 
                             cs.push(f->left);
                         if(f->right!=NULL)
                           cs.push(f->right);
                       }
                 else
                       {
                        if(f->right!=NULL)
                           cs.push(f->right);
                         if(f->left!=NULL)
                              cs.push(f->left);
                        }
             
        }
        if(ms.size()==0)
        {
            ms=cs;
            stack<BinaryTreeNode<int>* > news;
            cs=news;
            level++;
        }
      cout<<"\n";
    }
}
