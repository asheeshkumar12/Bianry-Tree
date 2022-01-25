
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
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}












/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/
#include<bits/stdc++.h>
void returnVect(BinaryTreeNode<int>* root,vector<int> & vect)
{
    if(root==NULL)
        return;
    vect.push_back(root->data);
    if(root->left!=NULL)
    {
        returnVect(root->left,vect);
    }
    if(root->right!=NULL)
    {
        returnVect(root->right,vect);
    }
}

void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
    if(root==NULL)
        return;
    vector<int> vect;
    returnVect(root,vect);
   
    sort(vect.begin(),vect.end());
    int i=0,j=vect.size()-1;
    while(i<j)
    {
        int nsum=vect[i]+vect[j];
        if(nsum< sum)
        {
            i++;
        }
       else if(nsum >sum)
       {
           j--;
       }
        else
        {
            cout<<vect[i]<<" "<<vect[j]<<endl;
            i++;
            j--;
        }
    }
}
