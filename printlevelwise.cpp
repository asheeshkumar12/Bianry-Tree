
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
/* #include "solution.h"   */

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
    printLevelWise(root);
}



#include<queue>
void printLevelWise(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL)
        return;
    queue<BinaryTreeNode<int>* > q;
    q.push(root);
    while( q.size()!=0)
    {
        int size=q.size();
       for(int i=0;i<size;i++)
       {
           BinaryTreeNode<int>* f=q.front();
           q.pop();
           cout<<f->data<<" ";
           if(f->left!=NULL)
               q.push(f->left);
           if(f->right!=NULL)
               q.push(f->right);
       }
        cout<<"\n";
    
        
        
        
    }
}
